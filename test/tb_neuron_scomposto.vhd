library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use std.textio.all;
use ieee.std_logic_textio.all;

library work;
use work.debug_func.all;
use work.utils.all;
use work.data_types.all;
use work.activation_functions.all;
 
entity tb_neuron_scomposto is
end tb_neuron_scomposto;

architecture behavioral of tb_neuron_scomposto is
  ------------------------------------------------------------------------------
  -- Generics
  constant input_depth    : natural       := 1;
  constant ker_width      : natural       := 5;
  constant ker_height     : natural       := 5;
  constant act_kind       : activation_t  := rectifier;
  constant act_unsigned   : boolean       := true;
  constant shift          : integer       := 2;
  -- Port
  signal   clock          : std_logic := '0';
  signal   reset_n        : std_logic := '0';
  signal   inputs         : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1) := (others => (others => (others => (others => '0'))));
  signal   bias           : std_logic_vector(data_size-1 downto 0) := (others => '0'); 
  signal   weights        : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1) := (others => (others => (others => (others => '0'))));
  signal   outputs        : std_logic_vector(data_size-1 downto 0) := (others => '0');
  ------------------------------------------------------------------------------

  component multiplier is
  	generic (data_size : integer);
  	port (	x			: in std_logic_vector(data_size-1 downto 0);
  					y			: in std_logic_vector(data_size-1 downto 0);
  					prod	: out std_logic_vector ((2*data_size)-1 downto 0));
  end component;
  component generic_register is
  	generic(data_size : natural);
  	port (
  		clk  : in std_logic;
  		rst_n  : in std_logic;
  		data_in : in std_logic_vector (data_size-1 downto 0);
  		en : in std_logic;
  		data_out : out std_logic_vector (data_size-1 downto 0)
  	);
  end component;
  component sum_reduct is
    generic (
      noperands : natural;
      data_size : natural);
    port (
  		clk     : in std_logic;
  		rst_n   : in std_logic;
      inputs  : in std_logic_vector ((noperands * data_size)-1 downto 0);
  		sum     : out std_logic_vector (data_size+log2(noperands)-1 downto 0));
  end component;
  component activation is
    generic (
      kind                : activation_t;
      unsigned_data       : boolean;
      actual_data_size    : natural;
      final_data_size     : natural;
      shift               : integer);
    port (
      data_in   : in std_logic_vector(actual_data_size-1 downto 0);
      data_out  : out std_logic_vector(final_data_size-1 downto 0));
  end component;

  constant num_terms          : natural                                         := input_depth * ker_height * ker_width;  -- total amount of partial product terms (equals the volume size )
  constant num_terms_2        : natural                                         := 2 ** (log2(num_terms+1)+1);            -- next power of two for num_terms (note, it include the bias term now)
  constant internal_data_size : natural                                         := data_size+1;                           -- needed in order to convert inputs to unsigned
  constant pprod_size         : natural                                         := 2*internal_data_size;                  -- data size of partial product terms
  constant sum_size           : natural                                         := pprod_size+log2(num_terms_2);          -- size of the sum (number of bits)
  constant pprod_concat_size  : natural                                         := num_terms_2*pprod_size;                -- size of partial product (concatenated)
  signal   pprod_concat       : std_logic_vector(pprod_concat_size-1 downto 0)  := (others => '0');                       -- concatenation of partial_prod (bias included)
  signal   bias_buffered      : std_logic_vector(data_size-1 downto 0)          := (others => '0');                       -- bias (buffered so it traverses the same amunt of pipe stages)
  signal   sum                : std_logic_vector(sum_size-1 downto 0)           := (others => '0');                       -- sum of the partial product terms (bias included)
  signal   output_unbuff      : std_logic_vector(data_size-1 downto 0)          := (others => '0');                       -- unbuffered output

  type iinputs_t              is array (natural range <>) of std_logic_vector(internal_data_size-1 downto 0);             -- new data type to hold sign-extended weights and unsigned inputs
  type pprod_t                is array (natural range <>) of std_logic_vector(pprod_size-1 downto 0);                     -- new data type to hold partual products

  signal ext_weights          : iinputs_t(num_terms-1 downto 0) := (others => (others => '0'));                           -- sign-extended weights
  signal uns_inputs           : iinputs_t(num_terms-1 downto 0) := (others => (others => '0'));                           -- inputs (unsigned)
  signal pprod_unbuf          : pprod_t(num_terms-1 downto 0) := (others => (others => '0'));                             -- partial products terms as they comes from multipliers
  signal pprod                : pprod_t(num_terms-1 downto 0) := (others => (others => '0'));                             -- partial product terms after the pipe stage  

  ------------------------------------------------------------------------------
  -- Testbench signals
	constant clock_period   : time          := 10 ns;
  constant latency        : natural       := log2(input_depth*ker_height*ker_width)+10;
  file     test_oracle    : text;
	signal   simulate       : std_logic     := '1';
begin
  -- and weights inputs assignment
  w_i_loop_z : for sz in 0 to input_depth-1 generate
    w_i_loop_y: for sy in 0 to ker_height-1 generate
      w_i_loop_x : for sx in 0 to ker_width-1 generate
        ext_weights((input_depth*ker_height*sz)+(ker_height*sy)+sx) <= weights(sz, sy, sx)(data_size-1) & weights(sz, sy, sx);
        uns_inputs((input_depth*ker_height*sz)+(ker_height*sy)+sx) <= '0' & inputs(sz, sy, sx);
      end generate;
    end generate;
  end generate;  

  ------------------------------------------------------------------------------
  -- Neuron implementation
  -- Bias buffering (so it traverses tha same amount of pipe stages)
  bias_buf : generic_register
    generic map (data_size)
    port map(clock, reset_n, bias, '1', bias_buffered);
  -- Synapse   
  -- Partial product computation
  pprod_loop : for i in 0 to num_terms-1 generate
        mul_w_i : multiplier generic map(internal_data_size) port map (ext_weights(i), uns_inputs(i), pprod_unbuf(i));
        buf_pprodd : generic_register generic map(pprod_size) port map(clock, reset_n, pprod_unbuf(i), '1', pprod(i));
  end generate;

  -- Neuron body
  -- Terms concatenation
  pprod_concat(data_size-1 downto 0) <= bias_buffered;
  concat_terms: for i in num_terms-1 downto 0 generate
    pprod_concat(pprod_concat'left-(i*pprod_size) downto pprod_concat'left-((i+1)*pprod_size)+1) <= pprod(i);
  end generate;
  -- Sum reduction
  reduct : sum_reduct
    generic map(num_terms_2, pprod_size)
    port map (clock, reset_n, pprod_concat, sum);
  -- Activation function and saturation
  act : activation
    generic map(act_kind, act_unsigned, sum_size, data_size, shift)
    port map(sum, output_unbuff);
  -- last pipe stage
  output_buf : generic_register
    generic map (data_size)
    port map(clock, reset_n, output_unbuff, '1', outputs);
  ------------------------------------------------------------------------------

	clock_process : process
	begin
		while simulate = '1' loop
			clock <= not clock;
			wait for clock_period / 2;
		end loop;
		wait;
	end process clock_process;

  stim_process : process
    variable rline        : line;
    variable space        : character;
    variable read_bias    : std_logic_vector(data_size-1 downto 0); 
    variable read_weights : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);
    variable read_inputs  : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);
    variable read_outputs : std_logic_vector(data_size-1 downto 0);
    variable line_number  : integer := 0;
  begin
    file_open(test_oracle, "../test/tb_neuron_oracle.txt", read_mode);
		reset_n <= '0', '1' after 5*clock_period;
		wait for 7*clock_period;
    while not endfile(test_oracle) loop
      readline(test_oracle, rline);
      -- reading bias
      read(rline, read_bias); read(rline, space);
      bias <= read_bias;
      -- reading weights
      for sz in 0 to input_depth-1 loop
        for sy in 0 to ker_height-1 loop
          for sx in 0 to ker_width-1 loop
            read(rline, read_weights(sz, sy, sx)); read(rline, space);
            weights(sz, sy, sx) <= read_weights(sz, sy, sx);
          end loop;
        end loop;
      end loop;
      -- reading inputs 
      for sz in 0 to input_depth-1 loop
        for sy in 0 to ker_height-1 loop
          for sx in 0 to ker_width-1 loop
            read(rline, read_inputs(sz, sy, sx)); read(rline, space);
            inputs(sz, sy, sx) <= read_inputs(sz, sy, sx);
          end loop;
        end loop;
      end loop;
      -- reading output
      read(rline, read_outputs);
      -- waiting the computation to complete
      wait for latency *clock_period;
      assert read_outputs = outputs report "Error with input line " & integer'image(line_number) & "! expected: " & vec_image(read_outputs) & " output: " & vec_image(outputs) severity failure; 
      line_number := line_number + 1;
    end loop;
		simulate <= '0';
		wait;
  end process;
end behavioral;
 


library ieee;
use ieee.std_logic_1164.all;

package data_types is
  constant data_size : natural := 8;
  type data_vector is array (natural range<>) of std_logic_vector(data_size-1 downto 0);  
  type data_matrix is array (natural range <>, natural range <>) of std_logic_vector (data_size-1 downto 0);
  type data_volume is array(natural range <>, natural range <>, natural range <>) of std_logic_vector(data_size-1 downto 0);
	type data_hypervolume is array (natural range <>, natural range <>, natural range <>, natural range <>) of std_logic_vector(data_size -1 downto 0);
end package;

library ieee;
use ieee.std_logic_1164.all;

library work;
use work.utils.all;
use work.data_types.all;
use work.activation_functions.all;

entity neuron is
  generic (
    -- Structural properties of convolutional kernel
    input_depth       : natural      := 120;                                                  -- Number of input channels
    ker_width         : natural      := 5;                                                    -- Kernel width
    ker_height        : natural      := 5;                                                    -- Kernel height
    act_kind          : activation_t := rectifier;                                            -- type of activation
    act_unsigned      : boolean      := true;                                                 -- do the activation work on unsigned data?
    shift             : integer      := 2;                                                    -- shift amount for the activation function
    add_approx_degree : natural      := 0;                                                    -- Approximation degree for adders
    mul_approx_degree : natural      := 0);                                                   -- Approximation degree for multipliers
  port (
    clock         : in std_logic;                                                             -- Clock signal
    reset_n       : in std_logic;                                                             -- Reset signal (active low)
    inputs        : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);  -- input volume
    bias          : in std_logic_vector(data_size-1 downto 0);                                -- bias (single term) 
    weights       : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);  -- weights volume
    outputs       : out std_logic_vector(data_size-1 downto 0));                              -- output
end neuron;

architecture structural of neuron is
  component multiplier is
    generic (
      data_size     : natural;
      approx_degree : natural);
    port (
      clock         : in std_logic;
      reset_n       : in std_logic;
      x             : in  std_logic_vector(data_size-1 downto 0);
      y             : in  std_logic_vector(data_size-1 downto 0);
      prod          : out std_logic_vector ((2*data_size)-1 downto 0));
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
      noperands     : natural;
      data_size     : natural;
      approx_degree : natural);
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
begin
  -- and weights inputs assignment
  w_i_loop_z : for sz in 0 to input_depth-1 generate
    w_i_loop_y: for sy in 0 to ker_height-1 generate
      w_i_loop_x : for sx in 0 to ker_width-1 generate
        ext_weights((ker_width*ker_height*sz)+(ker_width*sy)+sx) <= weights(sz, sy, sx)(data_size-1) & weights(sz, sy, sx);
        uns_inputs((ker_width*ker_height*sz)+(ker_width*sy)+sx) <= '0' & inputs(sz, sy, sx);
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
        mul_w_i : multiplier generic map(internal_data_size, mul_approx_degree) port map (clock, reset_n, ext_weights(i), uns_inputs(i), pprod_unbuf(i));
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
    generic map(num_terms_2, pprod_size, add_approx_degree)
    port map (clock, reset_n, pprod_concat, sum);
  -- Activation function and saturation
  act : activation
    generic map(act_kind, act_unsigned, sum_size, data_size, shift)
    port map(sum, output_unbuff);
  -- last pipe stage
  output_buf : generic_register
    generic map (data_size)
    port map(clock, reset_n, output_unbuff, '1', outputs);
end structural;  

library ieee;
use ieee.std_logic_1164.all;

library work;
use work.utils.all;
use work.config.all;
use work.data_types.all;
use work.activation_functions.all;

entity neuron is
  generic (
    data_size      : natural := 16;
    -- Structural properties of convolutional kernel
    nchannels      : natural;       -- Number of input channels
    ker_width      : natural;       -- Kernel width
    ker_height     : natural;       -- Kernel height
    act_kind       : activation_t;  -- type of activation
    shift          : natural);
  port (
    clock         : in std_logic;                                                             -- Clock signal
    reset_n       : in std_logic;                                                             -- Reset signal (active low)
    inputs        : in data_volume(0 to nchannels-1, 0 to ker_height-1, 0 to ker_width-1);    -- input volume
    bias          : in std_logic_vector(data_size-1 downto 0);                                -- bias (single term) 
    weights       : in data_volume(0 to nchannels-1, 0 to ker_height-1, 0 to ker_width-1);    -- weights volume
    outputs       : out std_logic_vector(data_size-1 downto 0)                                -- output
  );
end neuron;

architecture structural of neuron is
  component multiplier is
  	generic (data_size : integer := 8);
  	port (	x			: in std_logic_vector(data_size-1 downto 0);
  					y			: in std_logic_vector(data_size-1 downto 0);
  					prod	: out std_logic_vector ((2*data_size)-1 downto 0));
  end component;
  component generic_register is
  	generic(data_size : natural := 16);
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
      noperands : natural;                                                    -- number of operand to be summed
      data_size : natural);                                                   -- size of each operand
    port (
  		clk     : in std_logic;                                                 -- clock
  		rst_n   : in std_logic;                                                 -- reset (active low)
      inputs  : in std_logic_vector ((noperands * data_size)-1 downto 0);     -- operands (concatenated)
  		sum     : out std_logic_vector (data_size+log2(noperands)-1 downto 0));
  end component;
  component activation is
    generic (
      kind                : activation_t;
      actual_data_size    : natural;
      final_data_size     : natural;
      shift               : natural);
    port (
      data_in   : in std_logic_vector(actual_data_size-1 downto 0);
      data_out  : out std_logic_vector(final_data_size-1 downto 0));
  end component;

  constant num_terms          : natural                                         := nchannels * ker_height * ker_width;  -- total amount of partial product terms (equals the volume size)
  constant num_terms_2        : natural                                         := 2 ** (log2(num_terms+1)+1);          -- next power of two for num_terms (note, it include the bias term now)
  constant pprod_size         : natural                                         := 2*data_size;                         -- data size of partial product terms
  constant sum_size           : natural                                         := log2(num_terms_2)*pprod_size;        -- size of the sum (number of bits)
  constant pprod_concat_size  : natural                                         := num_terms_2*pprod_size;              -- size of partial product (concatenated)
  signal pprod_concat         : std_logic_vector(pprod_concat_size-1 downto 0)  := (others => '0');                     -- concatenation of partial_prod (bias included)
  signal bias_buffered        : std_logic_vector(data_size-1 downto 0)          := (others => '0');                     -- bias (buffered so it traverses the same amunt of pipe stages)
  signal sum                  : std_logic_vector(sum_size-1 downto 0)           := (others => '0');                     -- sum of the partial product terms (bias included)
  signal output_unbuff        : std_logic_vector(data_size-1 downto 0)          := (others => '0');                     -- unbuffered output
  type pprod_t                is array (natural range <>) of std_logic_vector(pprod_size-1 downto 0);                   -- new data type to hold partual products
  signal pprod_unbuf          : pprod_t(num_terms-1 downto 0);                                                          -- partial products terms as they comes from multipliers
  signal pprod                : pprod_t(num_terms-1 downto 0);                                                          -- partial product terms after the pipe stage  
begin

  -- Bias buffering (so it traverses tha same amount of pipe stages)
  bias_buf : generic_register
    generic map (data_size)
    port map(clock, reset_n, bias, '1', bias_buffered);

  -- Synapse   
  -- Partial product computation
  loop_z : for sz in 0 to nchannels-1 generate
    loop_y: for sy in 0 to ker_height-1 generate
      loop_x : for sx in 0 to ker_width-1 generate
         mul : multiplier generic map(data_size) port map (weights(sz, sy, sx), inputs(sz, sy, sx), pprod_unbuf(sz*sx*sy));
         buf : generic_register generic map(2*data_size) port map(clock, reset_n, pprod_unbuf(sz*sx*sy), '1', pprod(sz*sx*sy));
       end generate;
    end generate;
  end generate;

  -- Neuron body
  -- Terms concatenation
  pprod_concat(data_size-1 downto 0) <= bias_buffered;
  concat_terms: for i in 0 to num_terms-1 generate
      pprod_concat(pprod_concat_size-(i*data_size)-1 downto pprod_concat_size-((i+1)*data_size)-1) <= pprod(i);
  end generate;
  -- Sum reduction
  reduct : sum_reduct
    generic map(num_terms_2, pprod_size)
    port map (clock, reset_n, pprod_concat, sum);
  -- Activation function
  act : activation
    generic map(act_kind, sum_size, data_size, shift)
    port map(sum, output_unbuff);
  -- last pipe stage
  output_buf : generic_register
    generic map (data_size)
    port map(clock, reset_n, output_unbuff, '1', outputs);

end structural;  
library ieee;
use ieee.std_logic_1164.all;
entity mac_cell is
  port (x    : in std_logic;
        y    : in std_logic;
        sin  : in std_logic;
        cin  : in std_logic;
        sout : out std_logic;
        cout : out std_logic);
end mac_cell;
architecture structural of mac_cell is
  component full_adder
    port (
      add_1     : in std_logic;
      add_2     : in std_logic;
      carry_in  : in std_logic;
      carry_out : out std_logic;
      sum       : out std_logic);
  end component;
  signal p : std_logic;
begin
  p <= x and y;
  adder : full_adder port map (p, sin, cin, cout, sout);
end structural;


library ieee;
use ieee.std_logic_1164.all;
entity unsigned_multiplier is
  generic (data_size : integer := 8);
  port (
    x     : in  std_logic_vector(data_size-1 downto 0);
    y     : in  std_logic_vector(data_size-1 downto 0);
    prod  : out std_logic_vector ((2*data_size)-1 downto 0));
end unsigned_multiplier;
architecture structural of unsigned_multiplier is
  component mac_cell
    port (
      x    : in std_logic;
      y    : in std_logic;
      sin  : in std_logic;
      cin  : in std_logic;
      sout : out std_logic;
      cout : out std_logic);
  end component;
	type slv_array_t is array(natural range <>) of std_logic_vector(data_size downto 0);
	signal intermediate : slv_array_t(0 to data_size) := (others => (others => '0'));
  signal carry : slv_array_t (0 to data_size) := (others => (others => '0'));

begin
	intermediate(0) <= (intermediate(0)'range => '0');
	row_array :	for i in 0 to data_size-1 generate
    row : for j in 0 to data_size-1 generate
        cell :  mac_cell port map (x(j), y(i), intermediate(i)(j+1), carry(i)(j), intermediate(i+1)(j), carry(i)(j+1));
    end generate;
    intermediate(i+1)(data_size) <= carry(i)(data_size);
		prod(i) <= intermediate(i+1)(0);
	end generate;
	prod((2*data_size)-1 downto data_size-1) <= intermediate(data_size)(data_size downto 0);
end structural;


library ieee;
use ieee.std_logic_1164.all;
entity magnitude_selector is
  generic (data_size : natural);
  port (
    clock         : in std_logic;
    reset_n       : in std_logic;
    sign          : in std_logic;                               -- select the appropriate sign
    data_in       : in std_logic_vector(data_size-1 downto 0);  -- data to be selected
    data_out      : out std_logic_vector(data_size-1 downto 0); -- if sign then -data_in else data_in
    sign_buffered : out std_logic);                             -- sign buffered (for pipelided architectures). can be left open
end magnitude_selector;
architecture structural of magnitude_selector is
  component generic_register is
    generic(data_size : natural := 16);
    port (
      clk      : in  std_logic;
      rst_n    : in  std_logic;
      data_in  : in  std_logic_vector (data_size-1 downto 0);
      en       : in  std_logic;
      data_out : out std_logic_vector (data_size-1 downto 0));
  end component;
  component piped_adder is
  generic (
    data_size     : natural;
    approx_degree : natural);
    port (
      clock     : in   std_logic;
      reset_n   : in   std_logic;
      add_1     : in   std_logic_vector (data_size-1 downto 0);
      add_2     : in   std_logic_vector (data_size-1 downto 0);
      sub_add_n : in   std_logic;
      sum       : out  std_logic_vector (data_size-1 downto 0);
      carry_out : out  std_logic;
      overflow  : out  std_logic);
  end component;
  constant zero_n           : std_logic_vector(data_size-1 downto 0) := (others => '0');
  signal   data_inv         : std_logic_vector(data_size-1 downto 0) := (others => '0');
  signal   inputs           : std_logic_vector(data_size downto 0)   := (others => '0');
  signal   inputs_buffered  : std_logic_vector(data_size downto 0)   := (others => '0');
begin
  inputs <= sign & data_in;
  inv_data_in : piped_adder generic map (data_size, 0) port map (clock, reset_n, zero_n, data_in, '1', data_inv, open, open);
  buf_data_in : generic_register generic map (data_size+1) port map(clock, reset_n, inputs, '1', inputs_buffered);
  sign_buffered <= inputs_buffered(inputs_buffered'left);
  with inputs_buffered(inputs_buffered'left) select
    data_out <= inputs_buffered(data_out'range) when '0',
                data_inv when '1',
                zero_n when others;
end structural;

library ieee;
use ieee.std_logic_1164.all;
entity multiplier is
  generic (data_size : integer := 8);
  port (
    clock         : in std_logic;
    reset_n       : in std_logic;
    x             : in  std_logic_vector(data_size-1 downto 0);
    y             : in  std_logic_vector(data_size-1 downto 0);
    prod          : out std_logic_vector ((2*data_size)-1 downto 0));
end multiplier;
architecture structural of multiplier is
  component magnitude_selector is
    generic (data_size : natural);
    port (
      clock         : in std_logic;
      reset_n       : in std_logic;
      sign          : in std_logic;                               -- select the appropriate sign
      data_in       : in std_logic_vector(data_size-1 downto 0);  -- data to be selected
      data_out      : out std_logic_vector(data_size-1 downto 0); -- if sign then -data_in else data_in
      sign_buffered : out std_logic);                             -- sign buffered (for pipelided architectures). can be left open
  end component;
  component unsigned_multiplier is
  generic (data_size : integer := 8);
    port (
      x     : in  std_logic_vector(data_size-1 downto 0);
      y     : in  std_logic_vector(data_size-1 downto 0);
      prod  : out std_logic_vector ((2*data_size)-1 downto 0));
  end component;
  component generic_register is
    generic(data_size : natural := 16);
    port (
      clk      : in  std_logic;
      rst_n    : in  std_logic;
      data_in  : in  std_logic_vector (data_size-1 downto 0);
      en       : in  std_logic;
      data_out : out std_logic_vector (data_size-1 downto 0));
  end component;
  signal sign_1            : std_logic                                   := '0';
  signal sign_2            : std_logic                                   := '0';
  signal final_sign_unbuff : std_logic_vector(0 downto 0)                := (others => '0');
  signal final_sign_buff   : std_logic_vector(0 downto 0)                := (others => '0');
  signal multiplicand_1    : std_logic_vector(data_size-1 downto 0)      := (others => '0');
  signal multiplicand_2    : std_logic_vector(data_size-1 downto 0)      := (others => '0');
  signal product_unbuff    : std_logic_vector ((2*data_size)-1 downto 0) := (others => '0');
  signal product_buff      : std_logic_vector ((2*data_size)-1 downto 0) := (others => '0');
begin
  -- There are many methods to multiply 2's complement numbers. 
  -- The easiest is to simply find the magnitude of the two multiplicands, 
  -- multiply these together, and then use the original sign bits to determine 
  -- the sign of the result. 
  x_sel : magnitude_selector generic map (data_size) port map(clock, reset_n, x(x'left), x, multiplicand_1, sign_1);
  y_sel : magnitude_selector generic map (data_size) port map(clock, reset_n, y(y'left), y, multiplicand_2, sign_2);
  final_sign_unbuff(0) <= sign_1 xor sign_2;
  -- Computing unsigned multiplication
  mul : unsigned_multiplier
    generic map(data_size)
    port map(multiplicand_1, multiplicand_2, product_unbuff);
  mul_buf : generic_register generic map (2*data_size) port map (clock, reset_n, product_unbuff, '1', product_buff); 
  sig_buf : generic_register generic map (1) port map (clock, reset_n, final_sign_unbuff, '1', final_sign_buff);
  -- If the multiplicands had the same sign, the result must be positive, if 
  -- the they had different signs, the result is negative. 
  -- Computing -product
  prod_sel : magnitude_selector generic map(2*data_size) port map (clock, reset_n, final_sign_buff(0), product_buff, prod, open);
end structural;


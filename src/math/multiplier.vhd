library ieee;
use ieee.std_logic_1164.all;

entity mac_cell is
	port (	x 		: in std_logic;
			y		: in std_logic;
			sin		: in std_logic;
			cin		: in std_logic;
			sout	: out std_logic;
			cout	: out std_logic
	);
end mac_cell;

architecture structural of mac_cell is

	component full_adder
		port (	add_1		: in std_logic;
				add_2		: in std_logic;
				carry_in	: in std_logic;
				carry_out	: out std_logic;
				sum			: out std_logic
		);
	end component;
	
	signal p : std_logic;
	
begin
	p <= x and y;
	adder : full_adder
		port map (
			add_1		=>	p,
			add_2		=>	sin,
			carry_in	=>	cin,
			carry_out	=>	cout,
			sum			=>	sout
		);
end structural;

library ieee;
use ieee.std_logic_1164.all;

entity mac_row is
	generic (nbits : natural := 4);
	port (	x		: in std_logic_vector (nbits-1 downto 0);
			y 		: in std_logic;
			sumin	: in std_logic_vector (nbits-1 downto 0);
			sumout	: out std_logic_vector (nbits-1 downto 0);
			cout	: out std_logic
	);
end mac_row;

architecture structural of mac_row is
	component mac_cell
		port (	x 		: in std_logic;
				y		: in std_logic;
				sin		: in std_logic;
				cin		: in std_logic;
				sout	: out std_logic;
				cout	: out std_logic
		);
	end component;
	
	signal carry : std_logic_vector (nbits downto 0) := (others => '0');
	
begin

	row :	for i in 0 to nbits-1 generate
			cell :	mac_cell 
				port map (
					x		=>	x(i),
					y		=>	y,
					sin		=>	sumin(i),
					cin		=>	carry(i),
					sout	=>	sumout(i),
					cout	=>	carry(i+1)
				);
		end generate;
	
	carry(0) <= '0';
	cout <= carry(nbits);
	
end structural;

library ieee;
use ieee.std_logic_1164.all;

entity multiplier is
	generic (nbits : integer := 8);
	port (	x			: in std_logic_vector(nbits-1 downto 0);
					y			: in std_logic_vector(nbits-1 downto 0);
					prod	: out std_logic_vector ((2*nbits)-1 downto 0)
	);
end multiplier;

architecture structural of multiplier is

component mac_row
	generic (nbits  : natural := 4);
	port (	
		x		   : in std_logic_vector (nbits-1 downto 0);
    y 		 : in std_logic;
    sumin	 : in std_logic_vector (nbits-1 downto 0);
    sumout : out std_logic_vector (nbits-1 downto 0);
    cout	 : out std_logic
	);
end component;

component adder is
	generic (nbits : natural := 16);
  port (
		add_1 		: in   std_logic_vector (nbits-1 downto 0);
		add_2 		: in   std_logic_vector (nbits-1 downto 0);
		sub_add_n	: in   std_logic;
		sum 		  : out  std_logic_vector (nbits-1 downto 0);
		carry_out	: out  std_logic;
		overflow 	: out  std_logic);
end component;

type sgn_mtx is array(0 to nbits) of std_logic_vector(nbits downto 0);
signal intermediate : sgn_mtx;

constant zero_n : std_logic_vector(nbits-1 downto 0) := (others => '0');
constant zero_2n : std_logic_vector((2*nbits)-1 downto 0) := (others => '0');
signal x_inv : std_logic_vector(nbits-1 downto 0);
signal y_inv : std_logic_vector(nbits-1 downto 0);
signal multiplicand_1 : std_logic_vector(nbits-1 downto 0);
signal multiplicand_2 : std_logic_vector(nbits-1 downto 0);
signal product : std_logic_vector ((2*nbits)-1 downto 0);
signal product_inv : std_logic_vector ((2*nbits)-1 downto 0);

begin
  -- There are many methods to multiply 2's complement numbers. 
  -- The easiest is to simply find the magnitude of the two multiplicands, 
  -- multiply these together, and then use the original sign bits to determine 
  -- the sign of the result. 
  --
  -- Multiplication by zero is a special case (the result is always zero, 
  -- with no sign bit).

	-- Computing -x
	sign_inv_x : adder generic map (nbits) port map (zero_n, x, '1', x_inv, open, open);
	-- Selecting +x/-x
	with x(nbits-1) select multiplicand_1 <= x when '0', x_inv when others;

  -- Computing -y
	sign_inv_y : adder generic map (nbits) port map (zero_n, y, '1', y_inv, open, open);
 	-- Selecting +y/-y
	with y(nbits-1) select multiplicand_2 <= y when '0', y_inv when others;

	-- Computing unsigned multiplication
	intermediate(0) <= (intermediate(0)'range => '0');	
	row_array :	for i in 0 to nbits-1 generate
		row : mac_row
				generic map (nbits => nbits)
				port map (
					x 		=>	 multiplicand_1,
					y 		=>	 multiplicand_2(i),
					sumin 	=>	 intermediate(i)(nbits downto 1),
					sumout 	=>	 intermediate(i+1)(nbits-1 downto 0),
					cout 	=>	 intermediate(i+1)(nbits)
				);
		product(i) <= intermediate(i+1)(0);
	end generate;

	product((2*nbits)-1 downto nbits-1) <= intermediate(nbits)(nbits downto 0);

  -- If the multiplicands had the same sign, the result must be positive, if 
  -- the they had different signs, the result is negative. 
	-- Computing -product
	sign_inv_product : adder generic map(2*nbits) port map (zero_2n, product, '1', product_inv, open, open);
	-- Selecting -product/+produce
	with y(nbits-1) xor x(nbits-1) select prod <= product when '0', product_inv when others;

end structural;

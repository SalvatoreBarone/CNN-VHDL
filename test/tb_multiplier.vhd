library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library work;
use work.debug_func.all;

entity tb_multiplier is
end tb_multiplier;

architecture behavior of tb_multiplier is
	component multiplier
    generic (data_size : integer := 8);
    port (
      clock         : in std_logic;
      reset_n       : in std_logic;
      x             : in  std_logic_vector(data_size-1 downto 0);
      y             : in  std_logic_vector(data_size-1 downto 0);
      prod          : out std_logic_vector ((2*data_size)-1 downto 0));
	end component;
  constant data_size : natural := 8;
  signal   clock     : std_logic := '0';
  signal   reset_n   : std_logic := '0';
  signal   x         : std_logic_vector(data_size-1 downto 0) := (others => '0');
  signal   y         : std_logic_vector(data_size-1 downto 0) := (others => '0');
  signal   prod      : std_logic_vector ((2*data_size)-1 downto 0) := (others => '0');

	-- Clock period definitions
  constant latency : natural := 4;
	constant clock_period : time := 10 ns;
	signal simulate : std_logic := '1';
 
BEGIN
	uut: multiplier generic map (data_size)	port map (clock, reset_n, x, y, prod);

	clock_process : process
	begin
		while simulate = '1' loop
			clock <= not clock;
			wait for clock_period / 2;
		end loop;
		wait;
	end process clock_process;

	stim_proc: process
		variable test_prod : integer := 0;
    variable test_prod_stdlv : std_logic_vector(2*data_size-1 downto 0);
	begin
		reset_n <= '0', '1' after 3*clock_period;
		wait for 5*clock_period;
		for i in -2**(data_size-1) to 2**(data_size-1)-1 loop
			x <= std_logic_vector(to_signed(i, data_size));
			for j in -2**(data_size-1) to 2**(data_size-1)-1 loop
				y <= std_logic_vector(to_signed(j,data_size));
				test_prod := i * j;
				test_prod_stdlv := std_logic_vector(to_signed(test_prod, 2*data_size));
				wait for (latency+1)*clock_period;
				assert prod = test_prod_stdlv report "Errore x: " & vec_image(x) & " y:" & vec_image(y) & " prod:" & vec_image(prod) & " test_prod:" & vec_image(test_prod_stdlv)	severity failure;
			end loop;
		end loop;
		simulate <= '0';
		wait;
	end process;
end behavior;

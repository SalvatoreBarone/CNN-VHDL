library ieee;
use ieee.std_logic_1164.all;

entity sipo_register is
	generic (data_size : natural := 8);
	port (
		clock			    : in std_logic;
		reset_n 		  : in std_logic;
		shift			    : in std_logic;
		serial_in 		: in std_logic; -- lsb first
		parallel_out 	: out std_logic_vector(data_size-1 downto 0));
end sipo_register;

architecture behavioral of sipo_register is
	signal data : std_logic_vector(data_size-1 downto 0);
begin
	parallel_out <= data;
	process(clock, reset_n, shift)
	begin
		if reset_n = '0' then
			data <= (others => '0');
		elsif rising_edge(clock) and shift = '1' then
				data <= serial_in & data(data_size-1 downto 1);
		end if;
	end process;
end behavioral;


library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity generic_register is
	generic(
		N : natural := 16
	);
	port (
		clk  : in std_logic;
		rst  : in std_logic;
		data_in : in std_logic_vector (N-1 downto 0);
		en : in std_logic;
		data_out : out std_logic_vector (N-1 downto 0)
	);
end generic_register;

architecture generic_register of generic_register is
    signal tmp : std_logic_vector(N-1 downto 0) := (others => '0');
begin

    data_out <= tmp;
	process(clk, rst, data_in, en)
    begin
        if rst = '0' then
            tmp <= (others => '0');
        elsif rising_edge(clk) then
            if en = '1' then
                tmp <= data_in;
            end if;
        end if;
    end process;

end architecture;


-- Copyright 2020	Salvatore Barone <salvatore.barone@unina.it>
-- 
-- This file is part of CNN-VHDL
-- 
-- This is free software; you can redistribute it and/or modify it under
-- the terms of the GNU General Public License as published by the Free
-- Software Foundation; either version 3 of the License, or any later version.
-- 
-- This is distributed in the hope that it will be useful, but WITHOUT
-- ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
-- FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
-- more details.
-- 
-- You should have received a copy of the GNU General Public License along with
-- RMEncoder; if not, write to the Free Software Foundation, Inc., 51 Franklin
-- Street, Fifth Floor, Boston, MA 02110-1301, USA.

library ieee;
use ieee.std_logic_1164.all;

entity piso_register is
	generic (data_size : natural := 8);
	port (
		clock			    : in std_logic;
		reset_n 		  : in std_logic;
		load       		: in std_logic;
		parallel_in 	: in std_logic_vector(data_size-1 downto 0);
		shift			    : in std_logic;
		serial_out 		: out std_logic); -- lsb first
end piso_register;


architecture behavioral of piso_register is
	signal data : std_logic_vector(data_size-1 downto 0);
begin
	serial_out <= data(0);
	process(clock, reset_n, load, shift, parallel_in)
	begin
		if (reset_n = '0') then
			data <= (others => '0');
		elsif rising_edge(clock) then
			if (load = '1') then
				data <= parallel_in;
			elsif (shift = '1') then
				data <= '0' & data(data_size-1 downto 1);
			end if;
		end if;
	end process;
end behavioral;


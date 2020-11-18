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


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

package data_types is
  constant data_size : natural := 8;
  type data_vector is array (natural range<>) of std_logic_vector(data_size-1 downto 0);  
  type data_matrix is array (natural range <>, natural range <>) of std_logic_vector (data_size-1 downto 0);
  type data_volume is array(natural range <>, natural range <>, natural range <>) of std_logic_vector(data_size-1 downto 0);
	type data_hypervolume is array (natural range <>, natural range <>, natural range <>, natural range <>) of std_logic_vector(data_size -1 downto 0);
end package;


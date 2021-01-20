-- Copyright 2020-2021 Salvatore Barone <salvatore.barone@unina.it>
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

entity full_adder is
  port (
    add_1     : in std_logic;
    add_2     : in std_logic;
    carry_in  : in std_logic;
    carry_out : out std_logic;
    sum       : out std_logic);
end full_adder;

architecture data_flow of full_adder is
begin
  carry_out <= (add_1 and add_2 ) or (carry_in and add_1) or (carry_in and add_2);
  sum <= add_1 xor add_2 xor carry_in;
end data_flow;

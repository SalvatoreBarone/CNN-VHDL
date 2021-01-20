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

entity wired_shift is
  generic (
    data_size : natural;
    shift     : integer);
  port (
    data_in   : in std_logic_vector(data_size-1 downto 0);
    data_out  : out std_logic_vector(data_size-1 downto 0));
end entity;

architecture data_flow of wired_shift is
begin
  -- if shift > 0 then sum >>= shift
  right_shift : if shift > 0 generate
    data_out(data_out'left downto data_out'left-shift+1) <= (others => data_in(data_in'left)); -- sign preservation
    data_out(data_out'left-shift downto 0) <= data_in(data_in'left downto shift);
  end generate;

  -- if shift < 0 sum <<= -shift
  left_shift : if shift < 0 generate
    data_out(-shift-1 downto 0) <= (others => '0');
    data_out(data_out'left downto -shift) <= data_in(data_in'left+shift downto 0);    
  end generate;

  -- no shift 
  no_shift : if shift = 0 generate
    data_out <= data_in;
  end generate;
end data_flow;

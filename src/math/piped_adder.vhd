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

entity piped_adder is
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
end piped_adder;

architecture structural of piped_adder is
  component adder is
    generic (
      data_size     : natural;
      approx_degree : natural);
    port (
      add_1     : in   std_logic_vector (data_size-1 downto 0);
      add_2     : in   std_logic_vector (data_size-1 downto 0);
      sub_add_n : in   std_logic;
      sum       : out  std_logic_vector (data_size-1 downto 0);
      carry_out : out  std_logic;
      overflow  : out  std_logic);
  end component ;
  component generic_register is
	  generic(data_size : natural);
	  port (
	    clk      : in  std_logic;
	    rst_n    : in  std_logic;
	    data_in  : in  std_logic_vector (data_size-1 downto 0);
	    en       : in  std_logic;
	    data_out : out std_logic_vector (data_size-1 downto 0));
  end component;
  signal adder_outs_unbuff  : std_logic_vector(data_size+1 downto 0) := (others => '0');
  signal adder_outs_buff    : std_logic_vector(data_size+1 downto 0) := (others => '0');
begin
  add : adder
    generic map(data_size, approx_degree) 
    port map (add_1, add_2, sub_add_n, adder_outs_unbuff(sum'range), adder_outs_unbuff(data_size), adder_outs_unbuff(data_size+1));
  buff: generic_register 
    generic map (data_size+2) 
    port map (clock, reset_n, adder_outs_unbuff, '1', adder_outs_buff);
  sum <= adder_outs_buff(sum'range);
  carry_out <= adder_outs_buff(data_size);
  overflow <= adder_outs_buff(data_size+1);
end structural;

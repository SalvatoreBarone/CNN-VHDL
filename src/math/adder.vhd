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

entity ripple_carry is
  generic (
    data_size     : natural;
    approx_degree : natural);
  port ( 
    add_1         : in  std_logic_vector (data_size-1 downto 0);
    add_2         : in  std_logic_vector (data_size-1 downto 0);
    carry_in      : in  std_logic;
    carry_out     : out std_logic;
    sum           : out std_logic_vector (data_size-1 downto 0));
end ripple_carry;
architecture structural of ripple_carry is
  component full_adder 
    port ( 
      add_1     : in  std_logic;
      add_2     : in  std_logic;
      carry_in  : in  std_logic;
      carry_out : out std_logic;
      sum       : out std_logic);
  end component full_adder;
  signal tmp_carry : std_logic_vector (data_size downto 0) := (others => '0');
  signal tmp_sum : std_logic_vector (data_size-1 downto 0) := (others => '0');
begin
  tmp_carry(0) <= carry_in;
  sum <= tmp_sum;
  carry_out <= tmp_carry(data_size);
  full_adder_waterfall : for i in data_size-1 downto approx_degree generate
    full_adder_inst : full_adder
      port map(add_1(i), add_2(i), tmp_carry(i), tmp_carry(i+1), tmp_sum(i));    
  end generate;
end structural;

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity adder is
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
end adder;
architecture structural of adder is
  component ripple_carry is
    generic (
      data_size     : natural;
      approx_degree : natural);
    port ( 
      add_1     : in  std_logic_vector (data_size-1 downto 0);
      add_2     : in  std_logic_vector (data_size-1 downto 0);
      carry_in  : in  std_logic;
      carry_out : out std_logic;
      sum       : out std_logic_vector (data_size-1 downto 0));
  end component;
  -- segnali di uscita dall'invertitore xor
  signal xorinv_out : std_logic_vector (data_size-1 downto 0);
  signal carry   : std_logic;
  signal sum_tmp  : std_logic_vector (data_size-1 downto 0);
begin
  with sub_add_n select
  xorinv_out <= add_2 when '0', (not add_2) when others;
  g_adder : ripple_carry
    generic map (data_size, approx_degree)
    port map (add_1, xorinv_out, sub_add_n, carry, sum_tmp);
  sum       <= sum_tmp;
  carry_out <= carry;
  overflow  <= (not add_1(data_size-1) and not add_2(data_size-1) and sum_tmp(data_size-1) and not carry) or (add_1(data_size-1) and add_2(data_size-1) and not sum_tmp(data_size-1) and carry);
end structural;


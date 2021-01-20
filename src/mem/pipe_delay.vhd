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

entity pipe_delay is
  generic (
    data_size : natural;
    stages    : natural);
  port (
    clock     : in  std_logic;
    reset_n   : in  std_logic;
    data_in   : in  std_logic_vector(data_size-1 downto 0);
    data_out  : out std_logic_vector(data_size-1 downto 0));
end entity;

architecture structural of pipe_delay is
  component generic_register is
    generic(data_size : natural);
    port (
      clk      : in  std_logic;
      rst_n    : in  std_logic;
      data_in  : in  std_logic_vector (data_size-1 downto 0);
      en       : in  std_logic;
      data_out : out std_logic_vector (data_size-1 downto 0));
  end component;

  type slv_array_t is array (natural range <>) of std_logic_vector(data_in'range);
  signal data_tmp : slv_array_t (0 to stages) := (others => (others => '0'));

begin
  data_tmp(0) <= data_in;
  data_out <= data_tmp(stages);
  pipe_stages : for i in 1 to stages generate
    stage : generic_register
      generic map(data_size)
      port map (clock, reset_n, data_tmp(i-1), '1', data_tmp(i));
    end generate;
end structural;

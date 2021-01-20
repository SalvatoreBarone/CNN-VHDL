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
use ieee.numeric_std.all;
use std.textio.all;
use ieee.std_logic_textio.all;

library work;
use work.debug_func.all;

entity tb_approx_multiplier is
end tb_approx_multiplier;

architecture behavior of tb_approx_multiplier is
	component multiplier
    generic (
      data_size     : natural;
      approx_degree : natural);
    port (
      clock         : in std_logic;
      reset_n       : in std_logic;
      x             : in  std_logic_vector(data_size-1 downto 0);
      y             : in  std_logic_vector(data_size-1 downto 0);
      prod          : out std_logic_vector ((2*data_size)-1 downto 0));
	end component;
  constant data_size : natural := 8;
  signal   clock     : std_logic := '0';
  signal   reset_n   : std_logic := '0';
  signal   x         : std_logic_vector(data_size-1 downto 0) := (others => '0');
  signal   y         : std_logic_vector(data_size-1 downto 0) := (others => '0');
  
  type     slv_array_t is array (natural range <>) of std_logic_vector (2*data_size-1 downto 0);
  signal   prod      : slv_array_t(0 to data_size-2) := (others => (others => '0'));

	-- Clock period definitions
  constant latency : natural := 4;
	constant clock_period : time := 10 ns;
	signal simulate : std_logic := '1';

  file     test_oracle                          : text;
 
begin
  uuts : for i in 0 to data_size-2 generate 
	  uut: multiplier generic map (data_size, i)	port map (clock, reset_n, x, y, prod(i));
  end generate;

	clock_process : process
	begin
		while simulate = '1' loop
			clock <= not clock;
			wait for clock_period / 2;
		end loop;
		wait;
	end process clock_process;

	stim_proc: process
    variable rline          : line;
    variable space          : character;
    variable read_x         : std_logic_vector (data_size-1 downto 0);
    variable read_y         : std_logic_vector (data_size-1 downto 0);
    variable read_prod      : slv_array_t(0 to data_size-2) := (others => (others => '0'));

	begin
		reset_n <= '0', '1' after 3*clock_period;
		wait for 5*clock_period;
    file_open(test_oracle, "../test/tb_approx_multiplier_oracle.txt", read_mode);
    while not endfile(test_oracle) loop
      readline(test_oracle, rline);
      read(rline, read_x);
      read(rline, space);
      read(rline, read_y);
      x <= read_x;
      y <= read_y;
			wait for (latency+1)*clock_period;
      for i in 0 to data_size-2 loop
        read(rline, space);
        read(rline, read_prod(i));
        assert prod(i) = read_prod(i) report "Error! apprx.degree=" & integer'image(i) & ": x=" & vec_image(x) & " y=" & vec_image(y) & " prod=" & vec_image(prod(i)) & " expected=" & vec_image(read_prod(i)) severity failure;
      end loop;
    end loop;
		simulate <= '0';
		wait;
	end process;
end behavior;

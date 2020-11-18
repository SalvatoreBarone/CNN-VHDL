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
use std.textio.all;
use ieee.std_logic_textio.all;

library work;
use work.debug_func.all;
use work.activation_functions.all;
 
entity tb_activation is
end tb_activation;

architecture behavioral of tb_activation is
  component activation is
    generic (
      kind                : activation_t;                             -- Activation kind
      unsigned_data       : boolean;                                  -- Does the activation work on unsigned data? note. this is meaningfull only for rectifier
      actual_data_size    : natural;                                  -- actual data size (input)
      final_data_size     : natural;                                  -- final data size (output). note actual_data_size >= final_data_size
      shift               : integer);
    port (
      data_in   : in std_logic_vector(actual_data_size-1 downto 0);   -- inputs
      data_out  : out std_logic_vector(final_data_size-1 downto 0));  -- outputs
  end component;

  constant actual_data_size    : natural := 16;
  constant final_data_size     : natural := 8;

  signal   data_in             : std_logic_vector(actual_data_size-1 downto 0);
  
  signal   data_out_linear_m7  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_m6  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_m5  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_m4  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_m3  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_m2  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_m1  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_00  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_p1  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_p2  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_p3  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_p4  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_p5  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_p6  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_linear_p7  : std_logic_vector(final_data_size-1 downto 0);

  signal   data_out_rect_u_m7  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_m6  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_m5  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_m4  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_m3  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_m2  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_m1  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_00  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_p1  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_p2  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_p3  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_p4  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_p5  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_p6  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_u_p7  : std_logic_vector(final_data_size-1 downto 0);

  signal   data_out_rect_s_m7  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_m6  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_m5  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_m4  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_m3  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_m2  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_m1  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_00  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_p1  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_p2  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_p3  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_p4  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_p5  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_p6  : std_logic_vector(final_data_size-1 downto 0);
  signal   data_out_rect_s_p7  : std_logic_vector(final_data_size-1 downto 0);

  file     test_oracle         : text;

begin

  uut_linear_m7 : activation generic map (linear, false, actual_data_size, final_data_size, -7) port map(data_in, data_out_linear_m7);
  uut_linear_m6 : activation generic map (linear, false, actual_data_size, final_data_size, -6) port map(data_in, data_out_linear_m6);
  uut_linear_m5 : activation generic map (linear, false, actual_data_size, final_data_size, -5) port map(data_in, data_out_linear_m5);
  uut_linear_m4 : activation generic map (linear, false, actual_data_size, final_data_size, -4) port map(data_in, data_out_linear_m4);
  uut_linear_m3 : activation generic map (linear, false, actual_data_size, final_data_size, -3) port map(data_in, data_out_linear_m3);
  uut_linear_m2 : activation generic map (linear, false, actual_data_size, final_data_size, -2) port map(data_in, data_out_linear_m2);
  uut_linear_m1 : activation generic map (linear, false, actual_data_size, final_data_size, -1) port map(data_in, data_out_linear_m1);
  uut_linear_00 : activation generic map (linear, false, actual_data_size, final_data_size,  0) port map(data_in, data_out_linear_00);
  uut_linear_p1 : activation generic map (linear, false, actual_data_size, final_data_size, +1) port map(data_in, data_out_linear_p1);
  uut_linear_p2 : activation generic map (linear, false, actual_data_size, final_data_size, +2) port map(data_in, data_out_linear_p2);
  uut_linear_p3 : activation generic map (linear, false, actual_data_size, final_data_size, +3) port map(data_in, data_out_linear_p3);
  uut_linear_p4 : activation generic map (linear, false, actual_data_size, final_data_size, +4) port map(data_in, data_out_linear_p4);
  uut_linear_p5 : activation generic map (linear, false, actual_data_size, final_data_size, +5) port map(data_in, data_out_linear_p5);
  uut_linear_p6 : activation generic map (linear, false, actual_data_size, final_data_size, +6) port map(data_in, data_out_linear_p6);
  uut_linear_p7 : activation generic map (linear, false, actual_data_size, final_data_size, +7) port map(data_in, data_out_linear_p7);

  uut_rect_u_m7 : activation generic map (rectifier, true, actual_data_size, final_data_size, -7) port map(data_in, data_out_rect_u_m7);
  uut_rect_u_m6 : activation generic map (rectifier, true, actual_data_size, final_data_size, -6) port map(data_in, data_out_rect_u_m6);
  uut_rect_u_m5 : activation generic map (rectifier, true, actual_data_size, final_data_size, -5) port map(data_in, data_out_rect_u_m5);
  uut_rect_u_m4 : activation generic map (rectifier, true, actual_data_size, final_data_size, -4) port map(data_in, data_out_rect_u_m4);
  uut_rect_u_m3 : activation generic map (rectifier, true, actual_data_size, final_data_size, -3) port map(data_in, data_out_rect_u_m3);
  uut_rect_u_m2 : activation generic map (rectifier, true, actual_data_size, final_data_size, -2) port map(data_in, data_out_rect_u_m2);
  uut_rect_u_m1 : activation generic map (rectifier, true, actual_data_size, final_data_size, -1) port map(data_in, data_out_rect_u_m1);
  uut_rect_u_00 : activation generic map (rectifier, true, actual_data_size, final_data_size,  0) port map(data_in, data_out_rect_u_00);
  uut_rect_u_p1 : activation generic map (rectifier, true, actual_data_size, final_data_size, +1) port map(data_in, data_out_rect_u_p1);
  uut_rect_u_p2 : activation generic map (rectifier, true, actual_data_size, final_data_size, +2) port map(data_in, data_out_rect_u_p2);
  uut_rect_u_p3 : activation generic map (rectifier, true, actual_data_size, final_data_size, +3) port map(data_in, data_out_rect_u_p3);
  uut_rect_u_p4 : activation generic map (rectifier, true, actual_data_size, final_data_size, +4) port map(data_in, data_out_rect_u_p4);
  uut_rect_u_p5 : activation generic map (rectifier, true, actual_data_size, final_data_size, +5) port map(data_in, data_out_rect_u_p5);
  uut_rect_u_p6 : activation generic map (rectifier, true, actual_data_size, final_data_size, +6) port map(data_in, data_out_rect_u_p6);
  uut_rect_u_p7 : activation generic map (rectifier, true, actual_data_size, final_data_size, +7) port map(data_in, data_out_rect_u_p7);

  uut_rect_s_m7 : activation generic map (rectifier, false, actual_data_size, final_data_size, -7) port map(data_in, data_out_rect_s_m7);
  uut_rect_s_m6 : activation generic map (rectifier, false, actual_data_size, final_data_size, -6) port map(data_in, data_out_rect_s_m6);
  uut_rect_s_m5 : activation generic map (rectifier, false, actual_data_size, final_data_size, -5) port map(data_in, data_out_rect_s_m5);
  uut_rect_s_m4 : activation generic map (rectifier, false, actual_data_size, final_data_size, -4) port map(data_in, data_out_rect_s_m4);
  uut_rect_s_m3 : activation generic map (rectifier, false, actual_data_size, final_data_size, -3) port map(data_in, data_out_rect_s_m3);
  uut_rect_s_m2 : activation generic map (rectifier, false, actual_data_size, final_data_size, -2) port map(data_in, data_out_rect_s_m2);
  uut_rect_s_m1 : activation generic map (rectifier, false, actual_data_size, final_data_size, -1) port map(data_in, data_out_rect_s_m1);
  uut_rect_s_00 : activation generic map (rectifier, false, actual_data_size, final_data_size,  0) port map(data_in, data_out_rect_s_00);
  uut_rect_s_p1 : activation generic map (rectifier, false, actual_data_size, final_data_size, +1) port map(data_in, data_out_rect_s_p1);
  uut_rect_s_p2 : activation generic map (rectifier, false, actual_data_size, final_data_size, +2) port map(data_in, data_out_rect_s_p2);
  uut_rect_s_p3 : activation generic map (rectifier, false, actual_data_size, final_data_size, +3) port map(data_in, data_out_rect_s_p3);
  uut_rect_s_p4 : activation generic map (rectifier, false, actual_data_size, final_data_size, +4) port map(data_in, data_out_rect_s_p4);
  uut_rect_s_p5 : activation generic map (rectifier, false, actual_data_size, final_data_size, +5) port map(data_in, data_out_rect_s_p5);
  uut_rect_s_p6 : activation generic map (rectifier, false, actual_data_size, final_data_size, +6) port map(data_in, data_out_rect_s_p6);
  uut_rect_s_p7 : activation generic map (rectifier, false, actual_data_size, final_data_size, +7) port map(data_in, data_out_rect_s_p7);

  stim_process : process
    variable rline                    : line;
    variable space                    : character;
    variable read_data_in             : std_logic_vector(actual_data_size-1 downto 0);
    variable read_data_out_linear_m7  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_m6  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_m5  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_m4  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_m3  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_m2  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_m1  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_00  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_p1  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_p2  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_p3  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_p4  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_p5  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_p6  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_linear_p7  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_m7  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_m6  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_m5  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_m4  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_m3  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_m2  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_m1  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_00  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_p1  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_p2  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_p3  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_p4  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_p5  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_p6  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_u_p7  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_m7  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_m6  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_m5  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_m4  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_m3  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_m2  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_m1  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_00  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_p1  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_p2  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_p3  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_p4  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_p5  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_p6  : std_logic_vector(final_data_size-1 downto 0);
    variable read_data_out_rect_s_p7  : std_logic_vector(final_data_size-1 downto 0);
  begin
    file_open(test_oracle, "../test/tb_activation_oracle.txt", read_mode);
    while not endfile(test_oracle) loop
      readline(test_oracle, rline);
      read(rline, read_data_in);            read(rline, space);
      read(rline, read_data_out_linear_m7); read(rline, space);
      read(rline, read_data_out_linear_m6); read(rline, space);
      read(rline, read_data_out_linear_m5); read(rline, space);
      read(rline, read_data_out_linear_m4); read(rline, space);
      read(rline, read_data_out_linear_m3); read(rline, space);
      read(rline, read_data_out_linear_m2); read(rline, space);
      read(rline, read_data_out_linear_m1); read(rline, space);
      read(rline, read_data_out_linear_00); read(rline, space);
      read(rline, read_data_out_linear_p1); read(rline, space);
      read(rline, read_data_out_linear_p2); read(rline, space);
      read(rline, read_data_out_linear_p3); read(rline, space);
      read(rline, read_data_out_linear_p4); read(rline, space);
      read(rline, read_data_out_linear_p5); read(rline, space);
      read(rline, read_data_out_linear_p6); read(rline, space);
      read(rline, read_data_out_linear_p7); read(rline, space);
      read(rline, read_data_out_rect_u_m7); read(rline, space);
      read(rline, read_data_out_rect_u_m6); read(rline, space);
      read(rline, read_data_out_rect_u_m5); read(rline, space);
      read(rline, read_data_out_rect_u_m4); read(rline, space);
      read(rline, read_data_out_rect_u_m3); read(rline, space);
      read(rline, read_data_out_rect_u_m2); read(rline, space);
      read(rline, read_data_out_rect_u_m1); read(rline, space);
      read(rline, read_data_out_rect_u_00); read(rline, space);
      read(rline, read_data_out_rect_u_p1); read(rline, space);
      read(rline, read_data_out_rect_u_p2); read(rline, space);
      read(rline, read_data_out_rect_u_p3); read(rline, space);
      read(rline, read_data_out_rect_u_p4); read(rline, space);
      read(rline, read_data_out_rect_u_p5); read(rline, space);
      read(rline, read_data_out_rect_u_p6); read(rline, space);
      read(rline, read_data_out_rect_u_p7); read(rline, space);
      read(rline, read_data_out_rect_s_m7); read(rline, space);
      read(rline, read_data_out_rect_s_m6); read(rline, space);
      read(rline, read_data_out_rect_s_m5); read(rline, space);
      read(rline, read_data_out_rect_s_m4); read(rline, space);
      read(rline, read_data_out_rect_s_m3); read(rline, space);
      read(rline, read_data_out_rect_s_m2); read(rline, space);
      read(rline, read_data_out_rect_s_m1); read(rline, space);
      read(rline, read_data_out_rect_s_00); read(rline, space);
      read(rline, read_data_out_rect_s_p1); read(rline, space);
      read(rline, read_data_out_rect_s_p2); read(rline, space);
      read(rline, read_data_out_rect_s_p3); read(rline, space);
      read(rline, read_data_out_rect_s_p4); read(rline, space);
      read(rline, read_data_out_rect_s_p5); read(rline, space);
      read(rline, read_data_out_rect_s_p6); read(rline, space);
      read(rline, read_data_out_rect_s_p7); 

      data_in <= read_data_in;
      wait for 5 ns;

      assert read_data_out_linear_m7 = data_out_linear_m7 report "Error! function:linear, shift:m7, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_m7) & ", expected:" & vec_image(read_data_out_linear_m7) severity failure;
      assert read_data_out_linear_m6 = data_out_linear_m6 report "Error! function:linear, shift:m6, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_m6) & ", expected:" & vec_image(read_data_out_linear_m6) severity failure;
      assert read_data_out_linear_m5 = data_out_linear_m5 report "Error! function:linear, shift:m5, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_m5) & ", expected:" & vec_image(read_data_out_linear_m5) severity failure;
      assert read_data_out_linear_m4 = data_out_linear_m4 report "Error! function:linear, shift:m4, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_m4) & ", expected:" & vec_image(read_data_out_linear_m4) severity failure;
      assert read_data_out_linear_m3 = data_out_linear_m3 report "Error! function:linear, shift:m3, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_m3) & ", expected:" & vec_image(read_data_out_linear_m3) severity failure;
      assert read_data_out_linear_m2 = data_out_linear_m2 report "Error! function:linear, shift:m2, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_m2) & ", expected:" & vec_image(read_data_out_linear_m2) severity failure;
      assert read_data_out_linear_m1 = data_out_linear_m1 report "Error! function:linear, shift:m1, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_m1) & ", expected:" & vec_image(read_data_out_linear_m1) severity failure;
      assert read_data_out_linear_00 = data_out_linear_00 report "Error! function:linear, shift:00, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_00) & ", expected:" & vec_image(read_data_out_linear_00) severity failure;
      assert read_data_out_linear_p1 = data_out_linear_p1 report "Error! function:linear, shift:p1, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_p1) & ", expected:" & vec_image(read_data_out_linear_p1) severity failure;
      assert read_data_out_linear_p2 = data_out_linear_p2 report "Error! function:linear, shift:p2, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_p2) & ", expected:" & vec_image(read_data_out_linear_p2) severity failure;
      assert read_data_out_linear_p3 = data_out_linear_p3 report "Error! function:linear, shift:p3, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_p3) & ", expected:" & vec_image(read_data_out_linear_p3) severity failure;
      assert read_data_out_linear_p4 = data_out_linear_p4 report "Error! function:linear, shift:p4, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_p4) & ", expected:" & vec_image(read_data_out_linear_p4) severity failure;
      assert read_data_out_linear_p5 = data_out_linear_p5 report "Error! function:linear, shift:p5, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_p5) & ", expected:" & vec_image(read_data_out_linear_p5) severity failure;
      assert read_data_out_linear_p6 = data_out_linear_p6 report "Error! function:linear, shift:p6, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_p6) & ", expected:" & vec_image(read_data_out_linear_p6) severity failure;
      assert read_data_out_linear_p7 = data_out_linear_p7 report "Error! function:linear, shift:p7, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_linear_p7) & ", expected:" & vec_image(read_data_out_linear_p7) severity failure;
      assert read_data_out_rect_u_m7 = data_out_rect_u_m7 report "Error! function:rect_u, shift:m7, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_m7) & ", expected:" & vec_image(read_data_out_rect_u_m7) severity failure;
      assert read_data_out_rect_u_m6 = data_out_rect_u_m6 report "Error! function:rect_u, shift:m6, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_m6) & ", expected:" & vec_image(read_data_out_rect_u_m6) severity failure;
      assert read_data_out_rect_u_m5 = data_out_rect_u_m5 report "Error! function:rect_u, shift:m5, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_m5) & ", expected:" & vec_image(read_data_out_rect_u_m5) severity failure;
      assert read_data_out_rect_u_m4 = data_out_rect_u_m4 report "Error! function:rect_u, shift:m4, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_m4) & ", expected:" & vec_image(read_data_out_rect_u_m4) severity failure;
      assert read_data_out_rect_u_m3 = data_out_rect_u_m3 report "Error! function:rect_u, shift:m3, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_m3) & ", expected:" & vec_image(read_data_out_rect_u_m3) severity failure;
      assert read_data_out_rect_u_m2 = data_out_rect_u_m2 report "Error! function:rect_u, shift:m2, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_m2) & ", expected:" & vec_image(read_data_out_rect_u_m2) severity failure;
      assert read_data_out_rect_u_m1 = data_out_rect_u_m1 report "Error! function:rect_u, shift:m1, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_m1) & ", expected:" & vec_image(read_data_out_rect_u_m1) severity failure;
      assert read_data_out_rect_u_00 = data_out_rect_u_00 report "Error! function:rect_u, shift:00, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_00) & ", expected:" & vec_image(read_data_out_rect_u_00) severity failure;
      assert read_data_out_rect_u_p1 = data_out_rect_u_p1 report "Error! function:rect_u, shift:p1, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_p1) & ", expected:" & vec_image(read_data_out_rect_u_p1) severity failure;
      assert read_data_out_rect_u_p2 = data_out_rect_u_p2 report "Error! function:rect_u, shift:p2, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_p2) & ", expected:" & vec_image(read_data_out_rect_u_p2) severity failure;
      assert read_data_out_rect_u_p3 = data_out_rect_u_p3 report "Error! function:rect_u, shift:p3, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_p3) & ", expected:" & vec_image(read_data_out_rect_u_p3) severity failure;
      assert read_data_out_rect_u_p4 = data_out_rect_u_p4 report "Error! function:rect_u, shift:p4, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_p4) & ", expected:" & vec_image(read_data_out_rect_u_p4) severity failure;
      assert read_data_out_rect_u_p5 = data_out_rect_u_p5 report "Error! function:rect_u, shift:p5, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_p5) & ", expected:" & vec_image(read_data_out_rect_u_p5) severity failure;
      assert read_data_out_rect_u_p6 = data_out_rect_u_p6 report "Error! function:rect_u, shift:p6, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_p6) & ", expected:" & vec_image(read_data_out_rect_u_p6) severity failure;
      assert read_data_out_rect_u_p7 = data_out_rect_u_p7 report "Error! function:rect_u, shift:p7, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_u_p7) & ", expected:" & vec_image(read_data_out_rect_u_p7) severity failure;
      assert read_data_out_rect_s_m7 = data_out_rect_s_m7 report "Error! function:rect_s, shift:m7, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_m7) & ", expected:" & vec_image(read_data_out_rect_s_m7) severity failure;
      assert read_data_out_rect_s_m6 = data_out_rect_s_m6 report "Error! function:rect_s, shift:m6, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_m6) & ", expected:" & vec_image(read_data_out_rect_s_m6) severity failure;
      assert read_data_out_rect_s_m5 = data_out_rect_s_m5 report "Error! function:rect_s, shift:m5, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_m5) & ", expected:" & vec_image(read_data_out_rect_s_m5) severity failure;
      assert read_data_out_rect_s_m4 = data_out_rect_s_m4 report "Error! function:rect_s, shift:m4, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_m4) & ", expected:" & vec_image(read_data_out_rect_s_m4) severity failure;
      assert read_data_out_rect_s_m3 = data_out_rect_s_m3 report "Error! function:rect_s, shift:m3, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_m3) & ", expected:" & vec_image(read_data_out_rect_s_m3) severity failure;
      assert read_data_out_rect_s_m2 = data_out_rect_s_m2 report "Error! function:rect_s, shift:m2, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_m2) & ", expected:" & vec_image(read_data_out_rect_s_m2) severity failure;
      assert read_data_out_rect_s_m1 = data_out_rect_s_m1 report "Error! function:rect_s, shift:m1, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_m1) & ", expected:" & vec_image(read_data_out_rect_s_m1) severity failure;
      assert read_data_out_rect_s_00 = data_out_rect_s_00 report "Error! function:rect_s, shift:00, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_00) & ", expected:" & vec_image(read_data_out_rect_s_00) severity failure;
      assert read_data_out_rect_s_p1 = data_out_rect_s_p1 report "Error! function:rect_s, shift:p1, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_p1) & ", expected:" & vec_image(read_data_out_rect_s_p1) severity failure;
      assert read_data_out_rect_s_p2 = data_out_rect_s_p2 report "Error! function:rect_s, shift:p2, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_p2) & ", expected:" & vec_image(read_data_out_rect_s_p2) severity failure;
      assert read_data_out_rect_s_p3 = data_out_rect_s_p3 report "Error! function:rect_s, shift:p3, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_p3) & ", expected:" & vec_image(read_data_out_rect_s_p3) severity failure;
      assert read_data_out_rect_s_p4 = data_out_rect_s_p4 report "Error! function:rect_s, shift:p4, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_p4) & ", expected:" & vec_image(read_data_out_rect_s_p4) severity failure;
      assert read_data_out_rect_s_p5 = data_out_rect_s_p5 report "Error! function:rect_s, shift:p5, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_p5) & ", expected:" & vec_image(read_data_out_rect_s_p5) severity failure;
      assert read_data_out_rect_s_p6 = data_out_rect_s_p6 report "Error! function:rect_s, shift:p6, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_p6) & ", expected:" & vec_image(read_data_out_rect_s_p6) severity failure;
      assert read_data_out_rect_s_p7 = data_out_rect_s_p7 report "Error! function:rect_s, shift:p7, data_in:" & vec_image(data_in) & ", data_out:" & vec_image(data_out_rect_s_p7) & ", expected:" & vec_image(read_data_out_rect_s_p7) severity failure;

    end loop;
    wait;
  end process;


end behavioral;
 

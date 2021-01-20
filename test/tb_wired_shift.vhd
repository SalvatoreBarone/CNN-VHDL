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
use std.textio.all;
use ieee.std_logic_textio.all;

library work;
use work.debug_func.all;

entity tb_wired_shift is
end tb_wired_shift;

architecture behavioral of tb_wired_shift is
  component wired_shift is
    generic (
      data_size : natural;
      shift     : integer);
    port (
      data_in   : in std_logic_vector(data_size-1 downto 0);
      data_out  : out std_logic_vector(data_size-1 downto 0));
  end component;

  constant data_size   : natural := 16;
  signal   data_in     : std_logic_vector(data_size-1 downto 0);
  signal   data_out_0  : std_logic_vector(data_size-1 downto 0);
  signal   data_out_r1 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_r2 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_r3 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_r4 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_r5 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_r6 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_r7 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_l1 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_l2 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_l3 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_l4 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_l5 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_l6 : std_logic_vector(data_size-1 downto 0);
  signal   data_out_l7 : std_logic_vector(data_size-1 downto 0);
    
  file test_oracle : text;


begin

  uut0   : wired_shift generic map (data_size,  0) port map (data_in, data_out_0);
  uut_r1 : wired_shift generic map (data_size,  1) port map (data_in, data_out_r1);
  uut_r2 : wired_shift generic map (data_size,  2) port map (data_in, data_out_r2);
  uut_r3 : wired_shift generic map (data_size,  3) port map (data_in, data_out_r3);
  uut_r4 : wired_shift generic map (data_size,  4) port map (data_in, data_out_r4);
  uut_r5 : wired_shift generic map (data_size,  5) port map (data_in, data_out_r5);
  uut_r6 : wired_shift generic map (data_size,  6) port map (data_in, data_out_r6);
  uut_r7 : wired_shift generic map (data_size,  7) port map (data_in, data_out_r7);
  uut_l1 : wired_shift generic map (data_size, -1) port map (data_in, data_out_l1);
  uut_l2 : wired_shift generic map (data_size, -2) port map (data_in, data_out_l2);
  uut_l3 : wired_shift generic map (data_size, -3) port map (data_in, data_out_l3);
  uut_l4 : wired_shift generic map (data_size, -4) port map (data_in, data_out_l4);
  uut_l5 : wired_shift generic map (data_size, -5) port map (data_in, data_out_l5);
  uut_l6 : wired_shift generic map (data_size, -6) port map (data_in, data_out_l6);
  uut_l7 : wired_shift generic map (data_size, -7) port map (data_in, data_out_l7);

  stim_process : process
    variable rline : line;
    variable read_data_in      : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_0  : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_r1 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_r2 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_r3 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_r4 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_r5 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_r6 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_r7 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_l1 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_l2 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_l3 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_l4 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_l5 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_l6 : std_logic_vector(data_size-1 downto 0);
    variable expct_data_out_l7 : std_logic_vector(data_size-1 downto 0);
    variable space : character;
  begin
    file_open(test_oracle, "../test/tb_wired_shift_oracle.txt", read_mode);
    while not endfile(test_oracle) loop
      readline(test_oracle, rline);
      read(rline, read_data_in); read(rline, space);
      read(rline, expct_data_out_0); read(rline, space);
      read(rline, expct_data_out_r1); read(rline, space);
      read(rline, expct_data_out_r2); read(rline, space);
      read(rline, expct_data_out_r3); read(rline, space);
      read(rline, expct_data_out_r4); read(rline, space);
      read(rline, expct_data_out_r5); read(rline, space);
      read(rline, expct_data_out_r6); read(rline, space);
      read(rline, expct_data_out_r7); read(rline, space);
      read(rline, expct_data_out_l1); read(rline, space);
      read(rline, expct_data_out_l2); read(rline, space);
      read(rline, expct_data_out_l3); read(rline, space);
      read(rline, expct_data_out_l4); read(rline, space);
      read(rline, expct_data_out_l5); read(rline, space);
      read(rline, expct_data_out_l6); read(rline, space);
      read(rline, expct_data_out_l7); 
      data_in <= read_data_in;
      wait for 5 ns;

      assert data_out_0  = expct_data_out_0  report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_0) severity failure;
      assert data_out_r1 = expct_data_out_r1 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_r1) severity failure;
      assert data_out_r2 = expct_data_out_r2 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_r2) severity failure;
      assert data_out_r3 = expct_data_out_r3 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_r3) severity failure;
      assert data_out_r4 = expct_data_out_r4 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_r4) severity failure;
      assert data_out_r5 = expct_data_out_r5 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_r5) severity failure;
      assert data_out_r6 = expct_data_out_r6 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_r6) severity failure;
      assert data_out_r7 = expct_data_out_r7 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_r7) severity failure;
      assert data_out_l1 = expct_data_out_l1 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_l1) severity failure;
      assert data_out_l2 = expct_data_out_l2 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_l2) severity failure;
      assert data_out_l3 = expct_data_out_l3 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_l3) severity failure;
      assert data_out_l4 = expct_data_out_l4 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_l4) severity failure;
      assert data_out_l5 = expct_data_out_l5 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_l5) severity failure;
      assert data_out_l6 = expct_data_out_l6 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_l6) severity failure;
      assert data_out_l7 = expct_data_out_l7 report "Errore shift=0 data_in=" & vec_image(data_in) & " data_out=" & vec_image(data_out_l7) severity failure;
   
      
    end loop;
    wait;
  end process;


end behavioral;
 


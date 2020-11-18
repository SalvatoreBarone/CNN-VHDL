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
use ieee.numeric_std.all;

library work;
use work.utils.all;
use work.debug_func.all;
 
entity tb_piped_adder is
end tb_piped_adder;
 
architecture behavioral of tb_piped_adder is 
  component piped_adder is
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
  end component;

  constant  data_size     : natural                                  := 8;
  constant  approx_degree : natural                                 := 0;
  signal    clock         : std_logic                                := '0';
  signal    reset_n       : std_logic                                := '0';
  signal    add_1         : std_logic_vector (data_size-1 downto 0)  := (others => '0');
  signal    add_2         :  std_logic_vector (data_size-1 downto 0) := (others => '0');
  signal    sub_add_n     : std_logic                                := '0';
  signal    sum           : std_logic_vector (data_size-1 downto 0)  := (others => '0');
  constant  clock_period  : time                                     := 10 ns;
  constant  latency       : natural                                  := 1;
  signal    simulate      : std_logic                                := '1';
  
begin

  uut : piped_adder
    generic map(data_size, approx_degree)
    port map (clock, reset_n, add_1, add_2, sub_add_n, sum, open, open);

  clock_process : process
  begin
    while simulate = '1' loop
      clock <= not clock;
      wait for clock_period / 2;
    end loop;
    wait;
  end process clock_process;
  
  -- stimulus process
  stim_proc: process
    variable test_sum : integer;
  begin    
    wait for 10 ns;  
    reset_n <= '0';
    wait for 5*clock_period;
    reset_n <= '1';
    -- prova in addizione
    sub_add_n <= '0';
    for i in -2**(data_size-1) to 2**(data_size-1)-1 loop
      add_1 <= std_logic_vector(to_signed(i, data_size));
      for j in -2**(data_size-1) to 2**(data_size-1)-1 loop
        add_2 <= std_logic_vector(to_signed(j, data_size));
        test_sum := i + j;
        wait for (latency+1)*clock_period;
        assert sum = std_logic_vector(to_signed(test_sum, data_size)) report "Errore calcolo somma in somma con i=" & integer'image(i) & " j=" & integer'image(j) & " sum=" & vec_image(sum) & " expected: " & integer'image(test_sum) severity failure;
      end loop;
    end loop;
    -- prova in sottrazione
    sub_add_n <= '1';
    for i in -2**(data_size-1) to 2**(data_size-1)-1 loop
      add_1 <= std_logic_vector(to_signed(i, data_size));
      for j in -2**(data_size-1) to 2**(data_size-1)-1 loop
        add_2 <= std_logic_vector(to_signed(j, data_size));
        test_sum := i - j;
        wait for (latency+1)*clock_period;
        assert   sum = std_logic_vector(to_signed(test_sum, data_size)) report "Errore calcolo somma in sottrazione con i=" & integer'image(i) & " j=" & integer'image(j) & " sum=" & vec_image(sum) & " expected: " & integer'image(test_sum) severity failure;
      end loop;
    end loop;
    simulate <= '0';
    wait;
  end process;
end;

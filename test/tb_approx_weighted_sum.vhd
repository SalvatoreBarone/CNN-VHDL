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
use work.utils.all;
use work.data_types.all;
 
entity tb_approx_weighted_sum is
end tb_approx_weighted_sum;

architecture behavioral of tb_approx_weighted_sum is
  component weighted_sum is
    generic (
      -- Structural properties of convolutional kernel
      input_depth       : natural      := 1;                                                                    -- Number of input channels
      ker_width         : natural      := 5;                                                                    -- Kernel width
      ker_height        : natural      := 5;                                                                    -- Kernel height
      add_approx_degree : natural      := 0;                                                                    -- Approximation degree for adders
      mul_approx_degree : natural      := 0);                                                                   -- Approximation degree for multipliers
    port (
      clock         : in std_logic;                                                                             -- Clock signal
      reset_n       : in std_logic;                                                                             -- Reset signal (active low)
      inputs        : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);                  -- input volume
      bias          : in std_logic_vector(data_size-1 downto 0);                                                -- bias (single term) 
      weights       : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);                  -- weights volume
      sum           : out std_logic_vector(2*(data_size+1)+log2(input_depth*ker_height*ker_width+1) downto 0)); -- output
  end component;

  ------------------------------------------------------------------------------
  -- Generics
  constant input_depth       : natural       := 1;
  constant ker_width         : natural       := 5;
  constant ker_height        : natural       := 5;
  -- Port
  signal   clock             : std_logic := '0';
  signal   reset_n           : std_logic := '0';
  signal   inputs            : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1) := (others => (others => (others => (others => '0'))));
  signal   bias              : std_logic_vector(data_size-1 downto 0) := (others => '0'); 
  signal   weights           : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1) := (others => (others => (others => (others => '0'))));

  type     sum_matrix        is array (natural range <>, natural range <>) of std_logic_vector(2*(data_size+1)+log2(input_depth*ker_height*ker_width+1) downto 0);
  signal   outputs           : sum_matrix(0 to data_size-2, 0 to data_size-2)  := (others => (others => (others => '0')));
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Testbench signals
	constant clock_period   : time          := 10 ns;
  constant latency        : natural       := log2(input_depth*ker_height*ker_width)+7;
  file     test_oracle    : text;
	signal   simulate       : std_logic     := '1';
begin
  uuts_r : for nab_mul in 0 to data_size-2 generate
    uuts_c : for nab_add in 0 to data_size-2 generate
    uut: weighted_sum
      generic map (input_depth, ker_width, ker_height, nab_add, nab_mul)
      port map(clock, reset_n, inputs, bias, weights, outputs(nab_mul, nab_add));
    end generate;
  end generate;

	clock_process : process
	begin
		while simulate = '1' loop
			clock <= not clock;
			wait for clock_period / 2;
		end loop;
		wait;
	end process clock_process;

  stim_process : process
    variable rline        : line;
    variable space        : character;
    variable read_bias    : std_logic_vector(data_size-1 downto 0); 
    variable read_weights : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);
    variable read_inputs  : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);
    variable read_outputs : sum_matrix(0 to data_size-2, 0 to data_size-2);
    variable line_number  : integer := 0;
  begin
    file_open(test_oracle, "../test/tb_approx_weighted_sum_oracle.txt", read_mode);

		reset_n <= '0', '1' after 5*clock_period;
		wait for 7*clock_period;

    while not endfile(test_oracle) loop
      readline(test_oracle, rline);
      -- reading bias
      read(rline, read_bias); read(rline, space);
      bias <= read_bias;
      -- reading weights
      for sz in 0 to input_depth-1 loop
        for sy in 0 to ker_height-1 loop
          for sx in 0 to ker_width-1 loop
            read(rline, read_weights(sz, sy, sx)); read(rline, space);
            weights(sz, sy, sx) <= read_weights(sz, sy, sx);
          end loop;
        end loop;
      end loop;
      -- reading inputs 
      for sz in 0 to input_depth-1 loop
        for sy in 0 to ker_height-1 loop
          for sx in 0 to ker_width-1 loop
            read(rline, read_inputs(sz, sy, sx)); read(rline, space);
            inputs(sz, sy, sx) <= read_inputs(sz, sy, sx);
          end loop;
        end loop;
      end loop;
      -- waiting the computation to complete
      wait for (latency+1)*clock_period;
      -- reading output
      for nab_mul in 0 to data_size-2 loop
        for nab_add in 0 to data_size-2 loop
          read(rline, read_outputs(nab_mul, nab_add)); read(rline, space);
          assert read_outputs(nab_mul, nab_add) = outputs(nab_mul, nab_add) report "Error with input line " & integer'image(line_number) severity failure; 
        end loop;
      end loop;  
      line_number := line_number + 1;
    end loop;
		simulate <= '0';
		wait;
  end process;
end behavioral;
 



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
use work.data_types.all;
use work.utils.all;
use work.activation_functions.all;

entity tb_neuromesh_lenet5_fc1 is
end tb_neuromesh_lenet5_fc1;

architecture behavioral of tb_neuromesh_lenet5_fc1 is
  component neuromesh is
    generic (
      -- Structural properties of the mesh
      parallel_weights_rows      : natural;            -- Number of rows of the mesh, i.e. the amount of neurons processing the same inputs
      parallel_inputs_cols       : natural;            -- Number of columns of the mesh, i.e. the amount of neurons using the same weights on different inputs
      -- Structural properties of convolutional kernel
      unsigned_inputs            : boolean;            -- Is input feature map unsigned?
      input_depth                : natural;            -- Number of input channels
      ker_width                  : natural;            -- Kernel width
      ker_height                 : natural;            -- Kernel height
      -- Properties of the activation function
      act_kind                   : activation_t;       -- type of activation
      act_unsigned               : boolean;            -- do the activation work on unsigned data?
      shift                      : integer;            -- shift amount for the activation function
      -- Approximation degrees (truncation)
      add_approx_degree          : natural;            -- Approximation degree for adders
      mul_approx_degree          : natural);           -- Approximation degree for multipliers
    port (
      clock   : in  std_logic;                                                                                                -- Clock signal
      reset_n : in  std_logic;                                                                                                -- Reset signal (active low)
      weights : in  data_hypervolume(0 to parallel_weights_rows-1, 0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);  -- weights volume
      bias    : in  bias_vector(0 to parallel_weights_rows-1);                                                                -- biases (one bias for each one of the weight volumes) 
      inputs  : in  data_hypervolume(0 to parallel_inputs_cols-1, 0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);   -- input volume
      outputs : out data_matrix(0 to parallel_weights_rows-1, 0 to parallel_inputs_cols-1));                                  -- output
  end component;
  ------------------------------------------------------------------------------
  -- Generics
  constant parallel_weights_rows    : natural      := 6;
  constant parallel_inputs_cols     : natural      := 1;
  constant unsigned_inputs          : boolean      := true;
  constant input_depth              : natural      := 120;
  constant ker_width                : natural      := 1;
  constant ker_height               : natural      := 1;
  constant act_kind                 : activation_t := rectifier;
  constant act_unsigned             : boolean      := true;
  constant shift                    : integer      := 0;
  constant add_approx_degree        : natural      := 0;
  constant mul_approx_degree        : natural      := 0;
  -- Port
  signal   clock             : std_logic := '0';
  signal   reset_n           : std_logic := '0';
  signal   inputs            : data_hypervolume(0 to parallel_inputs_cols-1, 0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1) := (others => (others => (others => (others => (others => '0')))));
  signal   weights           : data_hypervolume(0 to parallel_weights_rows-1, 0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1) := (others => (others => (others => (others => (others => '0')))));
  signal   bias              : bias_vector(0 to parallel_weights_rows-1) := (others => (others => '0')); 
  signal   outputs           : data_matrix(0 to parallel_weights_rows-1, 0 to parallel_inputs_cols-1) := (others => (others => (others => '0')));
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Testbench stuff
	constant clock_period   : time          := 10 ns;
  constant latency        : natural       := log2(input_depth*ker_height*ker_width)+7;
  file     test_biases    : text;
  file     test_weights   : text;
  file     test_inputs    : text;
  file     test_outputs   : text;
	signal   simulate       : std_logic     := '1';
begin
  uut : neuromesh
    generic map(parallel_weights_rows, parallel_inputs_cols, unsigned_inputs, input_depth, ker_width, ker_height, act_kind, act_unsigned, shift, add_approx_degree, mul_approx_degree)
    port map(clock, reset_n, weights, bias, inputs, outputs);

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
    variable read_bias    : bias_vector(0 to parallel_weights_rows-1); 
    variable read_weights : data_hypervolume(0 to parallel_weights_rows-1, 0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);
    variable read_inputs  : data_hypervolume(0 to parallel_inputs_cols-1, 0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);
    variable read_outputs : data_matrix(0 to parallel_weights_rows-1, 0 to parallel_inputs_cols-1);
    variable line_number  : integer := 0;
  begin
		reset_n <= '0';
    wait for clock_period;
    reset_n <= '1';
    ----------------------------------------------------------------------------
    -- Reading biases
    file_open(test_weights, "../test/tb_neuromesh_lenet5_fc1_weights.txt", read_mode);
    file_open(test_biases, "../test/tb_neuromesh_lenet5_fc1_biases.txt", read_mode);
    file_open(test_outputs, "../test/tb_neuromesh_lenet5_fc1_outputs.txt", read_mode);
    while not endfile(test_biases) and not endfile(test_weights) loop
      report "Reading biases ..." severity note;
      readline(test_biases, rline);
      for w in 0 to parallel_weights_rows-1 loop
        read(rline, read_bias(w)); read(rline, space);
      end loop; 
      bias <= read_bias;
      report "Reading weights ..." severity note;
      readline(test_weights, rline);
      for w in 0 to parallel_weights_rows-1 loop
        for sz in 0 to input_depth-1 loop
          for sy in 0 to ker_height-1 loop
            for sx in 0 to ker_width-1 loop
              read(rline, read_weights(w, sz, sy, sx)); read(rline, space);
            end loop;
          end loop;
        end loop;
      end loop;
      weights <= read_weights;
      file_open(test_inputs, "../test/tb_neuromesh_lenet5_fc1_inputs.txt", read_mode);
      while not endfile(test_inputs) loop
        report "Processing input line " & integer'image(line_number) severity note;
        readline(test_inputs, rline);
        for i in 0 to parallel_inputs_cols-1 loop
          for sz in 0 to input_depth-1 loop
            for sy in 0 to ker_height-1 loop
              for sx in 0 to ker_width-1 loop
                read(rline, read_inputs(i, sz, sy, sx)); read(rline, space);
              end loop;
            end loop;
          end loop;
        end loop;
        inputs <= read_inputs;
        wait for latency * clock_period;
        readline(test_outputs, rline);
        for i in 0 to parallel_inputs_cols-1 loop
          for w in 0 to parallel_weights_rows-1 loop
            read(rline, read_outputs(w,i)); read(rline, space);
            assert read_outputs(w,i) = outputs(w,i) report "Error with input line " & integer'image(line_number) severity failure; 
          end loop;
        end loop;
        line_number := line_number + 1;
      end loop;
      file_close(test_inputs);
    end loop;
    file_close(test_weights);
    file_close(test_biases); 
    file_close(test_outputs);
		simulate <= '0';
		wait;
  end process;
end behavioral;


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
use work.activation_functions.all;
 
entity tb_neuron_pipelining is
end tb_neuron_pipelining;

architecture behavioral of tb_neuron_pipelining is
  component neuron is
  generic (
    -- Structural properties of convolutional kernel
    input_depth       : natural      := 120;                                                  -- Number of input channels
    ker_width         : natural      := 5;                                                    -- Kernel width
    ker_height        : natural      := 5;                                                    -- Kernel height
    act_kind          : activation_t := rectifier;                                            -- type of activation
    act_unsigned      : boolean      := true;                                                 -- do the activation work on unsigned data?
    shift             : integer      := 2;                                                    -- shift amount for the activation function
    add_approx_degree : natural      := 0;                                                    -- Approximation degree for adders
    mul_approx_degree : natural      := 0);                                                   -- Approximation degree for multipliers
  port (
    clock         : in std_logic;                                                             -- Clock signal
    reset_n       : in std_logic;                                                             -- Reset signal (active low)
    inputs        : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);  -- input volume
    bias          : in std_logic_vector(data_size-1 downto 0);                                -- bias (single term) 
    weights       : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);  -- weights volume
    outputs       : out std_logic_vector(data_size-1 downto 0));                              -- output
  end component;

  ------------------------------------------------------------------------------
  -- Generics
  constant input_depth       : natural       := 1;
  constant ker_width         : natural       := 5;
  constant ker_height        : natural       := 5;
  constant act_kind          : activation_t  := rectifier;
  constant act_unsigned      : boolean       := true;
  constant shift             : integer       := 2;
  constant add_approx_degree : natural       := 0;
  constant mul_approx_degree : natural       := 0;
  -- Port
  signal   clock             : std_logic := '0';
  signal   reset_n           : std_logic := '0';
  signal   inputs            : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1) := (others => (others => (others => (others => '0'))));
  signal   bias              : std_logic_vector(data_size-1 downto 0) := (others => '0'); 
  signal   weights           : data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1) := (others => (others => (others => (others => '0'))));
  signal   outputs           : std_logic_vector(data_size-1 downto 0) := (others => '0');
  ------------------------------------------------------------------------------

  ------------------------------------------------------------------------------
  -- Testbench signals
	constant clock_period   : time          := 10 ns;
  constant latency        : natural       := log2(input_depth*ker_height*ker_width)+7;
  file     test_inputs    : text;
  file     test_oracle    : text;
	signal   simulate       : std_logic     := '1';
begin
  uut: neuron
    generic map (input_depth, ker_width, ker_height, act_kind, act_unsigned, shift, add_approx_degree, mul_approx_degree)
    port map(clock, reset_n, inputs, bias, weights, outputs);

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
  begin
    file_open(test_inputs, "../test/tb_neuron_pipelining_input.txt", read_mode);

		reset_n <= '0', '1' after 5*clock_period;
    while not endfile(test_inputs) loop
      readline(test_inputs, rline);
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
      wait for clock_period;
    end loop;
		wait;
  end process;

  output_process : process
    variable rline        : line;
    variable space        : character;
    variable read_outputs : std_logic_vector(data_size-1 downto 0);
    variable line_number  : integer := 0;
  begin
    file_open(test_oracle, "../test/tb_neuron_pipelining_oracle.txt", read_mode);
    -- wait for the reset signal to become inactive
    while reset_n = '0' loop
    end loop; 
    -- waiting for the firs computation to complete
    wait for latency * clock_period;
    while not endfile(test_oracle) loop
      readline(test_oracle, rline);
      -- reading output
      read(rline, read_outputs);
      assert read_outputs = outputs report "Error with input line " & integer'image(line_number) severity failure; 
      line_number := line_number + 1;
      wait for clock_period;
    end loop;
		simulate <= '0';
		wait;
  end process;
end behavioral;
 


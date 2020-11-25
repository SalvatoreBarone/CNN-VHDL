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
use work.data_types.all;
use work.activation_functions.all;
use work.debug_func.all;

entity tb_neuron_4dpa is
end tb_neuron_4dpa;

architecture mixed_structural_behavioral of tb_neuron_4dpa is
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
  -- Testbench signals
	constant clock_period   : time          := 10 ns;
  constant latency        : natural       := log2(input_depth*ker_height*ker_width)+7;
	constant clock_period   : time          := 10 ns;
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
    constant test_vectors : integer := 10000;
  begin
		reset_n <= '0', '1' after 5*clock_period;
		wait for 7*clock_period;
    for test_case in 0 to test_vectors-1 loop
      bias <= std_logic_vector(to_signed(random(-2**(data_size-1), 2**(data_size-1)-1), data_size));
      -- random inputs and weights
      for sz in 0 to input_depth-1 loop
        for sy in 0 to ker_height-1 loop
          for sx in 0 to ker_width-1 loop
            weights(sz, sy, sx) <= std_logic_vector(to_signed(random(-2**(data_size-1), 2**(data_size-1)-1), data_size));
            inputs(sz, sy, sx) <= std_logic_vector(to_signed(random(-2**(data_size-1), 2**(data_size-1)-1), data_size));
          end loop;
        end loop;
      end loop;
      -- waiting the computation to complete
      wait for latency *clock_period;
      -- assert read_outputs = outputs report "Error with input line " & integer'image(line_number) severity failure; 
      -- line_number := line_number + 1;
    end loop;
		simulate <= '0';
		wait;
  end process;
end mixed_structural_behavioral;
 

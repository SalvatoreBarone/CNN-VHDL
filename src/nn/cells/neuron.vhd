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

library work;
use work.utils.all;
use work.data_types.all;
use work.activation_functions.all;

entity neuron is
  generic (
    unsigned_inputs   : boolean;                                                        -- Is input feature map unsigned?
    -- Structural properties of convolutional kernel
    input_depth       : natural;                                                        -- Number of input channels
    ker_width         : natural;                                                        -- Kernel width
    ker_height        : natural;                                                        -- Kernel height
    -- Properties of the activation function
    act_kind          : activation_t;                                                   -- type of activation
    act_unsigned      : boolean;                                                        -- do the activation work on unsigned data?
    shift             : integer;                                                        -- shift amount for the activation function
    -- Approximation degrees (truncation)
    add_approx_degree : natural;                                                        -- Approximation degree for adders
    mul_approx_degree : natural);                                                       -- Approximation degree for multipliers
  port (
    clock   : in std_logic;                                                             -- Clock signal
    reset_n : in std_logic;                                                             -- Reset signal (active low)
    inputs  : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);  -- input volume
    bias    : in std_logic_vector(data_size-1 downto 0);                                -- bias (single term) 
    weights : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);  -- weights volume
    outputs : out std_logic_vector(data_size-1 downto 0));                              -- output
end neuron;

architecture structural of neuron is
  component generic_register is
  	generic(data_size : natural);
  	port (
  		clk  : in std_logic;
  		rst_n  : in std_logic;
  		data_in : in std_logic_vector (data_size-1 downto 0);
  		en : in std_logic;
  		data_out : out std_logic_vector (data_size-1 downto 0)
  	);
  end component;
  component weighted_sum is
    generic (
      unsigned_inputs   : boolean;                                                                              -- Is input feature map unsigned?
      -- Structural properties of convolutional kernel
      input_depth       : natural;                                                                              -- Number of input channels
      ker_width         : natural;                                                                              -- Kernel width
      ker_height        : natural;                                                                              -- Kernel height
      -- Approx. degree (truncation)
      add_approx_degree : natural;                                                                              -- Approximation degree for adders
      mul_approx_degree : natural);                                                                             -- Approximation degree for multipliers
    port (
      clock         : in std_logic;                                                                             -- Clock signal
      reset_n       : in std_logic;                                                                             -- Reset signal (active low)
      inputs        : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);                  -- input volume
      bias          : in std_logic_vector(data_size-1 downto 0);                                                -- bias (single term) 
      weights       : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);                  -- weights volume
      sum           : out std_logic_vector(2*(data_size+1)+log2(input_depth*ker_height*ker_width+1) downto 0)); -- output
  end component;
  component activation is
    generic (
      kind                : activation_t;
      unsigned_data       : boolean;
      actual_data_size    : natural;
      final_data_size     : natural;
      shift               : integer);
    port (
      data_in   : in std_logic_vector(actual_data_size-1 downto 0);
      data_out  : out std_logic_vector(final_data_size-1 downto 0));
  end component;
  constant num_terms          : natural                                := input_depth * ker_height * ker_width;  -- total amount of partial product terms (equals the volume size )
  constant num_terms_2        : natural                                := 2 ** (log2(num_terms+1)+1);            -- next power of two for num_terms (note, it include the bias term now)
  constant internal_data_size : natural                                := data_size+1;                           -- needed in order to convert inputs to unsigned
  constant pprod_size         : natural                                := 2*internal_data_size;                  -- data size of partial product terms
  constant sum_size           : natural                                := pprod_size+log2(num_terms_2);          -- size of the sum (number of bits)
  signal   sum                : std_logic_vector(sum_size-1 downto 0)  := (others => '0');                       -- sum of the partial product terms (bias included)
  signal   output_unbuff      : std_logic_vector(data_size-1 downto 0) := (others => '0');                       -- unbuffered output
begin
  -- weighted sum computation
  w_sum : weighted_sum
    generic map(unsigned_inputs, input_depth, ker_width, ker_height, add_approx_degree, mul_approx_degree)
    port map(clock, reset_n, inputs, bias, weights, sum);
  -- Activation function and saturation
  act : activation
    generic map(act_kind, act_unsigned, sum_size, data_size, shift)
    port map(sum, output_unbuff);
  -- last pipe stage
  output_buf : generic_register
    generic map (data_size)
    port map(clock, reset_n, output_unbuff, '1', outputs);
end structural;  

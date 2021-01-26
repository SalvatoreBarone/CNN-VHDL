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

-- Neurons mesh can be used to implement fully-connected layers (reusing inputs)
-- or even a full convolutional layer (reusing weights only or both inputs and
-- weights).
--
-- It consist of a matrix of neurons. Neurons on the same row share weights
-- (i.e. a row implements weight reuse), while neurons on the same colums 
-- processes the same inputs (i.e. a column implements input reuse).
-- 
-- Weights and inputs are distrubuted using a mesh (hence the name of this
-- entity).
--
-- A mesh with a single column (partially) implements a fully connected layer
-- (in which all neurons processes the same input, while each of them has 
-- different synaptic weights).
-- A mesh with multiple rows and one column (partially) implement a convolution
-- for a single depth slice (neurons belonging to the same depth-slice i.e. 
-- output feature map share weights).
--
-- A mesh with multiple rows and columns may be used to partually implement
-- a piace of a convolutional layer!
--
-- Note: weights and input managements is up to the user (read "you reading, you
-- implement the memory hierarchy you like the most").
entity neuromesh is
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
end neuromesh;

architecture structural of neuromesh is
  component neuron is
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
      inputs  : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);  -- input volume (signed integer, internally converted to unsigned wheter unsigned_inputs is true)
      bias    : in std_logic_vector(2*data_size-1 downto 0);                              -- bias (single term, signed integer) 
      weights : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);  -- weights volume (signed integer)
      outputs : out std_logic_vector(data_size-1 downto 0));                              -- output (signed integer)
  end component;
  type internal_hypervolume is array(natural range <>) of data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);
  signal weights_hypervolume : internal_hypervolume(0 to parallel_weights_rows-1);
  signal inputs_hypervolume  : internal_hypervolume(0 to parallel_inputs_cols-1);
begin
  -- mesh assignments
  -- weights assignement
  y_assing : for y in 0 to parallel_weights_rows-1 generate
    d_assign : for d in  0 to input_depth-1 generate
      h_assign : for h in  0 to ker_height-1 generate
        w_assing : for w in 0 to ker_width-1 generate
          weights_hypervolume(y)(d,h,w) <= weights(y,d,h,w);
        end generate;
      end generate;
    end generate;
  end generate;
  -- input assignement
  x_assing : for x in 0 to parallel_inputs_cols-1 generate
    d_assign : for d in  0 to input_depth-1 generate
      h_assign : for h in  0 to ker_height-1 generate
        w_assing : for w in 0 to ker_width-1 generate
          inputs_hypervolume(x)(d,h,w) <= inputs(x,d,h,w);
        end generate;
      end generate;
    end generate;
  end generate;
  -- mesh of neurons
  col_of_neurons : for i in 0 to parallel_weights_rows-1 generate
    row_of_neurons : for j in 0 to parallel_inputs_cols-1 generate
      processing_element : neuron
        generic map (unsigned_inputs, input_depth, ker_width, ker_height, act_kind, act_unsigned, shift, add_approx_degree, mul_approx_degree)
        port map (clock, reset_n, inputs_hypervolume(j), bias(i), weights_hypervolume(i), outputs(i,j));
    end generate;
  end generate;
end structural;


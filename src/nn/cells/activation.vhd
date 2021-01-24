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

package activation_functions is
  type activation_t is (logistic, logistic_with_loss, tan_h, tan_h_lecun, saturation, linear, rectifier);
end package;

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_misc.all;

entity sum_saturation is
  generic (
    unsigned_data       : boolean;                                  -- Does the activation work on unsigned data? note. this is meaningfull only for rectifier
    actual_data_size    : natural;                                  -- actual data size (input)
    final_data_size     : natural;                                  -- final data size (output). note actual_data_size >= final_data_size
    shift               : integer);
  port (
    data_in   : in std_logic_vector(actual_data_size-1 downto 0);   -- inputs
    data_out  : out std_logic_vector(final_data_size-1 downto 0));  -- outputs
end entity;

architecture dataflow of sum_saturation is
  component wired_shift is
    generic (
      data_size : natural;
      shift     : integer);
    port (
      data_in   : in std_logic_vector(data_size-1 downto 0);
      data_out  : out std_logic_vector(data_size-1 downto 0));
  end component;
  signal int_minimum : std_logic_vector(final_data_size-1 downto 0);
  signal int_maximum : std_logic_vector(final_data_size-1 downto 0);

  signal data_in_shf : std_logic_vector(actual_data_size-1 downto 0) := (others => '0');
  signal conditions : std_logic_vector(3 downto 0);
begin
  -- y = (x >> rs)
  shf : wired_shift
    generic map(actual_data_size, shift)
    port map (data_in, data_in_shf);

  conditions <= data_in_shf(data_in_shf'left) &                                      -- is negative
                and_reduce(data_in_shf(data_in_shf'left-1 downto final_data_size)) & -- lower bound break 
                or_reduce( data_in_shf(data_in_shf'left-1 downto final_data_size)) & -- upper bound break
                data_in_shf(final_data_size-1);                                      -- sign bit

  -- Compunting saturating-maximum/minimum for signed/unsigned number on final_data_size bits
  int_maximum(int_maximum'left-1 downto 0) <= (others => '1');
  int_minimum(int_minimum'left-1 downto 0) <= (others => '0');
  max_generate_unsigned : if unsigned_data = true generate
    int_maximum(int_maximum'left) <= '1';
    int_minimum(int_minimum'left) <= '0';
    with conditions select
      data_out <= data_in_shf(data_out'range) when b"0000",
                  data_in_shf(data_out'range) when b"0001",
                  int_maximum                 when b"0010",
                  int_maximum                 when b"0011",
                  int_maximum                 when b"0110",
                  int_maximum                 when b"0111",
                  (others => '0')             when others;
  end generate;
  max_generate_signed : if unsigned_data = false generate
    int_maximum(int_maximum'left) <= '0';
    int_minimum(int_minimum'left) <= '1';
    with conditions select
      data_out <= data_in_shf(data_out'range) when b"0000",
                  int_maximum                 when b"0001",
                  int_maximum                 when b"0010",
                  int_maximum                 when b"0011",
                  int_maximum                 when b"0110",
                  int_maximum                 when b"0111",
                  data_in_shf(data_out'range) when b"1111",
                  int_minimum                 when others;
  end generate;
end dataflow;


library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_misc.all;
library work;
use work.activation_functions.all;

entity activation is
  generic (
    kind                : activation_t;                             -- Activation kind
    unsigned_data       : boolean;                                  -- Does the activation work on unsigned data? note. this is meaningfull only for rectifier
    actual_data_size    : natural;                                  -- actual data size (input)
    final_data_size     : natural;                                  -- final data size (output). note actual_data_size >= final_data_size
    shift               : integer);
  port (
    data_in   : in std_logic_vector(actual_data_size-1 downto 0);   -- inputs
    data_out  : out std_logic_vector(final_data_size-1 downto 0));  -- outputs
end entity;

architecture data_flow of activation is
  component wired_shift is
    generic (
      data_size : natural;
      shift     : integer);
    port (
      data_in   : in std_logic_vector(data_size-1 downto 0);
      data_out  : out std_logic_vector(data_size-1 downto 0));
  end component;
  component sum_saturation is
    generic (
      unsigned_data       : boolean;                                  -- Does the activation work on unsigned data? note. this is meaningfull only for rectifier
      actual_data_size    : natural;                                  -- actual data size (input)
      final_data_size     : natural;                                  -- final data size (output). note actual_data_size >= final_data_size
      shift               : integer);
    port (
      data_in   : in std_logic_vector(actual_data_size-1 downto 0);   -- inputs
      data_out  : out std_logic_vector(final_data_size-1 downto 0));  -- outputs
  end component;

  constant ext_size       : natural                                := 2*actual_data_size;
  signal   data_in_exp    : std_logic_vector (ext_size-1 downto 0) := (others => '0');
  signal   data_in_shf    : std_logic_vector (ext_size-1 downto 0) := (others => '0');
  signal   max_0_data_in  : std_logic_vector (ext_size-1 downto 0) := (others => '0');
begin

  -- Sign extension
  data_in_exp(data_in'range) <= data_in;
  data_in_exp(data_in_exp'left downto data_in'left+1) <= (others => data_in(data_in'left));

-- if (shift > 0)
--     weightedSum >>= shift;
-- else if (shift < 0)
--     weightedSum <<= (-shift);
  shf1 : wired_shift
    generic map(ext_size, shift)
    port map (data_in_exp, data_in_shf);

-- switch (func)
  logistic_shift : if kind = logistic or kind = logistic_with_loss generate
    sum_sat : sum_saturation
      generic map(false, ext_size, final_data_size, final_data_size + 1)
      port map(data_in_shf, data_out);
  end generate;
  linear_shift : if kind = linear or kind = tan_h or kind = tan_h_lecun or kind = saturation generate
    sum_sat : sum_saturation
      generic map(false, ext_size, final_data_size, final_data_size)
      port map(data_in_shf, data_out);
  end generate;
  rect_shift : if kind = rectifier generate
    -- max(0, sum)  
    with data_in_shf(data_in_shf'left) select
      max_0_data_in <= data_in_shf when '0', (others => '0') when others;
    rect_unsigned : if unsigned_data = true generate
        sum_sat : sum_saturation
        generic map(true, ext_size, final_data_size, final_data_size-1)
        port map(max_0_data_in, data_out);
    end generate;  
    rect_signed : if unsigned_data = false generate
      sum_sat : sum_saturation
      generic map(false, ext_size, final_data_size, final_data_size)
      port map(max_0_data_in, data_out);
    end generate;  
  end generate;
end data_flow;

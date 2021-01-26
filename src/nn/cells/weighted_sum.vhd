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

entity weighted_sum is
  generic (
    unsigned_inputs   : boolean;                                                                                  -- Is input feature map unsigned?
    -- Structural properties of convolutional kernel
    input_depth       : natural;                                                                                  -- Number of input channels
    ker_width         : natural;                                                                                  -- Kernel width
    ker_height        : natural;                                                                                  -- Kernel height
    -- Approx. degree (truncation)
    add_approx_degree : natural;                                                                                  -- Approximation degree for adders
    mul_approx_degree : natural);                                                                                 -- Approximation degree for multipliers
  port (
    clock             : in std_logic;                                                                             -- Clock signal
    reset_n           : in std_logic;                                                                             -- Reset signal (active low)
    inputs            : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);                  -- input volume (signed integer, internally converted to unsigned wheter unsigned_inputs is true)
    bias              : in std_logic_vector(2*data_size-1 downto 0);                                              -- bias (single term, signed integer) 
    weights           : in data_volume(0 to input_depth-1, 0 to ker_height-1, 0 to ker_width-1);                  -- weights volume (signed integer)
    sum               : out std_logic_vector(2*(data_size+1)+log2(input_depth*ker_height*ker_width+1) downto 0)); -- output (signed integer)
end weighted_sum;

architecture structural of weighted_sum is
  component pipe_delay is
    generic (
      data_size : natural;
      stages    : natural);
    port (
      clock     : in  std_logic;
      reset_n   : in  std_logic;
      data_in   : in  std_logic_vector(data_size-1 downto 0);
      data_out  : out std_logic_vector(data_size-1 downto 0));
  end component;
  component multiplier is
    generic (
      data_size     : natural;
      approx_degree : natural);
    port (
      clock         : in std_logic;
      reset_n       : in std_logic;
      x             : in  std_logic_vector(data_size-1 downto 0);
      y             : in  std_logic_vector(data_size-1 downto 0);
      prod          : out std_logic_vector ((2*data_size)-1 downto 0));
  end component;
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
  component sum_reduct is
    generic (
      noperands     : natural;
      data_size     : natural;
      approx_degree : natural);
    port (
  		clk     : in std_logic;
  		rst_n   : in std_logic;
      inputs  : in std_logic_vector ((noperands * data_size)-1 downto 0);
  		sum     : out std_logic_vector (data_size+log2(noperands)-1 downto 0));
  end component;

  constant num_terms          : natural                                         := input_depth * ker_height * ker_width;  -- total amount of partial product terms (equals the volume size )
  constant num_terms_2        : natural                                         := 2 ** (log2(num_terms+1)+1);            -- next power of two for num_terms (note, it include the bias term now)
  constant internal_data_size : natural                                         := data_size+1;                           -- needed in order to convert inputs to unsigned
  constant pprod_size         : natural                                         := 2*internal_data_size;                  -- data size of partial product terms
  constant sum_size           : natural                                         := pprod_size+log2(num_terms_2);          -- size of the sum (number of bits)
  constant pprod_concat_size  : natural                                         := num_terms_2*pprod_size;                -- size of partial product (concatenated)
  signal   pprod_concat       : std_logic_vector(pprod_concat_size-1 downto 0)  := (others => '0');                       -- concatenation of partial_prod (bias included)
--  signal   sum                : std_logic_vector(sum_size-1 downto 0)           := (others => '0');                       -- sum of the partial product terms (bias included)
  signal   output_unbuff      : std_logic_vector(data_size-1 downto 0)          := (others => '0');                       -- unbuffered output

  type iinputs_t              is array (natural range <>) of std_logic_vector(internal_data_size-1 downto 0);             -- new data type to hold sign-extended weights and unsigned inputs
  type pprod_t                is array (natural range <>) of std_logic_vector(pprod_size-1 downto 0);                     -- new data type to hold partual products

  signal ext_weights          : iinputs_t(num_terms-1 downto 0) := (others => (others => '0'));                           -- sign-extended weights
  signal uns_inputs           : iinputs_t(num_terms-1 downto 0) := (others => (others => '0'));                           -- inputs (unsigned)
  signal pprod_unbuf          : pprod_t(num_terms-1 downto 0) := (others => (others => '0'));                             -- partial products terms as they comes from multipliers
  signal pprod                : pprod_t(num_terms-1 downto 0) := (others => (others => '0'));                             -- partial product terms after the pipe stage  
  signal bias_buff            : std_logic_vector(2*data_size-1 downto 0) := (others => '0');                               -- bias (buffered so it traverses the same amunt of pipe stages)
  signal ext_bias             : std_logic_vector(pprod_size -1 downto 0) := (others => '0');
begin
  -- inputs and weights assignment
  w_i_loop_z : for sz in 0 to input_depth-1 generate
    w_i_loop_y: for sy in 0 to ker_height-1 generate
      w_i_loop_x : for sx in 0 to ker_width-1 generate
        ext_weights((ker_width*ker_height*sz)+(ker_width*sy)+sx) <= weights(sz, sy, sx)(data_size-1) & weights(sz, sy, sx);
        uns : if unsigned_inputs = true generate
          uns_inputs((ker_width*ker_height*sz)+(ker_width*sy)+sx) <= '0' & inputs(sz, sy, sx);
        end generate;
        sig : if unsigned_inputs = false generate
          uns_inputs((ker_width*ker_height*sz)+(ker_width*sy)+sx) <= inputs(sz, sy, sx)(data_size-1) & inputs(sz, sy, sx);
        end generate;
      end generate;
    end generate;
  end generate;  
  -- Bias buffering (so it traverses tha same amount of pipe stages)
  bias_buf : pipe_delay
    generic map (2*data_size, 3)
    port map(clock, reset_n, bias, bias_buff);
  -- Bias sign extension
  ext_bias(bias'range) <= bias_buff;
  with bias_buff(bias_buff'left) select
    ext_bias(ext_bias'left downto bias_buff'left+1) <= (others => '1') when '1', (others => '0') when others;
  -- Partial product computation
  pprod_loop : for i in 0 to num_terms-1 generate
        mul_w_i : multiplier generic map(internal_data_size, mul_approx_degree) port map (clock, reset_n, ext_weights(i), uns_inputs(i), pprod_unbuf(i));
        buf_pprodd : generic_register generic map(pprod_size) port map(clock, reset_n, pprod_unbuf(i), '1', pprod(i));
  end generate;
  -- Terms concatenation
  pprod_concat(ext_bias'range) <= ext_bias;
  concat_terms: for i in num_terms-1 downto 0 generate
    pprod_concat(pprod_concat'left-(i*pprod_size) downto pprod_concat'left-((i+1)*pprod_size)+1) <= pprod(i);
  end generate;
  -- Sum reduction
  reduct : sum_reduct
    generic map(num_terms_2, pprod_size, add_approx_degree)
    port map (clock, reset_n, pprod_concat, sum);
end structural;


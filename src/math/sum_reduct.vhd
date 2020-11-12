library ieee;
use ieee.std_logic_1164.all;
library work;
use work.utils.all;

entity sum_reduct is
  generic (
    noperands     : natural;                                                -- number of operand to be summed
    data_size     : natural;                                               -- size of each operand
    approx_degree : natural);
  port (
    clk     : in  std_logic;                                                -- clock
    rst_n   : in  std_logic;                                                -- reset (active low)
    inputs  : in  std_logic_vector ((noperands * data_size)-1 downto 0);    -- operands (concatenated)
    sum     : out std_logic_vector (data_size+log2(noperands)-1 downto 0)); -- sum of the operands
end sum_reduct;

architecture structural of sum_reduct is
  constant tree_depth     : natural := log2(noperands);                      -- depth of the sum-reduct tree
  constant final_sum_size : natural := data_size+tree_depth;                 -- final data lenght of the sum
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
  -- type to hold partial sums 
  type psum_t is array (natural range <>, natural range <>) of std_logic_vector (final_sum_size-1 downto 0);
  signal psum : psum_t (0 to tree_depth, 0 to noperands-1) := (others => (others => (others => '0')));
begin
  input_assign: for i in 0 to noperands-1 generate
    psum(0, i)(data_size-1 downto 0) <= inputs(inputs'left-(i*data_size) downto inputs'left-((i+1)*data_size)+1); -- actual-signal
    psum(0, i)(final_sum_size-1 downto data_size) <= (others => inputs(inputs'left-(i*data_size)));                -- sign extension
  end generate;
  sum_tree : for level in 0 to tree_depth-1 generate
    sum_row : for i in 0 to noperands/(2**(level+1))-1 generate
      add: piped_adder
        generic map(final_sum_size, approx_degree)
        port map(clk, rst_n, psum(level, 2*i), psum(level, 2*i+1), '0', psum(level+1, i), open, open);
    end generate;
  end generate;
  sum <= psum(tree_depth, 0);
end structural;

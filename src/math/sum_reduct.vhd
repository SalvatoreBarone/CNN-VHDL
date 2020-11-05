library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


entity sum_row is
  generic (
    noperands : natural;
    data_size : natural);
  port (
    inputs  : in std_logic_vector (noperands*data_size-1 downto 0);
    outputs : out std_logic_vector (noperands/2*(data_size+1)-1 downto 0));
end sum_row;

architecture structural of sum_row is
  component adder is
    generic (
      data_size	  	: natural := 16);
    port (
  		add_1 		: in   std_logic_vector (data_size-1 downto 0);
  		add_2 		: in   std_logic_vector (data_size-1 downto 0);
  		sub_add_n	: in   std_logic;
  		sum 		  : out  std_logic_vector (data_size-1 downto 0);
  		carry_out	: out  std_logic;
  		overflow 	: out  std_logic);
  end component;
begin
  add_loop : for i in 0 to noperands/2-1 generate
    add: adder 
      generic map (data_size)
      port map (
			  inputs ((2*i+1)*data_size-1 downto 2*i*data_size),
			  inputs ((2*i+2)*data_size-1 downto (2*i+1)*data_size),
				'0',
        outputs(i*(data_size+1)+data_size-1 downto i*(data_size+1)),
        outputs(i*(data_size+1)+data_size),
        open);
  end generate;
end structural;

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
library work;
use work.utils.all;

entity sum_reduct is
  generic (
    noperands : natural;                                                    -- number of operand to be summed
    data_size : natural);                                                   -- size of each operand
  port (
		clk     : in std_logic;                                                 -- clock
		rst_n   : in std_logic;                                                 -- reset (active low)
    inputs  : in std_logic_vector ((noperands * data_size)-1 downto 0);     -- operands (concatenated)
		sum     : out std_logic_vector (data_size+log2(noperands)-1 downto 0));
end sum_reduct;

architecture structural of sum_reduct is
  component generic_register is
  	generic(
  		data_size : natural := 16
  	);
  	port (
  		clk  : in std_logic;
  		rst_n  : in std_logic;
  		data_in : in std_logic_vector (data_size-1 downto 0);
  		en : in std_logic;
  		data_out : out std_logic_vector (data_size-1 downto 0)
  	);
  end component;
  component sum_row is
    generic (
      noperands : natural;
      data_size : natural);
    port (
	    inputs  : in std_logic_vector (noperands*data_size-1 downto 0);
	    outputs : out std_logic_vector (noperands/2*(data_size+1)-1 downto 0));
  end component;
	type slv_matrix is array(natural range <>)of std_logic_vector(noperands * data_size-1 downto 0);
	signal buffer_in : slv_matrix(log2(noperands) downto 0);
	signal adder_in : slv_matrix(log2(noperands)-1 downto 0);
begin
  buffer_in(log2(noperands)) <= inputs;
	blocks : for level in log2(noperands)-1 downto 0 generate
    pipe_buff : generic_register
  		generic map((2**(level+1)) * (data_size+log2(noperands)-level-1))
  		port map	(	
  			clk,
  			rst_n,
				buffer_in(level+1)((data_size+log2(noperands)-level-1)*(2**(level+1))-1 downto 0),
				'1',
  			adder_in(level)((data_size+log2(noperands)-level-1)*(2**(level+1))-1 downto 0));
		add_row : sum_row
  		generic map	(noperands => 2**(level+1),	data_size => data_size+log2(noperands)-level-1)
  		port map (
  			 adder_in(level)( (data_size+log2(noperands)-level-1)*(2**(level + 1))-1 downto 0),
  			 buffer_in(level)((2**level)*(data_size+log2(noperands)-level)-1 downto 0));
	end generate;
	sum <= buffer_in(0)(data_size+log2(noperands)-1 downto 0);
end structural;

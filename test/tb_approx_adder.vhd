library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use std.textio.all;
use ieee.std_logic_textio.all;

library work;
use work.utils.all;
use work.debug_func.all;
 
entity tb_approx_adder is
end tb_approx_adder;
 
architecture behavioral of tb_approx_adder is 
	component adder is
    generic (
      data_size     : natural;
      approx_degree : natural);
		port (
				add_1 		: in   std_logic_vector (data_size-1 downto 0);
				add_2 		: in   std_logic_vector (data_size-1 downto 0);
				sub_add_n	: in   std_logic;
				sum 		  : out  std_logic_vector (data_size-1 downto 0);
				carry_out	: out  std_logic;
				overflow 	: out  std_logic);
	end component;
  constant data_size     : natural := 8;
  type     slv_array_t is array (natural range <>) of std_logic_vector (data_size-1 downto 0);

	signal   add_1         : std_logic_vector (data_size-1 downto 0) := (others => '0');
	signal   add_2         : std_logic_vector (data_size-1 downto 0) := (others => '0');
	signal   sub_add_n     : std_logic := '0';
  signal   sum           : slv_array_t(0 to data_size-2)  := (others => (others => '0'));
  file     test_oracle                          : text;
begin
  uuts : for i in 0 to data_size-2 generate 
    uut : adder
		  generic map(data_size, i)
		  port map (add_1, add_2, sub_add_n, sum(i), open, open);
	end generate; 

	stim_proc: process
    variable rline              : line;
    variable space              : character;
    variable read_add_1         : std_logic_vector (data_size-1 downto 0);
    variable read_add_2         : std_logic_vector (data_size-1 downto 0);
    variable read_sum           : slv_array_t(0 to data_size-2) := (others => (others => '0'));
	begin		
		wait for 10 ns;	
		-- prova in addizione
		sub_add_n <= '0';
    file_open(test_oracle, "../test/tb_approx_adder_oracle.txt", read_mode);
    while not endfile(test_oracle) loop
      readline(test_oracle, rline);
      read(rline, read_add_1);
      read(rline, space);
      read(rline, read_add_2);
      add_1 <= read_add_1;
      add_2 <= read_add_2;
      wait for 10 ns;
      for i in 0 to data_size-2 loop
        read(rline, space);
        read(rline, read_sum(i));
        assert sum(i) = read_sum(i) report "Error! apprx.degree=" & integer'image(i) & ": add1=" & vec_image(add_1) & " add2=" & vec_image(add_2) & " sum=" & vec_image(sum(i)) & " expected=" & vec_image(read_sum(i)) severity failure;
      end loop;
    end loop;
	wait;
	end process;
end;

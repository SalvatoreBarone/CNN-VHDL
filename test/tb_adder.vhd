library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library work;
use work.utils.all;
use work.debug_func.all;
 
entity tb_adder is
end tb_adder;
 
architecture behavioral of tb_adder is 

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
  constant approx_degree : natural := 0;  
	signal   add_1         : std_logic_vector (data_size-1 downto 0);
	signal   add_2         : std_logic_vector (data_size-1 downto 0);
	signal   sub_add_n     : std_logic;
	signal   sum           : std_logic_vector (data_size-1 downto 0);
	
begin

	uut : adder
		generic map( data_size, approx_degree)
		port map (add_1, add_2, sub_add_n, sum, open, open);
	
	-- stimulus process
	stim_proc: process
		variable test_sum : integer;
	begin		
		wait for 10 ns;	
		-- prova in addizione
		sub_add_n <= '0';
    for i in -2**(data_size-1) to 2**(data_size-1)-1 loop
      add_1 <= std_logic_vector(to_signed(i, data_size));
      for j in -2**(data_size-1) to 2**(data_size-1)-1 loop
        add_2 <= std_logic_vector(to_signed(j, data_size));
				test_sum := i + j;
				wait for 20 ns;
        assert sum = std_logic_vector(to_signed(test_sum, data_size)) report "Errore calcolo somma in somma con i=" & integer'image(i) & " j=" & integer'image(j) & " sum=" & vec_image(sum) & " expected: " & integer'image(test_sum) severity failure;
			end loop;
		end loop;
		-- prova in sottrazione
		sub_add_n <= '1';
    for i in -2**(data_size-1) to 2**(data_size-1)-1 loop
      add_1 <= std_logic_vector(to_signed(i, data_size));
      for j in -2**(data_size-1) to 2**(data_size-1)-1 loop
        add_2 <= std_logic_vector(to_signed(j, data_size));
				test_sum := i - j;
				wait for 20 ns;
        assert   sum = std_logic_vector(to_signed(test_sum, data_size)) report "Errore calcolo somma in sottrazione con i=" & integer'image(i) & " j=" & integer'image(j) & " sum=" & vec_image(sum) & " expected: " & integer'image(test_sum) severity failure;
			end loop;
		end loop;
	wait;
	end process;
end;

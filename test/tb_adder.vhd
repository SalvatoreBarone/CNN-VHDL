library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
 
entity tb_adder is
end tb_adder;
 
architecture behavioral of tb_adder is 

	component adder is
		generic (
				data_size		: natural := 4
		);
		
		port (
				add_1 		: in   std_logic_vector (data_size-1 downto 0);
				add_2 		: in   std_logic_vector (data_size-1 downto 0);
				sub_add_n	: in   std_logic;
				sum 		  : out  std_logic_vector (data_size-1 downto 0);
				carry_out	: out  std_logic;
				overflow 	: out  std_logic
		);
	end component;
	
	signal add_1 : 			std_logic_vector (7 downto 0);
	signal add_2 :		 	std_logic_vector (7 downto 0);
	signal sub_add_n : 	std_logic;
	signal sum : 		std_logic_vector (7 downto 0);
	signal overflow : 	std_logic;
	
begin

	uut : adder
		generic map( data_size => 8 )
		port map (
			add_1 => add_1,
			add_2 => add_2,
			sub_add_n => sub_add_n,
			sum => sum,
			overflow => overflow);
	
	-- stimulus process
	stim_proc: process
		variable test_sum : integer;
	begin		

		wait for 10 ns;	
		
		-- prova in addizione
		sub_add_n <= '0';
		for i in -128 to 127 loop
			add_1 <= std_logic_vector(to_signed(i, 8));
			for j in -128 to 127 loop
				add_2 <= std_logic_vector(to_signed(j, 8));
				
				test_sum := i + j;

				wait for 20 ns;
				
				assert 	sum = std_logic_vector(to_signed(test_sum, 8))
					report "Errore calcolo somma in somma con i=" & integer'image(i) & " j=" & integer'image(j)
					severity failure;
				
			end loop;
		end loop;
		
		
		-- prova in sottrazione
		sub_add_n <= '1';
		for i in -128 to 127 loop
			add_1 <= std_logic_vector(to_signed(i, 8));
			for j in -128 to 127 loop
				add_2 <= std_logic_vector(to_signed(j, 8));
				
				test_sum := i - j;
				
				wait for 20 ns;
				
				assert 	sum = std_logic_vector(to_signed(test_sum, 8))
					report "Errore calcolo somma in sottrazione con i=" & integer'image(i) & " j=" & integer'image(j)
					severity failure;
				
			end loop;
		end loop;
		
	wait;
	end process;

end;

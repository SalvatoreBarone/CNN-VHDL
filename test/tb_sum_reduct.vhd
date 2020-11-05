library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library work;
use work.utils.all;
use work.debug_func.all;

entity tb_sum_reduct is
end tb_sum_reduct;

--! @test Testbench esaustivo per sum_reduct con parametri:
--! - noperands = 4
--! - data_size = 4 
--!
architecture tb_sum_reduct of tb_sum_reduct is

	component sum_reduct is
	  generic (
	    noperands : natural;                                                    -- number of operand to be summed
	    data_size : natural);                                                   -- size of each operand
	  port (
			clk     : in std_logic;                                                 -- clock
			rst_n   : in std_logic;                                                 -- reset (active low)
	    inputs  : in std_logic_vector ((noperands * data_size)-1 downto 0);     -- operands (concatenated)
			sum     : out std_logic_vector (data_size+log2(noperands)-1 downto 0));
	end component;

	constant clock_period : time := 10 ns;
	constant noperands : natural := 4;
	constant data_size : natural := 4;

	signal clk : std_logic := '0';
	signal reset_n : std_logic := '0';
	signal data_in : std_logic_vector ((noperands * data_size)-1 downto 0) :=	(others => '0');
	signal data_out : std_logic_vector (data_size+log2(noperands)-1 downto 0) := (others => '0');
	signal data_out_test : std_logic_vector (data_size+log2(noperands)-1 downto 0) := (others => '0');

	----------------------------------------------------------------------------
	-- Segnale usato per segnalare la fine del test
	signal simulate : std_logic := '1';

begin

	----------------------------------------------------------------------------
	-- Process per la generazione del segnale di clock
	-- Nota: rispetto alla forma classica, questa forma di process serve ad
	-- evitare che GHDL vada in freeze al termine del test.
	clock_process : process
	begin
		while simulate = '1' loop
			clk <= not clk;
			wait for clock_period / 2;
		end loop;
		wait;
	end process clock_process;

	----------------------------------------------------------------------------
	-- Istanza del componente sotto test
	uut : sum_reduct
		generic map (noperands, data_size)
		port map (clk, reset_n, data_in, data_out);

	----------------------------------------------------------------------------
	-- Process di test
	stim_process : process
		variable sum : integer := 0;
	begin

		reset_n <= '0', '1' after 5*clock_period;
		wait for 7*clock_period;
		
		for op_3 in 0 to 2**data_size -1 loop
			for op_2 in 0 to 2**data_size -1 loop
				for op_1 in 0 to 2**data_size -1 loop
					for op_0 in 0 to 2**data_size -1 loop

					data_in <= 	std_logic_vector(to_unsigned(op_3, data_size)) &
								std_logic_vector(to_unsigned(op_2, data_size)) &
								std_logic_vector(to_unsigned(op_1, data_size)) &
								std_logic_vector(to_unsigned(op_0, data_size));

					sum := op_0 + op_1 + op_2 + op_3;
					data_out_test <= 
						std_logic_vector(to_unsigned(sum, data_size+log2(noperands)));

					wait for (log2(noperands)+1)*clock_period;

					assert data_out = data_out_test
					report	"Errore!"
							& " op_3=" & integer'image(op_3)
							& " op_2=" & integer'image(op_2)
							& " op_1=" & integer'image(op_1)
							& " op_0=" & integer'image(op_0)
							& " sum= " & integer'image(sum)
							& " data_out= " & vec_image(data_out)
							& " data_out_test= " & vec_image(data_out_test)
					severity failure;

					end loop;
				end loop;
			end loop;		
		end loop;

		simulate <= '0';
		report "Test completato con successo" severity note;
		wait;
	end process;

end architecture;

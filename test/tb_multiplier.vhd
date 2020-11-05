library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_multiplier is
end tb_multiplier;

architecture behavior of tb_multiplier is

	component multiplier
    generic (nbits : integer := 8);
    port (	x		: in std_logic_vector(nbits-1 downto 0);
        y		: in std_logic_vector(nbits-1 downto 0);
        prod	: out std_logic_vector ((2*nbits)-1 downto 0)
    );
	end component;

--	for all : multiplier use entity work.booth_multiplier(structural);


	--Inputs
	signal X : std_logic_vector(7 downto 0) := (others => '0');
	signal Y : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
	signal Prod : std_logic_vector(15 downto 0);

	-- Clock period definitions
	constant clock_period : time := 10 ns;

BEGIN

	-- Instantiate the Unit Under Test (UUT)
	uut: multiplier
		port map (
			x 				=> x,
			y 				=> y,
			prod 			=> prod
		);


	-- Stimulus process
	stim_proc: process
		variable test_prod : integer := 0;
		variable test_prod_stdlv : std_logic_vector(15 downto 0);
		variable error_cnt : integer := 0;
	begin
		wait for 100 ns;

		for i in -128 to 127 loop
			X <= std_logic_vector(to_signed(i, 8));
			for j in -128 to 127 loop
				Y <= std_logic_vector(to_signed(j,8));
				test_prod := i * j;
				test_prod_stdlv := std_logic_vector(to_signed(test_prod, 16));

				wait for clock_period;

				assert (Prod = test_prod_stdlv)
					report
						"Errore di calcolo con "
						& "i (x) =" & integer'image(i) & " ("
						& std_logic'image(X(7)) & std_logic'image(X(6)) & std_logic'image(X(5)) & std_logic'image(X(4))
						& std_logic'image(X(3)) & std_logic'image(X(2)) & std_logic'image(X(1)) & std_logic'image(X(0))
						& "), j (y) =" & integer'image(j) & " ("
						& std_logic'image(Y(7)) & std_logic'image(Y(6)) & std_logic'image(Y(5)) & std_logic'image(Y(4))
						& std_logic'image(Y(3)) & std_logic'image(Y(2)) & std_logic'image(Y(1)) & std_logic'image(Y(0))
						& "), prod ="
						& std_logic'image(Prod(15)) & std_logic'image(Prod(14)) & std_logic'image(Prod(13)) & std_logic'image(Prod(12))
						& std_logic'image(Prod(11)) & std_logic'image(Prod(10)) & std_logic'image(Prod(9)) & std_logic'image(Prod(8))
						& std_logic'image(Prod(7)) & std_logic'image(Prod(6)) & std_logic'image(Prod(5)) & std_logic'image(Prod(4))
						& std_logic'image(Prod(3)) & std_logic'image(Prod(2)) & std_logic'image(Prod(1)) & std_logic'image(Prod(0))
						& ", test_prod ="
						& std_logic'image(test_prod_stdlv(15)) & std_logic'image(test_prod_stdlv(14)) & std_logic'image(test_prod_stdlv(13)) & std_logic'image(test_prod_stdlv(12))
						& std_logic'image(test_prod_stdlv(11)) & std_logic'image(test_prod_stdlv(10)) & std_logic'image(test_prod_stdlv(9)) & std_logic'image(test_prod_stdlv(8))
						& std_logic'image(test_prod_stdlv(7)) & std_logic'image(test_prod_stdlv(6)) & std_logic'image(test_prod_stdlv(5)) & std_logic'image(test_prod_stdlv(4))
						& std_logic'image(test_prod_stdlv(3)) & std_logic'image(test_prod_stdlv(2)) & std_logic'image(test_prod_stdlv(1)) & std_logic'image(test_prod_stdlv(0))
					severity error;

				if (Prod /= test_prod_stdlv) then
					error_cnt := error_cnt + 1;
				end if;

			end loop;
		end loop;

		assert false
			report "Si sono verificati " & integer'image(error_cnt) & " errori"
			severity note;

		wait;
	end process;

end behavior;

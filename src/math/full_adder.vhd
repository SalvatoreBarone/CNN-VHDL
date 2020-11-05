library ieee;
use ieee.std_logic_1164.all;

entity full_adder is
    port (	add_1		: in std_logic;
			add_2		: in std_logic;
			carry_in	: in std_logic;
			carry_out	: out std_logic;
			sum			: out std_logic
	);
end full_adder;

architecture structural of full_adder is
begin
	carry_out <= (add_1 and add_2 ) or (carry_in and add_1) or (carry_in and add_2);
	sum <= add_1 xor add_2 xor carry_in;
end structural;

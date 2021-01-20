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
use ieee.std_logic_arith.all;  
use ieee.std_logic_signed.all;
use ieee.math_real.all;

package debug_func is
	function vec_image(arg : std_logic_vector) return string;
	shared variable seed1:integer:=844396720; -- uniform procedure seed1  
	shared variable seed2:integer:=821616997; -- uniform procedure seed2  
	impure function random(lower_value : integer; upper_value : integer) return integer;  
end package;

package body debug_func is

	----------------------------------------------------------------------------
	-- Funzione di stampa per std_logic_vector
	function vec_image(arg : std_logic_vector) return string is 
		constant arg_norm : std_logic_vector(1 to arg'length) := arg; 
		constant center : natural := 2; 
		variable just_the_number : character;
		variable bit_image : string(1 to 3); 
    begin 
		if (arg'length > 0) then 
			bit_image := std_logic'image(arg_norm(1));
			just_the_number := bit_image(center);
			return just_the_number & vec_image(arg_norm(2 to arg_norm'length));
		else 
			return ""; 
		end if; 
    end function vec_image; 

	----------------------------------------------------------------------------
	-- Funzione di generazione di numero pseudo-casuali
	impure function random (lower_value : integer;  upper_value : integer) return integer is  
		variable result : integer;  
		variable tmp_real : real; -- return value from uniform procedure --  
	begin  
		uniform(seed1,seed2,tmp_real);  
		result := integer(trunc((tmp_real * real(upper_value - lower_value)) + real(lower_value)));  
		return result;
	end function random;  
	
end package body;

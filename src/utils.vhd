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
use ieee.numeric_std.all;


package utils is
  function int_max(left, right: integer) return integer; 
  function int_min(left, right: integer) return integer;
  function log2(i: natural) return integer;
end package;

package body utils is

  function int_max(left, right: integer) return integer is
  begin
    if left > right then return left;
    else return right;
    end if;
  end;

  function int_min(left, right: integer) return integer is
  begin
    if left < right then return left;
    else return right;
    end if;
  end;

  function log2(i: natural) return integer is
		variable temp   : integer:= i;
		variable ret_val: integer:= 0; 
	begin					
		while temp > 1 loop
			ret_val:= ret_val + 1;
			temp   := temp / 2;     
		end loop;
		return ret_val;
	end function;

end package body;

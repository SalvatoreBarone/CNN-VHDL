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
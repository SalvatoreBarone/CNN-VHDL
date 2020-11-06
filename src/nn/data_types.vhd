library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library work;
use work.config.all;

package data_types is
  constant data_size : natural := 16;

  type data_vector is array (natural range<>) of std_logic_vector(data_size-1 downto 0);  
  type data_matrix is array (natural range <>, natural range <>) of std_logic_vector (data_size-1 downto 0);
  type data_volume is array(natural range <>, natural range <>, natural range <>) of std_logic_vector(data_size-1 downto 0);
	type data_hypervolume is array (natural range <>, natural range <>, natural range <>, natural range <>) of std_logic_vector(data_size -1 downto 0);
end package;
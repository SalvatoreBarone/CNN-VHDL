library ieee;
use ieee.std_logic_1164.all;

entity wired_shift is
  generic (
    data_size : natural;
    shift     : integer);
  port (
    data_in   : in std_logic_vector(data_size-1 downto 0);
    data_out  : out std_logic_vector(data_size-1 downto 0));
end entity;

architecture data_flow of wired_shift is
begin
  -- if shift > 0 then sum >>= shift
  right_shift : if shift > 0 generate
    data_out(data_out'left downto data_out'left-shift+1) <= (others => data_in(data_in'left)); -- sign preservation
    data_out(data_out'left-shift downto 0) <= data_in(data_in'left downto shift);
  end generate;

  -- if shift < 0 sum <<= -shift
  left_shift : if shift < 0 generate
    data_out(-shift-1 downto 0) <= (others => '0');
    data_out(data_out'left downto -shift) <= data_in(data_in'left+shift downto 0);    
  end generate;

  -- no shift 
  no_shift : if shift = 0 generate
    data_out <= data_in;
  end generate;
end data_flow;

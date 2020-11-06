package activation_functions is
  type activation_t is (rect, linear);
end package;

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.activation_functions.all;

entity activation is
  generic (
    kind                : activation_t := rect;
    actual_data_size    : natural;
    final_data_size     : natural;
    shift               : natural);
  port (
    data_in   : in std_logic_vector(actual_data_size-1 downto 0);
    data_out  : out std_logic_vector(final_data_size-1 downto 0));
end entity;

architecture data_flow of activation is
  signal zero           : std_logic_vector (final_data_size-1 downto 0) := (others => '0');
  signal linear_result  : std_logic_vector (final_data_size-1 downto 0) := (others => '0');
  signal rect_result    : std_logic_vector (final_data_size-1 downto 0) := (others => '0');
begin
  -- Computing linear
  linear_result <= data_in(final_data_size-1 downto 0);
  -- Computing rect
  with data_in(actual_data_size-1) select
    rect_result <= '0' & data_in(final_data_size-2 downto 0) when '0',
                   zero when others;
  -- Computing the final outcome
  with kind select
    data_out <= linear_result when linear,
                rect_result when rect;
end data_flow;

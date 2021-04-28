library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity evo_mul16s is
  generic (axcomponent : natural := 0);
  port (
    clock         : in std_logic;
    reset_n       : in std_logic;
    x             : in  std_logic_vector(15 downto 0);
    y             : in  std_logic_vector(15 downto 0);
    prod          : out std_logic_vector (31 downto 0));
end evo_mul16s;

architecture structural of evo_mul16s is
    component generic_register is
        generic(data_size : natural := 16);
        port (
          clk      : in  std_logic;
          rst_n    : in  std_logic;
          data_in  : in  std_logic_vector (data_size-1 downto 0);
          en       : in  std_logic;
          data_out : out std_logic_vector (data_size-1 downto 0));
    end component;
    component mul16s_G7F is
        port(   A : in  std_logic_vector (15 downto 0);
                B : in  std_logic_vector (15 downto 0);
                O : out std_logic_vector (31 downto 0));
    end component;
    component mul16s_G7Z is
        port(   A : in  std_logic_vector (15 downto 0);
                B : in  std_logic_vector (15 downto 0);
                O : out std_logic_vector (31 downto 0));
    end component;
    component mul16s_G80 is
        port(   A : in  std_logic_vector (15 downto 0);
                B : in  std_logic_vector (15 downto 0);
                O : out std_logic_vector (31 downto 0));
    end component;
    component mul16s_GAT is
        port(   A : in  std_logic_vector (15 downto 0);
                B : in  std_logic_vector (15 downto 0);
                O : out std_logic_vector (31 downto 0));
    end component;
    component mul16s_GK2 is
        port(   A : in  std_logic_vector (15 downto 0);
                B : in  std_logic_vector (15 downto 0);
                O : out std_logic_vector (31 downto 0));
    end component;

    component mul16s_HDG is
        port(   A : in  std_logic_vector (15 downto 0);
                B : in  std_logic_vector (15 downto 0);
                O : out std_logic_vector (31 downto 0));
    end component;
    component mul16s_HEB is
        port(   A : in  std_logic_vector (15 downto 0);
                B : in  std_logic_vector (15 downto 0);
                Z : out std_logic_vector (31 downto 0));
    end component;
    component mul16s_HFZ is
        port(   A : in  std_logic_vector (15 downto 0);
                B : in  std_logic_vector (15 downto 0);
                O : out std_logic_vector (31 downto 0));
    end component;
    component mul16s_HHP is
        port(   A : in  std_logic_vector (15 downto 0);
                B : in  std_logic_vector (15 downto 0);
                Z : out std_logic_vector (31 downto 0));
    end component;
    signal prod_unbuff : std_logic_vector (31 downto 0) := (others => '0');
begin
    assert axcomponent < 10;
    mul_buf : generic_register generic map (32) port map (clock, reset_n, prod_unbuff, '1', prod); 
    exact_cell : if axcomponent = 0 generate prod_unbuff <= signed(x) * signed(y); end generate;
    G7F_cell   : if axcomponent = 9 generate mul_cell : mul16s_G7F port map (x, y,prod_unbuff); end generate;
    G7Z_cell   : if axcomponent = 8 generate mul_cell : mul16s_G7Z port map (x, y,prod_unbuff); end generate;
    G80_cell   : if axcomponent = 7 generate mul_cell : mul16s_G80 port map (x, y,prod_unbuff); end generate;
    GK2_cell   : if axcomponent = 6 generate mul_cell : mul16s_GK2 port map (x, y,prod_unbuff); end generate;
    GAT_cell   : if axcomponent = 4 generate mul_cell : mul16s_GAT port map (x, y,prod_unbuff); end generate;
    HDG_cell   : if axcomponent = 2 generate mul_cell : mul16s_HDG port map (x, y,prod_unbuff); end generate;
    HEB_cell   : if axcomponent = 1 generate mul_cell : mul16s_HEB port map (x, y,prod_unbuff); end generate;
    HFZ_cell   : if axcomponent = 3 generate mul_cell : mul16s_HFZ port map (x, y,prod_unbuff); end generate;
    HHP_cell   : if axcomponent = 5 generate mul_cell : mul16s_HHP port map (x, y,prod_unbuff); end generate;
end structural;
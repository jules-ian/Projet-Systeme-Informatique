----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/26/2024 01:11:24 PM
-- Design Name: 
-- Module Name: Test_ALU - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Test_ALU is
--  Port ( );
end Test_ALU;

architecture Behavioral of Test_ALU is
    component ALU 
    port(
           A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           S : out STD_LOGIC_VECTOR (7 downto 0);
           opCode : in STD_LOGIC_VECTOR (2 downto 0);
           C : out STD_LOGIC;
           O : out STD_LOGIC;
           Z : out STD_LOGIC;
           N : out STD_LOGIC
    );
    end component;
    
    for all : ALU use entity work.ALU(Behavioral);
    

signal A : STD_LOGIC_VECTOR (7 downto 0);
signal B : STD_LOGIC_VECTOR (7 downto 0);
signal S : STD_LOGIC_VECTOR (7 downto 0);
signal opCode : STD_LOGIC_VECTOR (2 downto 0);
signal C : STD_LOGIC;
signal O : STD_LOGIC;
signal Z : STD_LOGIC;
signal N : STD_LOGIC;
    
begin

ALU_test : ALU port map(A=>A, B=>B, S=>S, opCode=>opCode, C=>C, O=>O, Z=>Z, N=>N);
A <= "01010101";-- 85 = 0x55 --, "00000001" after 40ns;
B <= "01010101"; -- 15 = 0x0F--, "10000001" after 40ns;
opCode <= "000", "001" after 40ns, "010" after 80ns, "011" after 120ns, "100" after 160ns, "101" after 200ns, "110" after 240ns, "111" after 280ns;

end Behavioral;

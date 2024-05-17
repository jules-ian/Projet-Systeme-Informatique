----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/06/2024 12:53:59 PM
-- Design Name: 
-- Module Name: Test_Instruction_memory - Behavioral
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

entity Test_Instruction_memory is
--  Port ( );
end Test_Instruction_memory;

architecture Behavioral of Test_Instruction_memory is
component Instruction_memory
    Port ( 
           Address : in STD_LOGIC_VECTOR (7 downto 0);
           Clock : in STD_LOGIC;
           ValOut : out STD_LOGIC_VECTOR (31 downto 0));
    end component;
    
    for all : Instruction_memory use entity work.Instruction_memory(Behavioral);
    
constant Clock_period : time := 10ns;
signal Clock : std_logic := '0';
signal Address : STD_LOGIC_VECTOR (7 downto 0);
signal ValOut : STD_LOGIC_VECTOR (31 downto 0);

begin

Instruction_memory_test : Instruction_memory port map(Address=>Address, Clock=>Clock, ValOut=>ValOut);

clk_process: process
begin
    while true loop
        Clock <= not Clock; 
        wait for Clock_period / 2; 
    end loop;
end process;

Address <= "00000001", "00000011" after 160ns; 




end Behavioral;

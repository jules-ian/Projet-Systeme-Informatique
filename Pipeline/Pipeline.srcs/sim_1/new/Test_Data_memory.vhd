----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/06/2024 12:53:59 PM
-- Design Name: 
-- Module Name: Test_Data_memory - Behavioral
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

entity Test_Data_memory is
--  Port ( );
end Test_Data_memory;

architecture Behavioral of Test_Data_memory is
component Data_memory
    Port ( 
           Address : in STD_LOGIC_VECTOR (7 downto 0);
           Data : in STD_LOGIC_VECTOR (7 downto 0);
           RW : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Clock : in STD_LOGIC;
           ValOut : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    for all : Data_memory use entity work.Data_memory(Behavioral);
    
constant Clock_period : time := 10ns;
signal Clock : std_logic := '0';
signal Address : STD_LOGIC_VECTOR (7 downto 0);
signal Data : STD_LOGIC_VECTOR (7 downto 0);
signal RW : STD_LOGIC;
signal Reset : STD_LOGIC;
signal ValOut : STD_LOGIC_VECTOR (7 downto 0);

begin

Data_memory_test : Data_memory port map(Address=>Address, Data=>Data, RW=>RW, Reset=>Reset, Clock=>Clock, ValOut=>ValOut);

clk_process: process
begin
    while true loop
        Clock <= not Clock; 
        wait for Clock_period / 2; 
    end loop;
end process;

Address <= "00000001"; 
RW <= '1', '0' after 40ns, '1' after 60ns;
Data <= "01010101";
Reset <= '0', '1' after 20ns;


end Behavioral;

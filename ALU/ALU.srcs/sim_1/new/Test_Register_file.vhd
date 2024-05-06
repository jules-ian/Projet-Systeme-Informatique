----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/06/2024 12:53:59 PM
-- Design Name: 
-- Module Name: Test_Register_file - Behavioral
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

entity Test_Register_file is
--  Port ( );
end Test_Register_file;

architecture Behavioral of Test_Register_file is
 component Register_file
    port(
           AddressA : in STD_LOGIC_VECTOR (3 downto 0);
           AddressB : in STD_LOGIC_VECTOR (3 downto 0);
           AddressWrite : in STD_LOGIC_VECTOR (3 downto 0);
           Write : in STD_LOGIC;
           Data : in STD_LOGIC_VECTOR (7 downto 0);
           Reset : in STD_LOGIC;
           Clock : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    for all : Register_file use entity work.Register_file(Behavioral);
    
constant Clock_period : time := 10ns;
signal Clock : std_logic := '0';
signal AddressA : STD_LOGIC_VECTOR (3 downto 0);
signal AddressB : STD_LOGIC_VECTOR (3 downto 0);
signal AddressWrite : STD_LOGIC_VECTOR (3 downto 0);
signal Write : STD_LOGIC;
signal Data : STD_LOGIC_VECTOR (7 downto 0);
signal Reset : STD_LOGIC;
signal QA : STD_LOGIC_VECTOR (7 downto 0);
signal QB : STD_LOGIC_VECTOR (7 downto 0);

begin

Register_file_test : Register_file port map(AddressA=>AddressA, AddressB=>AddressB, AddressWrite=>AddressWrite, Write=>Write, Data=>Data, Reset=>Reset, Clock=>Clock, QA=>QA, QB=>QB);

clk_process: process
begin
    while true loop
        Clock <= not Clock; 
        wait for Clock_period / 2; 
    end loop;
end process;

AddressA <= "0001"; 
AddressB <= "1111";
AddressWrite <= "0001";
Write <= '1', '0' after 40ns;
Data <= "01010101";
Reset <= '0', '1' after 20ns;

end Behavioral;

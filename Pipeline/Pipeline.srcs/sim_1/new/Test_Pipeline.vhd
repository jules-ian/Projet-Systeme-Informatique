----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/22/2024 08:04:24 AM
-- Design Name: 
-- Module Name: Test_Pipeline - Behavioral
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Test_Pipeline is
--  Port ( );
end Test_Pipeline;

architecture Behavioral of Test_Pipeline is
component Pipeline
    Port ( CLK : in std_logic );
           end component;

    for all : Pipeline use entity work.Pipeline(Structural);
    
constant Clock_period : time := 10ns; 
signal Clock : std_logic := '0';

begin


Pipeline_test : Pipeline port map(CLK=>Clock);


clk_process: process

begin
    while true loop
        Clock <= not Clock; 
        wait for Clock_period / 2; 
    end loop;
end process;


end Behavioral;

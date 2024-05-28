----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/29/2024 11:06:47 AM
-- Design Name: 
-- Module Name: Memory_file - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Data_memory is 
    Port ( 
           Address : in STD_LOGIC_VECTOR (7 downto 0);
           Data : in STD_LOGIC_VECTOR (7 downto 0);
           RW : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Clock : in STD_LOGIC;
           ValOut : out STD_LOGIC_VECTOR (7 downto 0));
           
end Data_memory;

architecture Behavioral of Data_memory is
    
    constant DATA_MEMORY_SIZE : natural := 255;
    type data_memory_array is array (natural range <>) of std_logic_vector(7 downto 0);
    signal data_memory : data_memory_array(DATA_MEMORY_SIZE downto 0) := (others => x"00");

begin
    process
    begin
    wait until Clock'event and Clock = '0';
    if Reset = '1' then
        if RW = '1' then -- Read
            ValOut <= data_memory(to_integer(unsigned(Address)));
        else -- Write
            data_memory(to_integer(unsigned(Address))) <= Data;
        end if;        
    else
        data_memory <= (others => x"00");
        ValOut <= x"00";
    end if;
    
    end process;
    
end Behavioral;

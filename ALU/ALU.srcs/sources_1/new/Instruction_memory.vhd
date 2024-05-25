----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/29/2024 11:21:57 AM
-- Design Name: 
-- Module Name: Instruction_memory - Behavioral
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

entity Instruction_memory is
    Port ( 
           Address : in STD_LOGIC_VECTOR (7 downto 0);
           Clock : in STD_LOGIC;
           ValOut : out STD_LOGIC_VECTOR (31 downto 0));
           
end Instruction_memory;

architecture Behavioral of Instruction_memory is

    constant INSTRUCTION_MEMORY_SIZE : natural := 255;
    type instruction_memory_array is array (natural range <>) of std_logic_vector(31 downto 0);
    signal instruction_memory : instruction_memory_array(INSTRUCTION_MEMORY_SIZE downto 0) := (others => x"FFFFFFFF");

begin
instruction_memory(0) <= x"09001000"; -- AFC R0 0x10 
instruction_memory(1) <= x"09012100"; -- AFC R1 0x21 
instruction_memory(2) <= x"FFFFFFFF"; -- NOP
instruction_memory(3) <= x"FFFFFFFF"; -- NOP
instruction_memory(4) <= x"FFFFFFFF"; -- NOP
instruction_memory(5) <= x"FFFFFFFF"; -- NOP
instruction_memory(6) <= x"08023200"; -- AFC R2 0x32 
--instruction_memory(6) <= x"08020000"; -- COP R2 R0
-- instruction_memory(2) <= x"00020001"; -- ADD R2 R0 R1
    process
    begin
    wait until Clock'event and Clock = '1';
    
    ValOut <= instruction_memory(to_integer(unsigned(Address)));
    
    end process;
end Behavioral;

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
instruction_memory(0) <= x"FFFFFFFF"; -- NOP 
instruction_memory(1) <= x"09000100"; -- AFC R0 0x01 
instruction_memory(2) <= x"09010200"; -- AFC R1 0x02 
instruction_memory(3) <= x"09020300"; -- AFC R2 0x03 
instruction_memory(4) <= x"09030400"; -- AFC R3 0x04 
instruction_memory(5) <= x"09040500"; -- AFC R4 0x05 
instruction_memory(6) <= x"09050600"; -- AFC R5 0x06 
instruction_memory(7) <= x"09060700"; -- AFC R6 0x07 
instruction_memory(8) <= x"09070800"; -- AFC R7 0x08 
instruction_memory(9) <= x"09080900"; -- AFC R8 0x09 
instruction_memory(10) <= x"09090A00"; -- AFC R9 0x0A 
instruction_memory(11) <= x"090A0B00"; -- AFC R10 0x0B 
instruction_memory(12) <= x"090B0C00"; -- AFC R11 0x0C 
instruction_memory(13) <= x"090C0D00"; -- AFC R12 0x0D 
instruction_memory(14) <= x"090D0E00"; -- AFC R13 0x0E 
instruction_memory(15) <= x"090E0F00"; -- AFC R14 0x0F 
instruction_memory(16) <= x"090F1000"; -- AFC R15 0x10 

instruction_memory(17) <= x"FFFFFFFF"; -- NOP
instruction_memory(18) <= x"FFFFFFFF"; -- NOP
instruction_memory(19) <= x"FFFFFFFF"; -- NOP

instruction_memory(22) <= x"00040001"; -- ADD R4 R0 R1
instruction_memory(23) <= x"00050001"; -- ADD R5 R0 R1
instruction_memory(24) <= x"00060001"; -- ADD R6 R0 R1
instruction_memory(25) <= x"00070001"; -- ADD R7 R0 R1
instruction_memory(26) <= x"00080001"; -- ADD R8 R0 R1
instruction_memory(27) <= x"00090001"; -- ADD R9 R0 R1
-- instruction_memory(2) <= x"00020001"; -- ADD R2 R0 R1
    process
    begin
    wait until Clock'event and Clock = '1';
    
    ValOut <= instruction_memory(to_integer(unsigned(Address)));
    
    end process;
end Behavioral;

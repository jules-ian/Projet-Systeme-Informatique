----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/29/2024 10:17:11 AM
-- Design Name: 
-- Module Name: Register_file - Behavioral
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

entity Register_file is
      Port ( 
           AddressA : in STD_LOGIC_VECTOR (3 downto 0);
           AddressB : in STD_LOGIC_VECTOR (3 downto 0);
           AddressWrite : in STD_LOGIC_VECTOR (3 downto 0);
           Write : in STD_LOGIC;
           Data : in STD_LOGIC_VECTOR (7 downto 0);
           Reset : in STD_LOGIC;
           Clock : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0));
           
end Register_file;

architecture Behavioral of Register_file is

    type register_array is array (natural range <>) of std_logic_vector(7 downto 0);
    signal registers : register_array(15 downto 0) := (others => x"00");

begin
    process 
    begin
    wait until Clock'event and Clock = '0';
    
    if Reset = '1' then
        if Write = '1' then
            if AddressWrite = AddressA then 
                QA <= Data;
            elsif  AddressWrite = AddressB then 
                QB <= Data;
            else
                QA <= registers(to_integer(unsigned(AddressA)));
                QB <= registers(to_integer(unsigned(AddressB)));
            end if;
            registers(to_integer(unsigned(AddressWrite))) <= Data;
        else
            QA <= registers(to_integer(unsigned(AddressA)));
            QB <= registers(to_integer(unsigned(AddressB)));
        end if;
    else
        registers <= (others => x"00");
        QA <= "00000000";
        QB <= "00000000";
    end if;
    
    end process;

end Behavioral;

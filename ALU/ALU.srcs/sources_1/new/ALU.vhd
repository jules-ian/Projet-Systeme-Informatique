----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/04/2024 08:47:12 PM
-- Design Name: 
-- Module Name: ALU - Behavioral
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

entity ALU is
    Port ( --CLK : in std_logic;
           A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           S : out STD_LOGIC_VECTOR (7 downto 0);
           opCode : in STD_LOGIC_VECTOR (2 downto 0);
           C : out STD_LOGIC;
           O : out STD_LOGIC;
           Z : out STD_LOGIC;
           N : out STD_LOGIC);
end ALU;

architecture Behavioral of ALU is
        signal S_ext, A_ext, B_ext : STD_LOGIC_VECTOR(15 downto 0);
        constant OP_add:  STD_LOGIC_VECTOR(2 downto 0) := "000";
        constant OP_sub:  STD_LOGIC_VECTOR(2 downto 0) := "001";
        constant OP_mul:  STD_LOGIC_VECTOR(2 downto 0) := "010";
        constant OP_and:  STD_LOGIC_VECTOR(2 downto 0) := "011";
        constant OP_or:   STD_LOGIC_VECTOR(2 downto 0) := "100";
        constant OP_xor:  STD_LOGIC_VECTOR(2 downto 0) := "101";
        constant OP_notA: STD_LOGIC_VECTOR(2 downto 0) := "110";
	    constant OP_notB: STD_LOGIC_VECTOR(2 downto 0) := "111";
	begin
	    
	    process(A, B, opCode, S_ext, A_ext, B_ext) 
	    begin
	    A_ext <= x"00" & A;
	    B_ext <= x"00" & B;
    case opCode is 
    
        when OP_add => 
            S_ext <= A_ext + B_ext;
            S <= S_ext(7 downto 0);
            if S_ext(15 downto 8) /= x"00" then
                C <= '1';
            else
                C <= '0';
            end if;
            if S_ext(7 downto 0) = x"00" then
                Z <= '1'; 
            else
                Z <= '0';
            end if;
            O <= '0';
            N <= '0';
        
        when OP_sub => 
            S_ext <= A_ext - B_ext;
            S <= S_ext(7 downto 0);
            if B_ext > A_ext then
                N <= '1';
            else
                N <= '0';
            end if;
            if S_ext(7 downto 0) = x"00" then
                Z <= '1'; 
            else
                Z <= '0';
            end if;
            O <= '0';
            C <= '0';
            
        when OP_mul => 
            S_ext <= A * B; 
            S <= S_ext(7 downto 0);
            if S_ext(15 downto 8) /= x"00" then 
                O <= '1';
            else
                O <= '0';
            end if;
            if S_ext(7 downto 0) = x"00" then
                Z <= '1'; 
            else
                Z <= '0';
            end if;
            C <= '0';
            N <= '0';
            
        when OP_and => 
            S_ext <= x"00" & (A and B);
            if S_ext(7 downto 0) = x"00" then
                Z <= '1'; 
            else
                Z <= '0';
            end if;
            C <= '0';
            O <= '0';
            N <= '0';
            
        when OP_or => 
            S_ext <= x"00" & (A or B);
            if S_ext(7 downto 0) = x"00" then
                Z <= '1';
            else
                Z <= '0'; 
            end if;
            C <= '0';
            O <= '0';
            N <= '0';
            
        when OP_xor => 
            S_ext <= x"00" & (A xor B);
            if S_ext(7 downto 0) = x"00" then
                Z <= '1'; 
            else
                Z <= '0';
            end if;
            C <= '0';
            O <= '0';
            N <= '0';
            
        when OP_notA => 
            S_ext <= x"00" & (not A);
            if S_ext(7 downto 0) = x"00" then
                Z <= '1';
            else
                Z <= '0'; 
            end if;
            C <= '0';
            O <= '0';
            N <= '0';
            
        when OP_notB => 
            S_ext <= x"00" & (not B);
            if S_ext(7 downto 0) = x"00" then
                Z <= '1'; 
            else
                Z <= '0';
            end if;
            C <= '0';
            O <= '0';
            N <= '0';
            
        when others => -- To make the compiler happy
            C <= '0';
            O <= '0';
            Z <= '0';
            N <= '0';
            
            
    end case;
    S <= S_ext(7 downto 0);
    
    --wait on A, B, opCode;
    end process;

end Behavioral;

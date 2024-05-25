----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/17/2024 08:22:14 AM
-- Design Name: 
-- Module Name: Pipeline - Behavioral
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
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Pipeline is
    Port (CLK: in std_logic);

end Pipeline;

architecture Structural of Pipeline is

    component Instruction_memory port(
           Address : in STD_LOGIC_VECTOR (7 downto 0);
           Clock : in STD_LOGIC;
           ValOut : out STD_LOGIC_VECTOR (31 downto 0));
    end component;
    component Register_file port(
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
    component Data_memory port(
           Address : in STD_LOGIC_VECTOR (7 downto 0);
           Data : in STD_LOGIC_VECTOR (7 downto 0);
           RW : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Clock : in STD_LOGIC;
           ValOut : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    component ALU Port ( 
           A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           S : out STD_LOGIC_VECTOR (7 downto 0);
           opCode : in STD_LOGIC_VECTOR (2 downto 0);
           C : out STD_LOGIC;
           O : out STD_LOGIC;
           Z : out STD_LOGIC;
           N : out STD_LOGIC);
   end component;

    constant OP_add:  STD_LOGIC_VECTOR(7 downto 0) := x"00";
    constant OP_sub:  STD_LOGIC_VECTOR(7 downto 0) := x"01";
    constant OP_mul:  STD_LOGIC_VECTOR(7 downto 0) := x"02";
    constant OP_and:  STD_LOGIC_VECTOR(7 downto 0) := x"03";
    constant OP_or:   STD_LOGIC_VECTOR(7 downto 0) := x"04";
    constant OP_xor:  STD_LOGIC_VECTOR(7 downto 0) := x"05";
    constant OP_notA: STD_LOGIC_VECTOR(7 downto 0) := x"06";
    constant OP_notB: STD_LOGIC_VECTOR(7 downto 0) := x"07";
    constant OP_cop:  STD_LOGIC_VECTOR(7 downto 0) := x"08";
    constant OP_afc:  STD_LOGIC_VECTOR(7 downto 0) := x"09";
    constant OP_ldr:  STD_LOGIC_VECTOR(7 downto 0) := x"0A";
    constant OP_str:  STD_LOGIC_VECTOR(7 downto 0) := x"0B";
    constant OP_nop:  STD_LOGIC_VECTOR(7 downto 0) := x"FF";
    
    signal IP : STD_LOGIC_VECTOR (7 downto 0) := x"00";
    
    signal instruction : std_logic_vector (31 downto 0) := x"FFFFFFFF";
    signal a1, b1, c1, op1 : std_logic_vector (7 downto 0) := x"FF"; 
    signal a2, b2, c2, op2 : std_logic_vector (7 downto 0) := x"FF";
    signal a3, b3, op3 : std_logic_vector (7 downto 0) := x"FF";
    signal a4, b4, op4 : std_logic_vector (7 downto 0) := x"FF";
    signal QA, QB : std_logic_vector (7 downto 0);
    signal S_ALU : std_logic_vector (7 downto 0);
    signal S_DM : std_logic_vector (7 downto 0);
    signal MUX_Address_DM : std_logic_vector (7 downto 0);
    signal Win : std_logic;
    signal RW_DM : std_logic;
    
signal C : STD_LOGIC;
signal O : STD_LOGIC;
signal Z : STD_LOGIC;
signal N : STD_LOGIC;

begin
    IM : Instruction_memory port map(Address=>IP, Clock => CLK, ValOut => instruction);
    RF : Register_file port map (AddressA=>b1 (3 downto 0), AddressB=>c1 (3 downto 0), AddressWrite=>a4 (3 downto 0), Write=>Win, Data=>b4, Reset=>'1', Clock=>CLK, QA=>QA, QB=>QB);
    AL : ALU port map (A=>b2, B=>c2, S=>S_ALU, opCode=>op2(2 downto 0), C=>C, O=>O, N=>N, Z=>Z); -- op2(2 downto 0) : truncate op_code to Alu_opCode
    DM : Data_memory port map(Address=>MUX_Address_DM, Data=>b3, RW=>RW_DM, Reset=>'1', Clock=>CLK, ValOut=>S_DM);
    
    process 
    variable ip_value : integer;
    variable hazard : boolean;
    begin
    wait until CLK'event and CLK = '1' ;
    
    
    -- Data Hazard Detector : a2 or a3 = b1 or c1 => Hazard
    
    if (((a2 = b1 or a2 = c1) and op2 /= op_nop) or ((a3 = b1 or a3 = c1) and op3 /= op_nop)) and op1 /= op_nop and op1 /= op_afc and op1 /= op_ldr then
        hazard := true;
    else 
        hazard := false;
    end if;
    
    
    -- Stage 4
    
        -- LC Write register file
        if op4 = op_str or op4 = op_nop then
            Win <= '0';
        else 
            Win <= '1';
        end if;
    
    -- Stage 3
    
        -- LC RW Data_memory
        if op3 = op_str then
            RW_DM <= '1';
        else 
            RW_DM <= '0';
        end if;
    
        -- MUX B4
        if op1 = op_ldr then
            b4 <= S_DM;
        else
            b4 <= b3;
        end if;
        
        -- MUX Address Data_memory
        if op3 = op_str then
            MUX_Address_DM <= a3;
        else
            MUX_Address_DM <= b3;
        end if;
        
        
        -- Propagate OP and A
        op4 <= op3;
        a4 <= a3;
        
    
    -- Stage 2
    
        -- MUX B3
        if op1 = op_add or op1 = op_sub or op1 = op_mul or op1 = op_and or op1 = op_or or op1 = op_xor or op1 = op_notA or op1 = op_notB then
            b3 <= S_ALU;
        else
            b3<=b2;
        end if;
        
        -- Propagate OP and A
        op3 <= op2;
        a3 <= a2;
 
    
    -- Stage 1
    if not hazard then
        -- MUX B2
        if op1 = op_cop or op1 = op_add or op1 = op_sub or op1 = op_mul or op1 = op_and or op1 = op_or or op1 = op_xor or op1 = op_notA or op1 = op_notB then
            b2 <= QA;
        else
            b2<=b1;
        end if;
        
        
        -- Propagate OP and A
        op2 <= op1;
        a2 <= a1;
        c2 <= QB;
    else -- insert bubble
        op2 <= op_nop;
        a2 <= x"FF";
        b2 <= x"FF";
        c2 <= x"FF";
    end if;
        
    
    -- Stage 0   
        if not hazard then
            -- Split instruction
            op1 <= instruction(31 downto 24);
            a1 <= instruction(23 downto 16);
            b1 <= instruction(15 downto 8);
            c1 <= instruction(7 downto 0);
        
            -- Increment IP
        
            ip_value := conv_integer(IP);
            ip_value := ip_value + 1 mod 255;
            IP <= conv_std_logic_vector(ip_value, 8);
        else
            -- Do nothing and wait for 1 clock cycle 
        end if;
        
    
    
        
    end process;


end Structural;

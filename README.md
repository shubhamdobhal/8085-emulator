# 8085-emulator
Implementation of 8085 microprocessor in C++
Contain arithmetic,logical,load and store instructions with additional debugger support.
Instructions It support:</br>

**Airthmatic Instruction:** ADD,ADI,ADC,ACI,SUB,SUI,SBB,SBI,LXI,INR,INX,DCR,DCX,DAD</br>
**Branching Instruction:** JMP,JC,JNZ,JZ,JNZ,JP,JM,JPE,JPO </br>
**Data Transfer Instruction:** MOV,MVI,LDA,STA,LHLD,SHLD,STAX,XCHG,SPHL,XTHL,PUSH,POP</br>
**Logical Instruction:** CMA,CMP,SET,CMC,ANA,ANI,RA,XRI,ORA,ORI,RLC,RRC,RAL,RAR,STC </br>


**About 8085 microprocessor:**</br>
8085 is pronounced as "eighty-eighty-five" microprocessor. It is an 8-bit microprocessor designed by Intel in 1977 using NMOS technology.

It has the following configuration −

- 8-bit data bus
- 16-bit address bus, which can address upto 64KB
- A 16-bit program counter
- A 16-bit stack pointer
- Six 8-bit registers arranged in pairs: BC, DE, HL
- Some other register are Accumulator(8 bit),flag(8 bit), Program counter(16 bit),stack pointer(16 bit),temporary register (8 bit),instruction register(8 bit) </br>
It is used in washing machines, microwave ovens, mobile phones, etc. </br>

**8085 Microprocessor – Functional Units** </br>
8085 consists of the following functional units − </br>

**Accumulator**</br>
It is an 8-bit register used to perform arithmetic, logical, I/O & LOAD/STORE operations. It is connected to internal data bus & ALU.</br>

**Arithmetic and logic unit**</br>
As the name suggests, it performs arithmetic and logical operations like Addition, Subtraction, AND, OR, etc. on 8-bit data.</br>

**General purpose register**</br>
There are 6 general purpose registers in 8085 processor, i.e. B, C, D, E, H & L. Each register can hold 8-bit data.</br>

These registers can work in pair to hold 16-bit data and their pairing combination is like B-C, D-E & H-L.</br>

**Program counter**</br>
It is a 16-bit register used to store the memory address location of the next instruction to be executed. Microprocessor increments the program whenever an instruction is being executed, so that the program counter points to the memory address of the next instruction that is going to be executed.</br>

**Stack pointer**</br>
It is also a 16-bit register works like stack, which is always incremented/decremented by 2 during push & pop operations.</br>

**Temporary register**</br>
It is an 8-bit register, which holds the temporary data of arithmetic and logical operations.</br>

**Flag register**</br>
It is an 8-bit register having five 1-bit flip-flops, which holds either 0 or 1 depending upon the result stored in the accumulator.</br>

These are the set of 5 flip-flops −
- Sign (S)
- Zero (Z)
- Auxiliary Carry (AC)
- Parity (P)
- Carry (C)
- Its bit position is shown in the following table −

**Instruction register and decoder**</br>
It is an 8-bit register. When an instruction is fetched from memory then it is stored in the Instruction register. Instruction decoder decodes the information present in the Instruction register.</br>

**Addressing Modes in 8085**</br>
These are the instructions used to transfer the data from one register to another register, from the memory to the register, and from the register to the memory without any alteration in the content. Addressing modes in 8085 is classified into 5 groups −

- **Immediate addressing mode**</br>
In this mode, the 8/16-bit data is specified in the instruction itself as one of its operand. For example: MVI K, 20F: means 20F is copied into register K.</br>

- **Register addressing mode**</br>
In this mode, the data is copied from one register to another. For example: MOV K, B: means data in register B is copied to register K.</br>

- **Direct addressing mode**</br>
In this mode, the data is directly copied from the given address to the register. For example: LDB 5000K: means the data at address 5000K is copied to register B.</br>

- **Indirect addressing mode**</br>
In this mode, the data is transferred from one register to another by using the address pointed by the register. For example: MOV K, B: means data is transferred from the memory address pointed by the register to the register K.</br>

**Logical instructions Example** </br>
- **OPCODE:** CMP
   - **OPERAND:** Memory or Register
   - **Defination:** Compare the register or memory with the accumulator
   - **Explanation:** The contents of the operand (register or memory) are M compared with the contents of the accumulator.
- **OPCODE:** CMI
   - **OPERAND:** 8-bit data
   - **Defination:** Compare immediate with the accumulator
   - **Explanation:** The second byte data is compared with the contents of the accumulator.
- **OPCODE:** ANA
   - **OPERAND:** Memory or Register
   - **Defination:** Logical AND register or memory with the accumulator
   - **Explanation:** The contents of the accumulator are logically AND with M the contents of the register or memory, and the result is placed in the accumulator.
- **OPCODE:** CMI
   - **OPERAND:** 8-bit data
   - **Defination:** 	Logical AND immediate with the accumulator
   - **Explanation:** The contents of the accumulator are logically AND with the 8-bit data and the result is placed in the accumulator.

- **OPCODE:** RLC
   - **OPERAND:** NONE
   - **Defination:** Rotate the accumulator left
   - **Explanation:** Each binary bit of the accumulator is rotated left by one position. Bit D7 is placed in the position of D0 as well as in the Carry flag. CY is modified according to bit D7.


**Branching instructions Example** </br>
All the instruction has OPERAND OF 16 bit, as its a memory location
- **OPCODE:** JMP
   - **Defination:** Jump unconditionally
   - **Explanation:** The program sequence is transferred to the memory address given in the operand.
- **OPCODE:** JC
   - **Defination:** Jump on Carry
   - **FLAG:** CY=1
   - **Explanation:** The program sequence is transferred to the memory address given in the operand based on the specified flag of the PSW.
- **OPCODE:** JNZ
   - **Defination:** Jump on no zero
   - **FLAG:** Z=0
   - **Explanation:** The program sequence is transferred to the memory address given in the operand based on the specified flag of the PSW.

**Arithmetic instructions Example** </br>
- **OPCODE:** ADD
   - **OPERAND:** Memory or Register
   - **Defination:** Add register or memory, to the accumulator
   - **Explanation:** The contents of the register or memory are added to the contents of the accumulator and the result is stored in the accumulator.Example − ADD K.
- **OPCODE:** ADC
   - **OPERAND:** Memory or Register
   - **Defination:** Add register to the accumulator with carry
   - **Explanation:** The contents of the register or memory & M the Carry flag are added to the contents of the accumulator and the result is stored in the accumulator.Example − ADC K.
- **OPCODE:** ADI
   - **OPERAND:** 8-bit data
   - **Defination:** 	Add the immediate to the accumulator
   - **Explanation:** The 8-bit data is added to the contents of the accumulator and the result is stored in the accumulator.Example − ADI 55K
- **OPCODE:** DAD
   - **OPERAND:** Reg. pair
   - **Defination:** 	Add the register pair to H and L registers
   - **Explanation:** The 16-bit data of the specified register pair are added to the contents of the HL register.Example − DAD K
- **OPCODE:** INR
   - **OPERAND:** Memory or Register
   - **Defination:** 	Increment the register or the memory by 1
   - **Explanation:** The contents of the designated register or the memory are incremented by 1 and their result is stored at the same place.Example − INR K
**Data-transfer instructions  Example** </br>
- **OPCODE:** MOV
   - **OPERAND:** Rd, Sc,M, Sc,Dt, M
   - **Defination:** Copy from the source (Sc) to the destination(Dt)
   - **Explanation:** This instruction copies the contents of the source register into the destination register without any alteration.Example − MOV K, L
- **OPCODE:** MVI
   - **OPERAND:** Rd, data,M, data
   - **Defination:** Move immediate 8-bit
   - **Explanation:** The 8-bit data is stored in the destination register or memory.Example − MVI K, 55L
- **OPCODE:** LDAX
   - **OPERAND:** B/D Reg. pair
   - **Defination:** 	Load the accumulator indirect
   - **Explanation:** The contents of the designated register pair point to a memory location. This instruction copies the contents of that memory location into the accumulator.Example − LDAX K


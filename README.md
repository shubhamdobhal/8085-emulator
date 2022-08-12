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






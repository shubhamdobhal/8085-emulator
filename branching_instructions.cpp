#include "CustomFunctions.cpp"
// branching instructions

//1 JMP
void JMP(int address)
{
	pc = address;
	program_counter = dectohex(pc);
}

//2 JC
void JC(int address)
{
	if(flag['c']==1)
		pc = address;
	else
		pc += 3;
    program_counter = dectohex(pc);
}

//3 JNC
void JNC(int address)
{
	if(flag['c']==0)
		pc = address;
	else
		pc += 3;
    program_counter = dectohex(pc);
}

//4 JZ
void JZ(int address)
{
	if(flag['z']==1)
		pc = address;
	else
		pc += 3;
    program_counter = dectohex(pc);
}

//5 JNZ
void JNZ(int address)
{
	if(flag['z']==0)
		pc = address;
	else
		pc += 3;
    program_counter = dectohex(pc);
}

//6 JP
void JP(int address)
{
	if(flag['s']==0)
		pc = address;
	else
		pc += 3;
    program_counter = dectohex(pc);
}

//7 JM
void jump_minus(int address)
{
	if(flag['s']==1)
		pc = address;
	else
		pc += 3;
    program_counter = dectohex(pc);
}

//8 JPE
void JPE(int address)
{
	if(flag[1]==1)
		pc = address;
	else
		pc += 3;
    program_counter = dectohex(pc);
}

//9 JPO
void JPO(int address)
{
	if(flag[1]==0)
		pc = address;
	else
		pc += 3;
    program_counter = dectohex(pc);
}

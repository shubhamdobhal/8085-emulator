// branching instructions

//1 JMP
void jump(int address){
	pc=address;
}

//2 JC
void jump_cary(int address){
	if(flag[0]==1)
		pc=address;
	else 
		pc++;
}

//3 JNC
void jump_not_cary(int address){
	if(flag[0]==0)
		pc=address;
	else 
		pc++;
}

//4 JZ
void jump_zero(int address){
	if(flag[3]==1)
		pc=address;
	else 
		pc++;
}

//5 JNZ
void jump_not_zero(int address){
	if(flag[3]==0)
		pc=address;
	else 
		pc++;
}

//6 JP
void jump_positive(int address){
	if(flag[4]==0)
		pc=address;
	else 
		pc++;
}

//7 JM
void jump_minus(int address){
	if(flag[4]==1)
		pc=address;
	else 
		pc++;
}

//8 JPE
void jump_parity_even(int address){
	if(flag[1]==1)
		pc=address;
	else 
		pc++;
}

//9 JPO
void jump_parity_odd(int address){
	if(flag[1]==0)
		pc=address;
	else 
		pc++;
}



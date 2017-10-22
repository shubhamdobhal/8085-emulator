#include "ArithmaticInstructions.cpp"


//1 JMP
void JMP(string address){
	program_counter=address;
	pc = hextodec(program_counter);
}

//2 JC
void JC(string address){
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['c']==1){
		program_counter=address;
		pc = hextodec(program_counter);
	}
	else {
		pc += 3;
		program_counter = dectohex(pc);
	}
}

//3 JNC
void JNC(string address){
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['c']==0){
		program_counter=address;
		pc = hextodec(program_counter);
	}
	else {
		pc += 3;
		program_counter = dectohex(pc);
	}
}


//4 JZ
void JZ(string address){
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['z']==1){
		program_counter=address;
		pc = hextodec(program_counter);
	}
	else {
		pc += 3;
		program_counter = dectohex(pc);
	}
}

//5 JNZ
void JNZ(string address){
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['z']==0){
		program_counter=address;
		pc = hextodec(program_counter);
	}
	else {
		pc += 3;
		program_counter = dectohex(pc);
	}
}

//6 JP
void JP(string address){
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['s']==0){
		program_counter=address;
		pc = hextodec(program_counter);
	}
	else {
		pc += 3;
		program_counter = dectohex(pc);
	}
}

//7 JM
void JM(string address){
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['s']==1){
		program_counter=address;
		pc = hextodec(program_counter);
	}
	else {
		pc += 3;
		program_counter = dectohex(pc);
	}
}

//8 JPE
void JPE(string address){
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['p']==1){
		program_counter=address;
		pc = hextodec(program_counter);
	}
	else {
		pc += 3;
		program_counter = dectohex(pc);
	}
}

//9 JPO
void JPO(string address){
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['p']==0){
		program_counter=address;
		pc = hextodec(program_counter);
	}
	else {
		pc += 3;
		program_counter = dectohex(pc);
	}
}

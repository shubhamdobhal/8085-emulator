//airthmatic

//10 ADD
void add(int registers[],char operand){
	switch(operand){
		case B:
			registers[0]+=registers[1];
			break;
		case C:
			registers[0]+=registers[2];
			break;
		case D:
			registers[0]+=registers[3];
			break;
		case E:
			registers[0]+=registers[4];
			break;
		case H:
			registers[0]+=registers[5];
			break;
		case L:
			registers[0]+=registers[6];
			break;
		case M:
			int address=registers[5]*256+registers[6];
			registers[0]+=memory[address];
			break;
		default:
			throw(exception);
	}
}

//11 ADI
int add_immidiate(int A,int val){
	if(val/1000>0){
		throw(exception);
	}
	val=hextodec(val);
	A+=val;
	return A;
}
 
//12 ADC
int add_carry(int A,char operand){
	return add(A,operand)+1;
}

//13 ACI
int add_carry_immidiate(int A,int val){
	return add_immidiate(A,operand)+1;
}

//14 SUB
void sub(int registers[],char operand){
	switch(operand){
		case B:
			registers[0]-=registers[1];
			break;
		case C:
			registers[0]-=registers[2];
			break;
		case D:
			registers[0]-=registers[3];
			break;
		case E:
			registers[0]-=registers[4];
			break;
		case H:
			registers[0]-=registers[5];
			break;
		case L:
			registers[0]-=registers[6];
			break;
		case M:
			int address=registers[5]*256+registers[6];
			registers[0]-=memory[address];
			break;
		default:
			throw(exception);
	}
}

//15 SUI
int sub_immidiate(int A,int val){
	if(val/1000>0){
		throw(exception);
	}
	val=hextodec(val);
	A-=val;
	return A;
}

//16 SBB
int sub_borrow(int A,char operand){
	return sub(A,operand)-flag[0];
}

//17 SBI
int sub_borrow_immidiate(int A,int val){
	return sub_immidiate(A,val)-flag[0];
}

//18 LXI
void inst_LXI(int registers[],int val){
	int val_L=val%100;
	int val_H=val/100;
	registers[5]=hex_to_dec(val_H);
	registers[6]=hex_to_dec(val_L);
}

//19 INR
void increment(int registers[],char operand){
	switch(operand){
		case A:
			registers[0]++;
		case B:
			registers[1]++;
			break;
		case C:
			registers[2]++;
			break;
		case D:
			registers[3]++;
			break;
		case E:
			registers[4]++;
			break;
		case H:
			registers[5]++;
			break;
		case L:
			registers[6]++;
			break;
		case M:
			int address=registers[5]*256+registers[6];
			memory[address]++;
			break;
		default:
			throw(exception);
	}
}

//20 INX { }

//21 DCR
void sub(int registers[],char operand){
	switch(operand){
		case A:
			registers[0]--;
		case B:
			registers[1]--;
			break;
		case C:
			registers[2]--;
			break;
		case D:
			registers[3]--;
			break;
		case E:
			registers[4]--;
			break;
		case H:
			registers[5]--;
			break;
		case L:
			registers[6]--;
			break;
		case M:
			int address=registers[5]*256+registers[6];
			memory[address]--;
			break;
		default:
			throw(exception);
	}
}

//22 DCX { }

//23 DAD { }

//24 DAA { }

void jump(int address){
	pc=address;
}

void jump_cary(int address){
	if(flag[0]==1)
		pc=address;
	else 
		pc++;
}

void jump_not_cary(int address){
	if(flag[0]==0)
		pc=address;
	else 
		pc++;
}

void jump_zero(int address){
	if(flag[3]==1)
		pc=address;
	else 
		pc++;
}

void jump_not_zero(int address){
	if(flag[3]==0)
		pc=address;
	else 
		pc++;
}

void jump_positive(int address){
	if(flag[4]==0)
		pc=address;
	else 
		pc++;
}

void jump_negative(int address){
	if(flag[4]==1)
		pc=address;
	else 
		pc++;
}

void jump_parity_even(int address){
	if(flag[1]==1)
		pc=address;
	else 
		pc++;
}

void jump_parity_odd(int address){
	if(flag[1]==0)
		pc=address;
	else 
		pc++;
}

//airthmatic

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

int add_immidiate(int A,int val){
	if(val/1000>0){
		throw(exception);
	}
	val=hextodec(val);
	A+=val;
	return A;
}

int sub_immidiate(int A,int val){
	if(val/1000>0){
		throw(exception);
	}
	val=hextodec(val);
	A-=val;
	return A;
}



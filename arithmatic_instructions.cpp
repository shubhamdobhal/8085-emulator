//airthmatic

//10 ADD

void add(char operand){
	if(operand=='M'){
		string address=dectohex(registers['H'])+dectohex(registers['L']);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']+=memory[address];
	}
	else
		registers['A']+=registers[operand];
	check_flags_2();
}

//11 ADI
void add_immidiate(string val){
	registers['A']+=hextodec(val);
	check_flags_2();
}
 
//12 ADC
int add_carry(char operand){
	if(operand=='M'){
		string address=dectohex(registers['H'])+dectohex(registers['L']);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']+=memory[address]+flag['c'];
	}
	else
		registers['A']+=registers[operand]+flag['c'];
	check_flags_2();
}

//13 ACI
int add_carry_immidiate(string val){
	registers['A']+=hextodec(val)+flag['c'];
	check_flags_2();
}

//14 SUB
void sub(char operand){
	if(operand=='M'){
		string address=dectohex(registers['H'])+dectohex(registers['L']);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']-=memory[address];
	}
	else
		registers['A']-=registers[operand];
	check_flags_2();
}

//15 SUI
void sub_immidiate(string val){
	registers['A']-=hextodec(val);
	check_flags_2();
}

//16 SBB
void sub_borrow(char operand){
	if(operand=='M'){
		string address=dectohex(registers['H'])+dectohex(registers['L']);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']-=memory[address]-flag['c'];
	}
	else
		registers['A']-=registers[operand]-flag['c'];
	check_flags_2();
}

//17 SBI
void sub_borrow_immidiate(string val){
	registers['A']-=hextodec(val)-flag['c'];
	check_flags_2();
}

//18 LXI
void inst_LXI(char operand){
	int val_L=val%100;
	int val_H=val/100;
	registers[5]=hex_to_dec(val_H);
	registers[6]=hex_to_dec(val_L);
}

//19 INR
void increment(char operand){
	registers[operand]++;
	check_flags_1(operand);
}

//20 INX { }
void increase_reg_pair(char operand){
	if(operand=='B'){
		if(registers['C']==127){
			registers['C']=0;
			if(registers['B']==127)
				registers['B']=0;
		}
		else
			registers['C']++;
	}
	else if(operand=='D'){
		if(registers['E']==127){
			registers['E']=0;
			if(registers['D']==127)
				registers['D']=0;
		}
		else
			registers['E']++;
	}
	else if(operand=='H'){
		if(registers['L']==127){
			registers['L']=0;
			if(registers['H']==127)
				registers['H']=0;
		}
		else
			registers['L']++;
	}
}

//21 DCR
void sub(char operand){
	registers[operand]--;
	check_flag_1(operand);
}

//22 DCX { }				//function under construction........
void decrease_reg_pair(char operand){	
	if(operand=='B'){
		if(registers['C']==127){
			registers['C']=0;
			if(registers['B']==127)
				registers['B']=0;
		}
		else
			registers['C']++;
	}
	else if(operand=='D'){
		if(registers['E']==127){
			registers['E']=0;
			if(registers['D']==127)
				registers['D']=0;
		}
		else
			registers['E']++;
	}
	else if(operand=='H'){
		if(registers['L']==127){
			registers['L']=0;
			if(registers['H']==127)
				registers['H']=0;
		}
		else
			registers['L']++;
	}
}

//23 DAD { }
void DAD(char operand)	//Not compeleted yet  flag remains
{
	int carry,sum;
	switch(operand)
	{
		case B:
			sum=registers['C']+registers['L'];
			registers['L']=sum%256;
			carry=sum/256;
			sum=registers['B']+registers['H']+carry;
			registers['H']=sum%256;
			flag['c']=sum/256;
			
		break;
		case D:
			sum=registers['E']+registers['L'];
			registers['L']=sum%256;
			carry=sum/256;
			sum=registers['D']+registers['H']+carry;
			registers['H']=sum%256;
			flag['c']=sum/256;
		break:
		case H:
			sum=registers['L']+registers['L'];
			registers['L']=sum%256;
			carry=sum/256;
			sum=registers['H']+registers['H']+carry;
			registers['H']=sum%256;
			flag['c']=sum/256;
		break;	
	}
}

//24 DAA { }

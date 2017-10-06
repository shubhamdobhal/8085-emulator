//airthmatic

void check_flags(char operand){				//to check flags for dcr, inr .....,carry flag never changes
	if(registers[operand]==0 || registers[operand]==128 || registers[operand]==-129){
		flag['z']=1;
		registers[operand]=0;
	}
	else{
		flag['z']=0;
	}
	//code for checking parity and auxilarry carry.............
}

void check(){							//to check flags for add,sub........
	if(registers['A']<0){
		flag['s']=1;
		if(registers['A']<(-128)){
			flag['c']=1;		//if carry
			registers['A']=129-registers['A'];		
		}
	}
	else{	
		flag['s']=0;
		flag['c']=registers['A']/128;		//if carry
		registers['A']%=128;
	}
	if(registers['A']==0)
		flag['z']=1;
	else
		flag['z']=0;
	//code for checking auxilarry and parity flag..............
}

//10 ADD

void add(char operand){
	if(operand=='M'){
		int address=registers['H']*256+registers['L'];
		registers['A']+=memory[address];
	}
	else
		registers['A']+=registers[operand];
	check();
}

//11 ADI
void add_immidiate(string val){
	registers['A']+=hextodec(val);
	check();
}
 
//12 ADC
int add_carry(char operand){
	if(operand=='M'){
		int address=registers['H']*256+registers['L'];
		registers['A']+=memory[address]+flag['c'];
	}
	else
		registers['A']+=registers[operand]+flag['c'];
	check();
}

//13 ACI
int add_carry_immidiate(char val){
	registers['A']+=hextodec(val)+flag['c'];
	check();
}

//14 SUB
void sub(char operand){
	if(operand=='M'){
		int address=registers['H']*256+registers['L'];
		registers['A']-=memory[address];
	}
	else
		registers['A']-=registers[operand];
	check();
}

//15 SUI
int sub_immidiate(char val){
	registers['A']-=hextodec(val);
	check();
}

//16 SBB
int sub_borrow(char operand){
	if(operand=='M'){
		int address=registers['H']*256+registers['L'];
		registers['A']-=memory[address]-flag['c'];
	}
	else
		registers['A']-=registers[operand]-flag['c'];
	check();
}

//17 SBI
int sub_borrow_immidiate(char val){
	registers['A']-=hextodec(val)-flag['c'];
	check();
}

//18 LXI
void inst_LXI(int registers[],int val){
	int val_L=val%100;
	int val_H=val/100;
	registers[5]=hex_to_dec(val_H);
	registers[6]=hex_to_dec(val_L);
}

//19 INR
void increment(char operand){
	registers[operand]++;
	check_flag(operand);
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
void sub(int registers[],char operand){
	registers[operand]--;
	check_flag(operand);
}

//22 DCX { }
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

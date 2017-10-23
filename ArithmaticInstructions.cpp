//10 ADD

void ADD(char operand){
	if(operand=='M'){
        string s = dectohex(registers['L']);
		string address=dectohex(registers['H'])+((s.size()==1)?("0"+s):s);
		//cout<<memory[address]<<endl;
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']+=memory[address];
	}
	else
		registers['A']+=registers[operand];
	check_carry();
	check_sign();
	check_zero();
	check_parity();
	check_auxilary();
}

//11 ADI
void ADI(string val){
	registers['A']+=hextodec(val);
	check_carry();
	check_sign();
	check_zero();
	check_parity();
	check_auxilary();
}

//12 ADC
int ADC(char operand){
	if(operand=='M'){
		string s = dectohex(registers['L']);
		string address=dectohex(registers['H'])+((s.size()==1)?("0"+s):s);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']+=memory[address]+flag['c'];
	}
	else
		registers['A']+=registers[operand]+flag['c'];
	check_carry();
	check_sign();
	check_zero();
	check_parity();
	check_auxilary();
}

//13 ACI
int ACI(string val){
	registers['A']+=hextodec(val)+flag['c'];
	check_carry();
	check_sign();
	check_zero();
	check_parity();
	check_auxilary();
}

//14 SUB
void SUB(char operand){
	if(operand=='M'){
		string s = dectohex(registers['L']);
		string address=dectohex(registers['H'])+((s.size()==1)?("0"+s):s);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']-=memory[address];
	}
	else
		registers['A']-=registers[operand];
	check_carry();
	check_sign();
	check_zero();
	check_parity();
	check_auxilary();
}

//15 SUI
void SUI(string val){
	registers['A']-=hextodec(val);
	check_carry();
	check_sign();
	check_zero();
	check_parity();
	check_auxilary();
}

//16 SBB
void SBB(char operand){
	if(operand=='M'){
		string s = dectohex(registers['L']);
		string address=dectohex(registers['H'])+((s.size()==1)?("0"+s):s);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']-=memory[address]-flag['c'];
	}
	else
		registers['A']-=(registers[operand]-flag['c']);
	check_carry();
	check_sign();
	check_zero();
	check_parity();
	check_auxilary();
	//check_flags_2();
}

//17 SBI
void SBI(string val){
	registers['A']-=hextodec(val)-flag['c'];
	check_carry();
	check_sign();
	check_zero();
	check_parity();
	check_auxilary();
}

//18 LXI
void LXI(char operand,string val){
	string val_L;
	val_L = val.substr(2,2);
	string val_H;
	val_H = val.substr(0,2);
	//cout<<val<<endl<<val_L<<endl<<val_H<<endl;
	registers['H']=hextodec(val_H);
	registers['L']=hextodec(val_L);
}

//19 INR
void INR(char operand){
	registers[operand]++;
	if(registers[operand]>255){
		registers[operand]%=256;
	}
	//check_carry();
	check_sign(operand);
	check_zero(operand);
	check_parity(operand);
	check_auxilary(operand);
}

//20 INX { }
void INX(char operand){
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
void DCR(char operand){
	registers[operand]--;
	if(registers[operand]<0){
		registers[operand]+=256;
	}
	//check_carry();
	check_sign(operand);
	check_zero(operand);
	check_parity(operand);
	check_auxilary(operand);
}

//22 DCX { }				//function under construction........
void DCX(char operand){
	if(operand=='B'){
		if(registers['C']==-128){
			registers['C']=0;
			if(registers['B']==-128)
				registers['B']=0;
		}
		else
			registers['C']--;
	}
	else if(operand=='D'){
		if(registers['E']==-128){
			registers['E']=0;
			if(registers['D']==-128)
				registers['D']=0;
		}
		else
			registers['E']--;
	}
	else if(operand=='H'){
		if(registers['L']==-128){
			registers['L']=0;
			if(registers['H']==-128)
				registers['H']=0;
		}
		else
			registers['L']--;
	}
}

//23 DAD { }
void DAD(char operand)	//Not compeleted yet  flag remains
{
	int carry,sum;
	switch(operand)
	{
		case 'B':
			sum=registers['C']+registers['L'];
			registers['L']=sum%256;
			carry=sum/256;
			sum=registers['B']+registers['H']+carry;
			registers['H']=sum%256;
			flag['c']=sum/256;

		break;
		case 'D':
			sum=registers['E']+registers['L'];
			registers['L']=sum%256;
			carry=sum/256;
			sum=registers['D']+registers['H']+carry;
			registers['H']=sum%256;
			flag['c']=sum/256;
		break;
		case 'H':
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

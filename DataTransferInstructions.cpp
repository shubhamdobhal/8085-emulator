#include"LogicalInstructions.cpp"
void MOV(char operand1,char operand2)
{
	if(operand1!='M'&&operand2!='M')
	{
		registers[operand1]=registers[operand2];
	}
	else    //incase operand is memory
	{
		int address=registers['H']*256+registers['L'];
		if(memory.find(dectohex(address))==memory.end())
		{
			memory[dectohex(address)]=0;
		}
		if(operand1=='M')
		{
			memory[dectohex(address)]=registers[operand2];
		}
		else
		{
			registers[operand1]=memory[dectohex(address)];
		}
	}
}
void MVI(char operand,string val)
{
	registers[operand]=hextodec(val);
}
void LDA(string address)
{
	if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
	registers['A']=memory[address];
}
void STA(string address)
{
	if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
	memory[address]=registers['A'];
}
void LHLD(string address)
{
	int add=hextodec(address);
	if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
	if(memory.find(dectohex(add+1))==memory.end())
		{
			memory[dectohex(add+1)]=0;
		}

	registers['H']=memory[address];
	registers['L']=memory[dectohex(add+1)];
}
void SHLD(string address)
{
	int add=hextodec(address);
	if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
	if(memory.find(dectohex(add+1))==memory.end())
		{
			memory[dectohex(add+1)]=0;
		}
	memory[address]=registers['L'];
	memory[dectohex(add+1)]=registers['H'];
}
void STAX(char operand)
{
	string hex;
	int dec;
	switch(operand)
		{
			case 'B':
			hex=dectohex(registers['B'])+dectohex(registers['C']);
			dec=hextodec(hex);
			if(memory.find(hex)==memory.end())
			{
				memory[hex]=0;
			}
			memory[hex]=registers['A'];
			break;
			case 'D':
			hex=dectohex(registers['D'])+dectohex(registers['E']);
			dec=hextodec(hex);
			if(memory.find(hex)==memory.end())
			{
				memory[hex]=0;
			}
			memory[hex]=registers['A'];
			break;
			case 'H':
			hex=dectohex(registers['H'])+dectohex(registers['L']);
			dec=hextodec(hex);
			if(memory.find(hex)==memory.end())
			{
				memory[hex]=0;
			}
			memory[hex]=registers['A'];
			break;
			/*default:
			throw(exception);*/
		}

}
void XCHG()
{
	int a;
	a=registers['D'];
	registers['D']=registers['H'];
	registers['H']=a;
	a=registers['E'];
	registers['E']=registers['L'];
	registers['L']=a;
}
void SPHL()
{
	if(memory.find(dectohex(sp-1))==memory.end())
	{
		memory[dectohex(sp-1)]=0;
	}
	if(memory.find(dectohex(sp-2))==memory.end())
	{
		memory[dectohex(sp-2)]=0;
	}
	memory[dectohex(sp-1)]=registers['H'];
	memory[dectohex(sp-2)]=registers['L'];
	sp=sp-2;
}
void XTHL()
{

	if(memory.find(dectohex(sp-1))==memory.end())
	{
		memory[dectohex(sp-1)]=0;
	}
	if(memory.find(dectohex(sp-2))==memory.end())
	{
		memory[dectohex(sp-1)]=0;
	}
	registers['L']=memory[dectohex(sp)];
	registers['H']=memory[dectohex(sp+1)];
}
void PUSH(char operand)
{
	if(memory.find(dectohex(sp-1))==memory.end())
	{
		memory[dectohex(sp-1)]=0;
	}
	if(memory.find(dectohex(sp-2))==memory.end())
	{
		memory[dectohex(sp-2)]=0;
	}
	switch(operand)
	{
		case 'B':
			memory[dectohex(sp-1)]=registers['B'];
			memory[dectohex(sp-2)]=registers['C'];
			sp=sp-2;
			break;
		case 'D':
			memory[dectohex(sp-1)]=registers['D'];
			memory[dectohex(sp-2)]=registers['E'];
			sp=sp-2;
			break;
		case 'H':
			memory[dectohex(sp-1)]=registers['H'];
			memory[dectohex(sp-1)]=registers['L'];
			sp=sp-2;
	}
}
void POP(char operand)
{
	if(memory.find(dectohex(sp-1))==memory.end())
	{
		memory[dectohex(sp-1)]=0;
	}
	if(memory.find(dectohex(sp-2))==memory.end())
	{
		memory[dectohex(sp-2)]=0;
	}
	switch(operand)
	{
		case 'B':
			registers['C']=memory[dectohex(sp)];
			registers['B']=memory[dectohex(sp+1)];
			sp=sp+2;
			break;
		case 'D':
			registers['E']=memory[dectohex(sp)];
			registers['D']=memory[dectohex(sp+1)];
			sp=sp+2;
			break;
		case 'H':
			registers['L']=memory[dectohex(sp)];
			registers['H']=memory[dectohex(sp+1)];
			sp=sp+2;
			break;
	}
}

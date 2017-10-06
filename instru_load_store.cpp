void MOV(char operand1,char operand2)
{
	if(operand1!='M'&&operand2!=M)
	{
		registers[operand1]=registers[operand2];
	}
	else    //incase operand is memory
	{
		int address=registers['H']*256+registers['L'];
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		if(operand1=='M')
		{
			memory[address]=registers[operand2];
		}
		else
		{
			memory[address]=registers[operand1];
		}
	}
}
void MVI(char operand,string val)
{
	registers[operand]=hextodec(val);
}
void LDA(string address)
{
	int add=hextodec(address);
	if(memory.find(add)==memory.end())
		{
			memory[add]=0;
		}
	registers['A']=memory[add];
}
void STA(string address)
{
	int add=hextodec(address);
	if(memory.find(add)==memory.end())
		{
			memory[add]=0;
		}
	memory[add]=registers['A'];
}
void LHLD(string address)
{
	int add=hextodec(address);
	if(memory.find(add)==memory.end())
		{
			memory[add]=0;
		}
	if(memory.find(add+1)==memory.end())
		{
			memory[add+1]=0;
		}
	
	registers['H']=memory[add];
	registers['L']=memory[add+1];
}
void SHLD(string address)
{
	int add=hextodec(address);
	if(memory.find(add)==memory.end())
		{
			memory[add]=0;
		}
	if(memory.find(add+1)==memory.end())
		{
			memory[add+1]=0;
		}
	memory[add]=registers['L'];
	memory[add+1]=registers['H'];
}
void STAX(char operand)
{
	string hex;
	int dec;
	switch(operand)
		{
			case B:
			hex=dectohex(registers['B'])+decitohex(registers['C']);
			dec=hextodec(hex);
			if(memory.find(dec)==memory.end())
			{
				memory[dec]=0;
			}
			memory[dec]=registers[A];
			break;
			case D:
			hex=dectohex(registers['D'])+decitohex(registers['E']);
			dec=hextodec(hex);
			if(memory.find(dec)==memory.end())
			{
				memory[dec]=0;
			}
			memory[dec]=registers['A'];
			break;
			case H:
			hex=dectohex(registers['H'])+decitohex(registers['L']);
			dec=hextodec(hex);
			if(memory.find(dec)==memory.end())
			{
				memory[dec]=0;
			}
			memory[dec]=registers['A'];
			break;
			default:
			throw(exception);
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
	if(memory.find(sp-1)==memory.end())
	{
		memory[sp-1]=0;
	}
	if(memory.find(sp-2)==memory.end())
	{
		memory[sp-2]=0;
	}
	memory[sp-1]=registers['H'];
	memory[sp-2]=registers['L'];
	sp=sp-2;
}
void XTHL()
{
	
	if(memory.find(sp-1)==memory.end())
	{
		memory[sp-1]=0;
	}
	if(memory.find(sp-2)==memory.end())
	{
		memory[sp-2]=0;
	}
	registers['L']=memory[sp];
	registers['H']=memory[sp+1];
}
void PUSH(char operand)
{
	if(memory.find(sp-1)==memory.end())
	{
		memory[sp-1]=0;
	}
	if(memory.find(sp-2)==memory.end())
	{
		memory[sp-2]=0;
	}
	switch(operand)
	{
		case B:
			memory[sp-1]=registers['B'];
			memory[sp-2]=registers['C'];
			sp=sp-2;
			break;
		case D:
			memory[sp-1]=registers['D'];
			memory[sp-2]=registers['E'];
			sp=sp-2;
			break;
		case H:
			memory[sp-1]=registers['H'];
			memory[sp-2]=registers['L'];
			sp=sp-2;
	}
}
void POP(char operand)
{
	if(memory.find(sp-1)==memory.end())
	{
		memory[sp-1]=0;
	}
	if(memory.find(sp-2)==memory.end())
	{
		memory[sp-2]=0;
	}
	switch(operand)
	{
		case B:
			registers['C']=memory[sp];
			registers['B']=memroy[sp+1];
			sp=sp+2;
			break;
		case D:
			registers['E']=memory[sp];
			registers['D']=memory[sp+1];
			sp=sp+2;
			break;
		case H:
			registers['L']=memory[sp];
			registers['H']=memory[sp+1];
			sp=sp+2;
			break;
	}
}


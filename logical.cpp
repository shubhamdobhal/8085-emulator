void CMA()
{
	registers['A']=255-registers['A'];
}
void CMP(char operand)
{
			if(registers['A']>registers[operand])
			{
				flag['c']=0;
				flag['z']=0;
			}
			else if(registers['A']==registers[operand])
			{
				flag['z']=1;	
			}	
			else
			{
				flag['c']=1;
			}								
		
}
void SET(string mem,string val)
{
	memory[hextodec(mem)]=hextodec(val);
}
void CMC()
{
	if(flag['c']==1)
	flag['c']=0;
	else
	flag['c']=1;
}
void ANA(char operand)
{
	if(operand!='M')
	registers['A']=registers['A']&registers[operand];
	else
	{
		int address=registers['H']*256+registers['L'];
		registers['A']=registers['A']&memory[address];
	}
}
void ANI(int a)
{
	registers['A']=registers['A']&a;
}
void XRA(char operand)
{
	if(operand!='M')
	registers['A']=registers['A']^registers[operand];
	else
	{
		int address=registers['H']*256+registers['L'];
		registers['A']=registers['A']^memory[address];
	}
}
void XRI(int a)
{
	registers'A'=registers['A']^a;
}
void ORA(char operand)
{
	if(operand!='M')
	registers['A']=registers['A']|registers[operand];
	else
	{
		int address=registers['H']*256+registers['L'];
		registers['A']=registers['A']|memory[address];
	}
}
void ORI(int a)
{
	registers['A']=registers['A']|a;
}
void RLC()
{
	string aBin;
	int i;
	char temp;
	aBin=dectobin(registers['A']);
	flag['c']=aBin[aBin.size()-1]-'0';
	temp=aBin[aBin.size()-1];
	for(i=aBin.size()-2;i>=0;i--)
	{
		aBin[i+1]=aBin[i];
	}
	aBin[0]=temp;
	registers['A']=bintodec(aBin);
}
void RRC()
{
	string aBin;
	int i;
	char temp;
	aBin=dectobin(registers['A']);
	flag['c']=aBin[0]-'0';
	temp=aBin[0];
	for(i=0;i<aBin.size()-1;i++)
	{
		aBin[i]=aBin[i+1];
	}
	aBin[aBin.size()-1]=temp;
	registers['A']=bintodec(aBin);
	
}
void RAL()
{
	string aBin;
	int i;
	char temp;
	aBin=dectobin(registers['A']);
	temp=flag['c'];
	flag['c']=aBin[aBin.size()-1];
	for(i=aBin.size()-2;i>=0;i--)
	{
		aBin[i+1]=aBin[i];
	}
	aBin[0]=temp;
}
void RAR()
{
	string aBin;
	int i;
	char temp;
	aBin=dectobin(registers['A']);
	temp=flag['c'];
	flag['c']=aBin[0];
	for(i=0;i<aBin.size()-1;i++)
	{
		aBin[i]=aBin[i+1];
	}
	aBin[aBin.size()-1]=temp;
	registers['A']=bintodec(aBin);
}
void STC()
{
	flag['c']=1;
}


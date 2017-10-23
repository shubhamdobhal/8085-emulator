void CMA() //complimenting accumulator
{
	registers['A']=255-registers['A'];
}
void CMP(char operand) //comparing register with accumulator
{
			if(operand=='M')
        {
            string address = dectohex(registers['H']*256+registers['L']);
            if(registers['A']>memory[address])//if memory is used
            {
                flag['c']=0;
                flag['z']=0;
            }
            else
            {
                if(registers['A']==memory[address])
                {
                    flag['z']=1;	//only zero flag get affected
                }
                else
                {
                    flag['c']=1;	//if register content is greater then accumulator carry set
                }
            }
        }
        else
        {
			if(registers['A']>registers[operand])
			{
				flag['c']=0; //carry and zero flag get affected
				flag['z']=0;
			}
			else
            {
                if(registers['A']==registers[operand])
                {
                    flag['z']=1;	//only zero flag get affected
                }
                else
                {
                    flag['c']=1;	//if register content is greater then accumulator carry set
                }
            }
        }


}
void SET(string mem,string val)  		//setting a memory location with a value
{
	memory[mem]=hextodec(val);
}
void CMC()		//complimenting carry flag
{
	if(flag['c']==1)
	flag['c']=0;
	else
	flag['c']=1;
}
void ANA(char operand)		//logical and with accumulator
{
	if(operand!='M')
	registers['A']=registers['A']&registers[operand];
	else
	{
		string address=dectohex(registers['H'])+dectohex(registers['L']);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']=registers['A']&memory[address];
	}
}
void ANI(string val)		//and immediate
{
	int a=hextodec(val);
	registers['A']=registers['A']&a;
}
void XRA(char operand)	//xor with accumulator
{
	if(operand!='M')
	registers['A']=registers['A']^registers[operand];
	else
	{
		string address=dectohex(registers['H'])+dectohex(registers['L']);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']=registers['A']^memory[address];
	}
}
void XRI(string val) 	//xor immediate
{
	int a=hextodec(val);
	registers['A']=registers['A']^a;
}
void ORA(char operand)	//or with accumulator
{
	if(operand!='M')
	registers['A']=registers['A']|registers[operand];
	else
	{
		string address=dectohex(registers['H'])+dectohex(registers['L']);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']=registers['A']|memory[address];
	}
}
void ORI(string val)	//or immediate
{
	int a=hextodec(val);
	registers['A']=registers['A']|a;
}
void RLC()		//Rotate left without carry
{
	string aBin;
	int i;
	char temp;
	aBin=dectobin(registers['A']);		//converting into binary(string) form ,stored number is reverse
	flag['c']=aBin[aBin.size()-1]-'0';
	temp=aBin[aBin.size()-1];
	for(i=aBin.size()-2;i>=0;i--)  	//rotating string left
	{
		aBin[i+1]=aBin[i];
	}
	aBin[0]=temp;
	registers['A']=bintodec(aBin);
}
void RRC()		//Rotate right without carry
{
	string aBin;
	int i;
	char temp;
	aBin=dectobin(registers['A']);		//converting into binary,reverse
	flag['c']=aBin[0]-'0';
	temp=aBin[0];
	for(i=0;i<aBin.size()-1;i++)	//rotating right
	{
		aBin[i]=aBin[i+1];
	}
	aBin[aBin.size()-1]=temp;
	registers['A']=bintodec(aBin);

}
void RAL()	//Rotate left with carry
{
	string aBin;
	int i;
	char temp;
	aBin=dectobin(registers['A']);		//converting into binary
	temp=flag['c'];
	flag['c']=aBin[aBin.size()-1];
	for(i=aBin.size()-2;i>=0;i--)
	{
		aBin[i+1]=aBin[i];
	}
	aBin[0]=temp;
	registers['A']=bintodec(aBin);
}
void RAR()	//Rotate right with carry
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
void STC()		//set carry flag
{
	flag['c']=1;
}

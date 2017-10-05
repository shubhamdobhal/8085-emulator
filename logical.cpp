void CMA()
{
	registers[0]=255-registers[0];
}
void CMP(char operand)
{
		switch(operand)
		{
			case A:
				FLAG[1]=1;	
			break;
			case B:			
			if(registers[0]>registers[1])
			{
				FLAG[4]=0;
				FLAG[1]=0;
			}
			else if(registers[0]==registers[1])
			{
				FLAG[1]=1;	
			}	
			else
			{
				FLAG[4]=1;
			}								
			break;
			case C:
			if(registers[0]>registers[2])
			{
				FLAG[4]=0;
				FLAG[1]=0;
			}
			else if(registers[0]==registers[2])
			{
				FLAG[1]=1;	
			}	
			else
			{
				FLAG[4]=1;
			}	
			break;
			case D:
			if(registers[0]>registers[3])
			{
				FLAG[4]=0;
				FLAG[1]=0;
			}
			else if(registers[0]==registers[3])
			{
				FLAG[1]=1;	
			}	
			else
			{
				FLAG[4]=1;
			}	
			break;
			case E:
			if(registers[0]>registers[4])
			{
				FLAG[4]=0;
				FLAG[1]=0;
			}
			else if(registers[0]==registers[4])
			{
				FLAG[1]=1;	
			}	
			else
			{
				FLAG[4]=1;
			}	
			break;
			case H:
			if(registers[0]>registers[5])
			{
				FLAG[4]=0;
				FLAG[1]=0;
			}
			else if(registers[0]==registers[5])
			{
				FLAG[1]=1;	
			}	
			else
			{
				FLAG[4]=1;
			}	
			break;
			case L:
			if(registers[0]>registers[6])
			{
				FLAG[4]=0;
				FLAG[1]=0;
			}
			else if(registers[0]==registers[6])
			{
				FLAG[1]=1;	
			}	
			else
			{
				FLAG[4]=1;
			}	
			break;
			case M:
			int address=registers[5]*256+registers[6];
			if(registers[0]>memory[address])
			{
				FLAG[4]=0;
				FLAG[1]=0;
			}
			else if(registers[0]==memory[address])
			{
				FLAG[1]=1;	
			}	
			else
			{
				FLAG[4]=1;
			}	
			break;
			default:
			throw(exception);
		}
}
void SET(int a)
{
	memory[a]=b;
}
void CMC
{
	if(FLAG[4]==1)
	FLAG[4]=0;
	else
	FLAG[4]=1;
}
void ANA(char operand)
{
	switch(operand)
	{
			case A:
				registers[0]=registers[0]&registers[0];
			break;
			case B:			
				registers[0]=registers[0]&registers[1];
			break;
			case C:
				registers[0]=registers[0]&registers[2];	
			break;
			case D:
				registers[0]=registers[0]&registers[3];	
			break;
			case E:
				registers[0]=registers[0]&registers[4];	
			break;
			case H:
				registers[0]=registers[0]&registers[5];	
			break;
			case L:
				registers[0]=registers[0]&registers[6];	
			break;
			case M:
			int address=registers[5]*256+registers[6];
				registers[0]=registers[0]&memory[address];
			break;
			default:
			throw(exception);
		
	}
}
void ANI(int a)
{
	registers[0]=registers[0]&a;
}
void XRA(char operand)
{
	switch(operand)
	{
			case A:
				registers[0]=registers[0]^registers[0];
			break;
			case B:			
				registers[0]=registers[0]^registers[1];
			break;
			case C:
				registers[0]=registers[0]^registers[2];	
			break;
			case D:
				registers[0]=registers[0]^registers[3];	
			break;
			case E:
				registers[0]=registers[0]^registers[4];	
			break;
			case H:
				registers[0]=registers[0]^registers[5];	
			break;
			case L:
				registers[0]=registers[0]^registers[6];	
			break;
			case M:
			int address=registers[5]*256+registers[6];
				registers[0]=registers[0]^memory[address];
			break;
			default:
			throw(exception);
		
	}
}
void XRI(int a)
{
	registers[0]=registers[0]^a;
}
void ORA(char operand)
{
	switch(operand)
	{
			case A:
				registers[0]=registers[0]|registers[0];
			break;
			case B:			
				registers[0]=registers[0]|registers[1];
			break;
			case C:
				registers[0]=registers[0]|registers[2];	
			break;
			case D:
				registers[0]=registers[0]|registers[3];	
			break;
			case E:
				registers[0]=registers[0]|registers[4];	
			break;
			case H:
				registers[0]=registers[0]|registers[5];	
			break;
			case L:
				registers[0]=registers[0]|registers[6];	
			break;
			case M:
			int address=registers[5]*256+registers[6];
				registers[0]=registers[0]|memory[address];
			break;
			default:
			throw(exception);
		
	}
}
void ORI(int a)
{
	registers[0]=registers[0]|a;
}

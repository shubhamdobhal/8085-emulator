void CMA()
{
	registers[0]=255-registers[0];
}
void CMP(int a,int b)
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
void SET(int a,int b)
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

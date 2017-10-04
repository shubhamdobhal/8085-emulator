void MOV(char operand1,char operand2)
{
		switch(operand1){
		case A:
			switch(operand2)
			{
			case A:
			registers[0]=registers[0];
			break;
			case B:
			registers[0]=registers[1];
			break;
			case C:
			registers[0]=registers[2];
			break;
			case D:
			registers[0]=registers[3];
			break;
			case E:
			registers[0]=registers[4];
			break;
			case H:
			registers[0]=registers[5];
			break;
			case L:
			registers[0]=registers[6];
			break;
			case M:
			int address=registers[5]*256+registers[6];
			registers[0]=memory[address];
			break;
			default:
			throw(exception);
		}
		break;
		case B:
			switch(operand2)
			{
			case A:
			registers[1]=registers[0];
			break;
			case B:
			registers[1]=registers[1];
			break;
			case C:
			registers[1]=registers[2];
			break;
			case D:
			registers[1]=registers[3];
			break;
			case E:
			registers[1]=registers[4];
			break;
			case H:
			registers[1]=registers[5];
			break;
			case L:
			registers[1]=registers[6];
			break;
			case M:
			int address=registers[5]*256+registers[6];
			registers[1]=memory[address];
			break;
			default:
			throw(exception);
		}	
		break;
		case C:
			switch(operand2)
			{
			case A:
			registers[2]=registers[0];
			break;
			case B:
			registers[2]=registers[1];
			break;
			case C:
			registers[2]=registers[2];
			break;
			case D:
			registers[2]=registers[3];
			break;
			case E:
			registers[2]=registers[4];
			break;
			case H:
			registers[2]=registers[5];
			break;
			case L:
			registers[2]=registers[6];
			break;
			case M:
			int address=registers[5]*256+registers[6];
			registers[2]=memory[address];
			break;
			default:
			throw(exception);
		}			
		case D:
			switch(operand2)
			{
			case A:
			registers[3]=registers[0];
			break;
			case B:
			registers[3]=registers[1];
			break;
			case C:
			registers[3]=registers[2];
			break;
			case D:
			registers[3]=registers[3];
			break;
			case E:
			registers[3]=registers[4];
			break;
			case H:
			registers[3]=registers[5];
			break;
			case L:
			registers[3]=registers[6];
			break;
			case M:
			int address=registers[5]*256+registers[6];
			registers[3]=memory[address];
			break;
			default:
			throw(exception);
		}		
		case E:
			switch(operand2)
			{
			case A:
			registers[4]=registers[0];
			break;
			case B:
			registers[4]=registers[1];
			break;
			case C:
			registers[4]=registers[2];
			break;
			case D:
			registers[4]=registers[3];
			break;
			case E:
			registers[4]=registers[4];
			break;
			case H:
			registers[4]=registers[5];
			break;
			case L:
			registers[4]=registers[6];
			break;
			case M:
			int address=registers[5]*256+registers[6];
			registers[4]=memory[address];
			break;
			default:
			throw(exception);
		}		
		case H:
			switch(operand2)
			{
			case A:
			registers[5]=registers[0];
			break;
			case B:
			registers[5]=registers[1];
			break;
			case C:
			registers[5]=registers[2];
			break;
			case D:
			registers[5]=registers[3];
			break;
			case E:
			registers[5]=registers[4];
			break;
			case H:
			registers[5]=registers[5];
			break;
			case L:
			registers[5]=registers[6];
			break;
			case M:
			int address=registers[5]*256+registers[6];
			registers[5]=memory[address];
			break;
			default:
			throw(exception);
		}		
		case L:
			switch(operand2)
			{
			case A:
			registers[6]=registers[0];
			break;
			case B:
			registers[6]=registers[1];
			break;
			case C:
			registers[6]=registers[2];
			break;
			case D:
			registers[6]=registers[3];
			break;
			case E:
			registers[6]=registers[4];
			break;
			case H:
			registers[6]=registers[5];
			break;
			case L:
			registers[6]=registers[6];
			break;
			case M:
			int address=registers[5]*256+registers[6];
			registers[6]=memory[address];
			break;
			default:
			throw(exception);
		}		
		case M:
			int address=registers[5]*256+registers[6];
						switch(operand2)
			{
			case A:
			memory[address]=registers[0];
			break;
			case B:
			memory[address]=registers[1];
			break;
			case C:
			memory[address]=registers[2];
			break;
			case D:
			memory[address]=registers[3];
			break;
			case E:
			memory[address]=registers[4];
			break;
			case H:
			memory[address]=registers[5];
			break;
			case L:
			memory[address]=registers[6];
			break;
			default:
			throw(exception);
		}		
		default:
			throw(exception);
	}
	}
}
void MVI(char operand,int a)
{
			switch(operand)
			{
			case A:
			registers[0]=a;
			break;
			case B:
			registers[1]=a;
			break;
			case C:
			registers[2]=a;
			break;
			case D:
			registers[3]=a;
			break;
			case E:
			registers[4]=a;
			break;
			case H:
			registers[5]=a;
			break;
			case L:
			registers[6]=a;
			break;
			case M:
			int address=registers[5]*256+registers[6];
			memory[address]=a;
			break;
			default:
			throw(exception);
		}		
	
}
void LXI(char operand,int a,int b)
{
		switch(operand)
			{
			case B:
			registers[1]=a;
			registers[2]=b;
			break;
			case D:
			registers[3]=a;
			registers[4]=b;
			break;
			case H:
			registers[5]=a;
			registers[6]=b;
			break;
			default:
			throw(exception);
		}		
		
}
void LDA(int registers[],int b)
{
	registers[0]=memory[b];
}
void STA(int registers[],int b)
{
	memory[b]=registers[0];
}
void LHLD(int registers[],int c)
{
	registers[5]=memory[c];
	registers[6]=memory[c+1];
}
void SHLD(int registers[],int c)
{
	memory[c]=registers[6];
	memory[c+1]=registers[5];
}
void STAX(char operand)
{
	string hex;
	int dec;
	switch(operand)
		{
			case B:
			hex=dectohex(registers[1])+decitohex(registers[2]);
			dec=hextodec(hex);
			memory[dec]=registers[0];
			break;
			case D:
			hex=dectohex(registers[3])+decitohex(registers[4]);
			dec=hextodec(hex);
			memory[dec]=registers[0];
			break;
			case H:
			hex=dectohex(registers[5])+decitohex(registers[6]);
			dec=hextodec(hex);
			memory[dec]=registers[0];
			break;
			default:
			throw(exception);
		}		
		
}
void XCHG()
{
	int a;
	a=registers[3];
	registers[3]=registers[5];
	registers[5]=a;
	a=registers[4];
	registers[4]=registers[6];
	registers[6]=a;
}


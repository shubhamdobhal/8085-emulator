int lenint(int a)
{
	int len=0;
	while(a>0)
	{
		len++;
		a=a/10;
	}
	return len;
}
int hextodec(string str) //for converting hex to decimal
{
	int dec=0,i=4;
	while(i>0)
	{
		if(str[i]=='A'||str[i]=='B'||str[i]=='C'||str[i]=='D'||str[i]=='E'||str[i]=='F')
		{
			if(str[i]=='A')
			{
				dec+=10*pow(16,4-i);
			}
			else if(str[i]=='B')
			{
				dec+=11*pow(16,4-i);
			}
				else if(str[i]=='C')
			{
				dec+=12*pow(16,4-i);
			}
				else if(str[i]=='D')
			{
				dec+=13*pow(16,4-i);
			}
				else if(str[i]=='E')
			{
				dec+=14*pow(16,4-i);
			}
				else 
			{
				dec+=15*pow(16,4-i);
			}
		}
		else
		{
			dec+=(str[i]-'0')*pow(16,4-i);
		}
	}
	
}

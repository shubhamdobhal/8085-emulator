string dectobin(int a)
{
	string str="";
	while(a>0)
	{
		str+=('0'+(a%2));
		a=a/2;
	}
	return str;
}
int bintodec(string str)
{
	int temp,i;
	for(i=0;i<str.size();i++)
	{
		a+=pow(2,i)*(str[i]-'0');
	}
	return a;
}
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

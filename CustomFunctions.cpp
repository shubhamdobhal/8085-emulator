#include "Global.cpp"
//String <--> Integer Conversions
int str_to_int(string str)
{
    int n;
    stringstream ss(str);
    ss>>n;
    return n;
}
string int_to_str(int n)
{
    stringstream ss;
    ss<<n;
    return ss.str();
}

//Finding Index of a character in a String
int indexOf(string s, char c)
{
    for(int i=0;i<s.size();i++)
    {
        if(c==s[i])
        {
            return(i);
        }
    }
    return -1;
}

//Hexadecimal <--> Decimal Conversions
string dectohex(int n)
{
    stringstream ss;
    ss << hex << n;
    return ss.str();
}
int hextodec(string s)
{
    istringstream converter(s);
    int value;
    converter>>hex>>value;
    return value;
}

//Decimal <--> Binary Conversions
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
	int temp,i,a=0;
	for(i=0;i<str.size();i++)
	{
		a+=pow(2,i)*(str[i]-'0');
	}
	return a;
}

//Find length
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

//Find parity
int parity(int a)	//if number of 1 odd return 1 else return 0
{
	int count=0;
	while(a)
	{
		a=a&(a-1);
		count++;
	}
	if(count%2==0)
	return 0;
	else return 1;
}

//Checking for Valid Instruction which have operands
int insturctionPresent(string s)
{
    if(s=="ADD"||s=="SUB"||s=="CMP"||s=="INR"||s=="DCR"||s=="LDA"||s=="STA"||s=="LHLD"||s=="SHLD"||s=="JMP"||s=="JC"||s=="JNC"||s=="JZ"||s=="JNZ"||s=="ADI"||s=="SUI"||s=="STAX"||s=="DAD"||s=="INX"||s=="DCX"||s=="MOV"||s=="LXI"||s=="MVI"||s=="SET")
    {
        return 1;
    }
    return 0;
}

//Checking operands
bool check0(string s)
{
    if(s=="XCHG"||s=="CMA"||s=="NOP"||s=="DI"||s=="EI"||s=="RIM"||s=="SIM"||s=="RLC"||s=="RRC"||s=="RAR"||s=="RAL"||s=="CMC"||s=="STC"||s=="RET"||s=="RC"||s=="RNC"||s=="RP"||s=="RM"||s=="RZ"||s=="RNZ"||s=="RPE"||s=="RPO"||s=="PCHL"||s=="DAA"||s=="SPHL"||s=="XTHL")
    {
        return 1;
    }
    return 0;
}
bool check1(string s)
{
    string a[] = {"A","B","C","D","E","H","L","M","a","b","c","d","e","h","l","m"};
    for(int i=0;i<8;i++)
    {
        if(a[i] == s)
        {
            return 1;
        }
    }
    return 0;
}
bool check2(string s)
{
    int flag=0;
    if(s.size()==4)
    {
        for(int i=0;i<4;i++)
        {
            if(!((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='F') || (s[i]>='a' && s[i]<='f')))
            {
                    flag = 1;
            }
        }
        if(flag==0)
        {
            return 1;
        }
    }
    return 0;
}
bool check3(string s)
{
    int flag=0;
    if(s.size()==2)
    {
        for(int i=0;i<2;i++)
        {
            if(!((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='F') || (s[i]>='a' && s[i]<='f')))
            {
                    flag = 1;
            }
        }
        if(flag==0)
        {
            return 1;
        }
    }
    return 0;
}
bool check4(string s)
{
    if(s=="B" || s=="D" || s=="H" || s=="b" || s=="d" || s=="h")
    {
        return 1;
    }
    return 0;
}
bool check5(string s)
{
    int f = indexOf(s,',');
    if(f!=-1)
    {
        string s1,s2;
        s1 = s.substr(0,1);
        s2 = s.substr(f+1,1);
        if(check1(s1) && check1(s2)&& (s1!=s2))
        {
            return 1;
        }
    }
    return 0;
}
bool check6(string s)
{
    int f = indexOf(s,',');
    if(f>-1)
    {
        string s1,s2;
        s1 = s.substr(0,1);
        s2 = s.substr(f+1,2);
        if(check1(s1) && check3(s2))
        {
            return 1;
        }
    }
    return 0;
}
bool check7(string s)
{
    int f = indexOf(s,',');
    if(f!=-1)
    {
        string s1,s2;
        s1 = s.substr(0,1);
        s2 = s.substr(f+1,4);
        if(check4(s1) && check2(s2))
        {
            return 1;
        }
    }
    return 0;
}
bool check8(string s)
{
    int f = indexOf(s,',');
    if(f!=-1)
    {
        string s1,s2;
        s1 = s.substr(0,4);
        s2 = s.substr(f+1,2);
        if(check2(s1) && check3(s2))
        {
            return 1;
        }
    }
    return 0;
}

//flags related functions.........
void check_flags_1(char operand){				//to check flags for dcr, inr .....,carry flag never changes
	if(registers[operand]==0 || registers[operand]==128 || registers[operand]==-129){
		flag['z']=1;
		registers[operand]=0;
	}
	else{
		flag['z']=0;
	}
	//code for checking parity and auxilarry carry.............
}
void check_flags_2(){							//to check flags for add,sub........
	if(registers['A']<0){
		flag['s']=1;
		if(registers['A']<(-128)){
			flag['c']=1;		//if carry
			registers['A']=129-registers['A'];
		}
	}
	else{
		flag['s']=0;
		flag['c']=registers['A']/128;		//if carry
		registers['A']%=128;
	}
	if(registers['A']==0)
		flag['z']=1;
	else
		flag['z']=0;
	//code for checking auxilarry and parity flag..............
}

//Reset all Flags
void reset_flags()
{
    flag['z'] = 0;
    flag['s'] = 0;
    flag['c'] = 0;
    flag['p'] = 0;
    flag['a'] = 0;
}

//Reset all Registers
void reset_registers()
{
    registers['A'] = 0;
    registers['B'] = 0;
    registers['C'] = 0;
    registers['D'] = 0;
    registers['E'] = 0;
    registers['H'] = 0;
    registers['L'] = 0;
}

//Setting size of instructions
void set_instructions_size()
{
    inst_size["MOV"] = 1;
    inst_size["XCHG"] = 1;
    inst_size["ADD"] = 1;
    inst_size["SUB"] = 1;
    inst_size["INR"] = 1;
    inst_size["DCR"] = 1;
    inst_size["INX"] = 1;
    inst_size["DCX"] = 1;
    inst_size["DAD"] = 1;
    inst_size["CMA"] = 1;
    inst_size["CMP"] = 1;
    inst_size["NOP"] = 1;
    inst_size["DI"] = 1;
    inst_size["EI"] = 1;
    inst_size["RIM"] = 1;
    inst_size["SIM"] = 1;
    inst_size["ANA"] = 1;
    inst_size["XRA"] = 1;
    inst_size["ORA"] = 1;
    inst_size["RLC"] = 1;
    inst_size["RRC"] = 1;
    inst_size["RAL"] = 1;
    inst_size["RAR"] = 1;
    inst_size["CMC"] = 1;
    inst_size["STC"] = 1;
    inst_size["RET"] = 1;
    inst_size["RC"] = 1;
    inst_size["RNC"] = 1;
    inst_size["RP"] = 1;
    inst_size["RM"] = 1;
    inst_size["RZ"] = 1;
    inst_size["RNZ"] = 1;
    inst_size["RPE"] = 1;
    inst_size["RPO"] = 1;
    inst_size["PCHL"] = 1;
    inst_size["ADC"] = 1;
    inst_size["SBB"] = 1;
    inst_size["DAA"] = 1;
    inst_size["SPHL"] = 1;
    inst_size["XTHL"] = 1;
    inst_size["PUSH"] = 1;
    inst_size["POP"] = 1;
    inst_size["MVI"] = 2;
    inst_size["ADI"] = 2;
    inst_size["SUI"] = 2;
    inst_size["MVI"] = 2;
    inst_size["CPI"] = 2;
    inst_size["ANI"] = 2;
    inst_size["XRI"] = 2;
    inst_size["ORI"] = 2;
    inst_size["SBI"] = 2;
    inst_size["ACI"] = 2;
    inst_size["OUT"] = 2;
    inst_size["IN"] = 2;
    inst_size["LXI"] = 3;
    inst_size["LDA"] = 3;
    inst_size["STA"] = 3;
    inst_size["LHLD"] = 3;
    inst_size["SHLD"] = 3;
    inst_size["STAX"] = 3;
    inst_size["JMP"] = 3;
    inst_size["JC"] = 3;
    inst_size["JNC"] = 3;
    inst_size["JZ"] = 3;
    inst_size["JNZ"] = 3;
    inst_size["CC"] = 3;
    inst_size["CNC"] = 3;
    inst_size["CP"] = 3;
    inst_size["CM"] = 3;
    inst_size["CZ"] = 3;
    inst_size["CNZ"] = 3;
    inst_size["CPE"] = 3;
    inst_size["CPO"] = 3;
    inst_size["SET"] = 4;
}

//Setting addressing modes of instructions
void set_instructions()
{
    commands["XCHG"] = 0;
    commands["CMA"] = 0;
    commands["NOP"] = 0;
    commands["DI"] = 0;
    commands["EI"] = 0;
    commands["RIM"] = 0;
    commands["SIM"] = 0;
    commands["RLC"] = 0;
    commands["RRC"] = 0;
    commands["RAL"] = 0;
    commands["RAR"] = 0;
    commands["CMC"] = 0;
    commands["STC"] = 0;
    commands["RET"] = 0;
    commands["RC"] = 0;
    commands["RNC"] = 0;
    commands["RP"] = 0;
    commands["RM"] = 0;
    commands["RZ"] = 0;
    commands["RNZ"] = 0;
    commands["RPE"] = 0;
    commands["RPO"] = 0;
    commands["PCHL"] = 0;
    commands["DAA"] = 0;
    commands["SPHL"] = 0;
    commands["XTHL"] = 0;
    commands["ANA"] = 1;
    commands["XRA"] = 1;
    commands["ORA"] = 1;
    commands["ADC"] = 1;
    commands["SBB"] = 1;
    commands["SUB"] = 1;
    commands["ADD"] = 1;
    commands["INR"] = 1;
    commands["DCR"] = 1;
    commands["CMP"] = 1;
    commands["CC"] = 2;
    commands["CNC"] = 2;
    commands["CP"] = 2;
    commands["CM"] = 2;
    commands["CZ"] = 2;
    commands["CNZ"] = 2;
    commands["CPE"] = 2;
    commands["CPO"] = 2;
    commands["LDA"] = 2;
    commands["STA"] = 2;
    commands["LHLD"] = 2;
    commands["SHLD"] = 2;
    commands["JMP"] = 2;
    commands["JC"] = 2;
    commands["JNC"] = 2;
    commands["JZ"] = 2;
    commands["JNZ"] = 2;
    commands["ADI"] = 3;
    commands["SUI"] = 3;
    commands["CPI"] = 3;
    commands["ANI"] = 3;
    commands["XRI"] = 3;
    commands["ORI"] = 3;
    commands["ADI"] = 3;
    commands["SBI"] = 3;
    commands["IN"] = 3;
    commands["OUT"] = 3;
    commands["PUSH"] = 4;
    commands["POP"] = 4;
    commands["STAX"] = 4;
    commands["INX"] = 4;
    commands["DCX"] = 4;
    commands["DAD"] = 4;
    commands["MOV"] = 5;
    commands["MVI"] = 6;
    commands["LXI"] = 7;
    commands["SET"] = 8;
}

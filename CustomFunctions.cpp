#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
using namespace std;
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
int insturctionPresent(string s)
{
    if(s=="ADD"||s=="SUB"||s=="CMP"||s=="INR"||s=="DCR"||s=="LDA"||s=="STA"||s=="LHLD"||s=="SHLD"||s=="JMP"||s=="JC"||s=="JNC"||s=="JZ"||s=="JNZ"||s=="ADI"||s=="SUI"||s=="STAX"||s=="DAD"||s=="INX"||s=="DCX"||s=="MOV"||s=="LXI"||s=="MVI"||s=="SET")
    {
        return 1;
    }
    return 0;
}

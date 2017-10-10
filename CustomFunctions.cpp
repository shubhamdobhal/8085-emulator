#include<bits/stdc++.h>
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

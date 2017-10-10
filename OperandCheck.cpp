#include "CustomFunctions.cpp"
bool check0(string s)
{
    if(s=="XCHG"||s=="CMA"||s=="EOF"||s=="HLT")
    {
        return 1;
    }
    return 0;
}
bool check1(string s)
{
    string a[] = {"A","B","C","D","E","H","L","M"};
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
            if(!((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='F')))
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
            if(!((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='F')))
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
    if(s=="B" || s=="D" || s=="H")
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
        s1 = s.substr(0,f);
        s2 = s.substr(f+1,s.size());
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
        s1 = s.substr(0,f);
        s2 = s.substr(f+1,s.size());
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
        s1 = s.substr(0,f);
        s2 = s.substr(f+1,s.size());
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
        s1 = s.substr(0,f);
        s2 = s.substr(f+1,s.size());
        if(check2(s1) && check3(s2))
        {
            return 1;
        }
    }
    return 0;
}

#include "OperandCheck.cpp"

int number_of_lines = 0, break_point = INT_MAX,memregflag=0,pc,line_number = 1;
string program_counter,start_address;
map<string,int> commands;
map<string,int> inst_size;
map<string,string> RAM;
map<int,int> memory;
map<char,int> registers;

void XCHG(){}
void CMA(){}

void ADD(string s){}
void SUB(string s){}
void INR(string s){}
void DCR(string s){}
void CMP(string s){}

void LDA(string s){}
void STA(string s){}
void LHLD(string s){}
void SHLD(string s){}
void JMP(string s){}
void JC(string s){}
void JNC(string s){}
void JZ(string s){}
void JNZ(string s){}

void ADI(string s){}
void SUI(string s){}

void STAX(string s){}
void DAD(string s){}
void INX(string s){}
void DCX(string s){}

void MOV(string s1,string s2){}

void MVI(string s1, string s2){}

void LXI(string s1, string s2){}

void SET(string s1, string s2){}

void set_instructions_size()
{
    inst_size["MOV"] = 1;
    inst_size["MVI"] = 2;
    inst_size["LXI"] = 3;
    inst_size["LDA"] = 3;
    inst_size["STA"] = 3;
    inst_size["LHLD"] = 3;
    inst_size["SHLD"] = 3;
    inst_size["STAX"] = 3;
    inst_size["XCHG"] = 1;
    inst_size["ADD"] = 1;
    inst_size["ADI"] = 2;
    inst_size["SUB"] = 1;
    inst_size["INR"] = 1;
    inst_size["DCR"] = 1;
    inst_size["INX"] = 1;
    inst_size["DCX"] = 1;
    inst_size["DAD"] = 1;
    inst_size["SUI"] = 2;
    inst_size["CMA"] = 1;
    inst_size["CMP"] = 1;
    inst_size["JMP"] = 3;
    inst_size["JC"] = 3;
    inst_size["JNC"] = 3;
    inst_size["JZ"] = 3;
    inst_size["JNZ"] = 3;
    inst_size["SET"] = 4;
}
void set_instructions()
{
    commands["MOV"] = 5;
    commands["MVI"] = 6;
    commands["LXI"] = 7;
    commands["LDA"] = 2;
    commands["STA"] = 2;
    commands["LHLD"] = 2;
    commands["SHLD"] = 2;
    commands["STAX"] = 4;
    commands["XCHG"] = 0;
    commands["ADD"] = 1;
    commands["ADI"] = 3;
    commands["SUB"] = 1;
    commands["INR"] = 1;
    commands["DCR"] = 1;
    commands["INX"] = 4;
    commands["DCX"] = 4;
    commands["DAD"] = 4;
    commands["SUI"] = 3;
    commands["CMA"] = 0;
    commands["CMP"] = 1;
    commands["JMP"] = 2;
    commands["JC"] = 2;
    commands["JNC"] = 2;
    commands["JZ"] = 2;
    commands["JNZ"] = 2;
    commands["SET"] = 8;
}
void break_point_set(int ch)
{
    cout<<"Enter line number to set break point:\n";
    cin>>break_point;
    if(break_point==1 && ch==1)
    {
        cout<<"Break point cannot set at line number 1 !\n\n";
        break_point = INT_MAX;
    }
    else
    {
        if(break_point>number_of_lines || break_point<1)
        {
            cout<<"Line number does not exist !\n\n";
            break_point = INT_MAX;
        }
        else
        {
            cout<<"Break point Set !\n\n";
        }
    }
}
void help()
{
    cout<<"\nHELP:\n";
    cout<<"1. break or b :- It will set break point on given line number.\n";
    cout<<"2. run or r :- Run the program until it ends or breakpoint is encountered.\n";
    cout<<"3. step or s :- It will run the program one instruction at a time.\n";
    cout<<"4. print or p :- It prints the value of register or memory location.\n   For ex 'p A' will print the value of register A.\n   'p 2500' will print the value at memory location 2500 if any.\n";
    cout<<"5. quit or q :- Quits the debugger\n";
    cout<<"6. help or h :- Will show all commands of the debugger\n\n";
}
void print()
{
    string memreg;
    cout<<"Enter register or memory location:\n";
    getline(cin,memreg);
    if(memreg.size()==1)
    {
        cout<<registers[toupper(memreg[0])]<<endl;
    }
    else
    {
        if(memreg.size()==4)
        {
            for(int i=0;i<4;i++)
            {
                if(!((memreg[i]>='0' && memreg[i]<='9') || (memreg[i]>='A' && memreg[i]<='F')))
                {
                    memregflag=1;
                    cout<<"Invalid Address !\n\n";
                    break;
                }
            }
            if(memregflag==0)
            {
                cout<<memory[hextodec(memreg)]<<"\n";
            }
        }
        else
        {
            cout<<"Invalid Address !\n\n";
        }
    }
}
void display()
{

}
void stepORrun(int op)
{
    string s1,s2,s3,s4,o;
    int f=0;
    //cout<<number_of_lines<<endl<<line_number<<endl<<break_point<<endl;
    while(op)
    {

    if(op==1)
    {
        f=1;
    }
    if((line_number==break_point || line_number==number_of_lines))
    {
        f=1;
        if(line_number==break_point)
        {
            cout<<"Program executed till break point!\n";
        }
        else
        {
            cout<<"Program fully executed!\n";
        }
    }
    else
    {
        s1 = RAM[program_counter];
        if(s1.size()==3 || s1.size()==4)
        {
            if(s1=="CMA")
            {
                CMA();
                pc = hextodec(program_counter);
                pc = pc + inst_size[s1];
                program_counter = dectohex(pc);
            }
            else
            {
                if(s1=="XCHG")
                {
                    XCHG();
                    pc = hextodec(program_counter);
                    pc = pc + inst_size[s1];
                    program_counter = dectohex(pc);
                }
                else
                {
                    if(s1=="EOF" || s1=="HLT")
                    {
                        cout<<"Program fully executed!\n";
                        f=1;
                    }
                    else
                    {
                        cout<<"Invalid Instruction or Operand Missing at line number "<<line_number<<"!\n";
                        f=1;
                        --line_number;
                    }
                }
            }
        }
        else
        {
            if(s1.size()>4)
            {
                s2 = s1.substr(0,indexOf(s1,' '));
                o = s1.substr(indexOf(s1,' ')+1,s1.size());
                switch(commands[s2])
                {
                    case 1: if(check1(o))
                            {
                                if(s2=="ADD")
                                {
                                    ADD(o);
                                }
                                if(s2=="SUB")
                                {
                                    SUB(o);
                                }
                                if(s2=="INR")
                                {
                                    INR(o);
                                }
                                if(s2=="DCR")
                                {
                                    DCR(o);
                                }
                                if(s2=="CMP")
                                {
                                    CMP(o);
                                }
                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"Invalid Operand(s) at line number "<<line_number<<"!\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 2: if(check2(o))
                            {
                                if(s2=="LDA")
                                {
                                    LDA(o);
                                }
                                if(s2=="STA")
                                {
                                    STA(o);
                                }
                                if(s2=="LHLD")
                                {
                                    LHLD(o);
                                }
                                if(s2=="SHLD")
                                {
                                    SHLD(o);
                                }
                                if(s2=="JMP")
                                {
                                    JMP(o);
                                }
                                if(s2=="JC")
                                {
                                    JC(o);
                                }
                                if(s2=="JNC")
                                {
                                    JNC(o);
                                }
                                if(s2=="JZ")
                                {
                                    JZ(o);
                                }
                                if(s2=="JNZ")
                                {
                                    JNZ(o);
                                }
                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"Invalid Operand(s) at line number "<<line_number<<"!\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 3: if(check3(o))
                            {
                                if(s2=="ADI")
                                {
                                    ADI(o);
                                }
                                if(s2=="SUI")
                                {
                                    SUI(o);
                                }
                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"Invalid Operand(s) at line number "<<line_number<<"!\n";
                                --line_number;
                                f=1;
                            }
                            break;
                    case 4: if(check4(o))
                            {
                                if(s2=="STAX")
                                {
                                    STAX(o);
                                }
                                if(s2=="DAD")
                                {
                                    DAD(o);
                                }
                                if(s2=="INX")
                                {
                                    INX(o);
                                }
                                if(s2=="DCX")
                                {
                                    DCX(o);
                                }
                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"Invalid Operand(s) at line number "<<line_number<<"!\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 5: if(check5(o))
                            {
                                s3 = s1.substr(indexOf(s1,' ')+1,indexOf(s1,','));
                                s4 = s1.substr(indexOf(s1,',')+1,s1.size());
                                if(s2=="MOV")
                                {
                                    MOV(s3,s4);
                                }
                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"Invalid Operand(s) at line number "<<line_number<<"!\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 6: if(check6(o))
                            {
                                s3 = s1.substr(indexOf(s1,' ')+1,indexOf(s1,','));
                                s4 = s1.substr(indexOf(s1,',')+1,s1.size());
                                if(s2=="MVI")
                                {
                                    MVI(s3,s4);
                                }
                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"Invalid Operand(s) at line number "<<line_number<<"!\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 7: if(check7(o))
                            {
                                s3 = s1.substr(indexOf(s1,' ')+1,indexOf(s1,','));
                                s4 = s1.substr(indexOf(s1,',')+1,s1.size());
                                if(s2=="LXI")
                                {
                                    LXI(s3,s4);
                                }
                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"Invalid Operand(s) at line number "<<line_number<<"!\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 8: if(check8(o))
                            {
                                s3 = s1.substr(indexOf(s1,' ')+1,indexOf(s1,','));
                                s4 = s1.substr(indexOf(s1,',')+1,s1.size());
                                if(s2=="SET")
                                {
                                    SET(s3,s4);
                                }
                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"Invalid Operand(s) at line number "<<line_number<<"!\n";
                                f=1;
                                --line_number;
                            }
                }
            }
            else
            {
                cout<<"Invalid instruction present!\n";
                f=1;
            }
        }
        ++line_number;
    }
    if(f==1)
    {
        break;
    }

    }
}
void debugger(int file)
{
    char ch;
    set_instructions();
    if(file==1)
    {
        string line;
        ifstream code;
        code.open("inputF.txt",ios::in);
        while(!code.eof())
        {
            getline(code,line);
            if(line_number==1)
            {
                program_counter = line;
                start_address = line;
                //cout<<program_counter<<" "<<start_address<<endl;
                line_number = 2;
                continue;
            }
            if(line=="\0")
            {
                --number_of_lines;
            }
            else
            {
                RAM[program_counter] = line;
                pc = hextodec(program_counter);
                if(line.size()==3 || line.size()==4)
                {
                    pc += inst_size[line];
                }
                else
                {
                    pc += inst_size[line.substr(0,indexOf(line,' '))];
                }
                program_counter = dectohex(pc);
            }
            ++number_of_lines;
            //cout<<number_of_lines<<endl;
        }
        //cout<<number_of_lines<<endl; //number of lines
        code.close();
        number_of_lines++;
    }
    /*else
    {
        line_number = 1;
    }*/
    //cout<<number_of_lines<<endl;
    program_counter = start_address;
    cout<<"\nCommands:\n";
    cout<<"For Break: b\t";
    cout<<"For Run: r\t";
    cout<<"For Step: s\n";
    cout<<"For Print: p\t";
    cout<<"For Quit: q\t";
    cout<<"For Help: h\n\n";
    do
    {
        memregflag = 0;
        cout<<"Enter Command:\n";
        cin>>ch;
        ch=tolower(ch);
        fflush(stdin);
        switch(ch)
        {
            case 'b':break_point_set(file);
                     break;
            case 'h':help();
                     break;
            case 'p':print();
                     break;
            case 'r':stepORrun(2);
                     break;
            case 's':stepORrun(1);
                     break;
            default:if(ch!='q')
                    {
                        cout<<"Invalid Input ! Try Again !\n\n";
                    }
        }
    }while(ch!='q');
}

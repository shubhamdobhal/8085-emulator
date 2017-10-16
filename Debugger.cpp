#include "OperandCheck.cpp"
#include "DummyInstructions.cpp"

int number_of_lines = 0, break_point = INT_MAX,memregflag=0,pc,line_number = 1,dp=0;
string program_counter,start_address;
map<string,int> commands;
map<string,int> inst_size;
map<string,string> RAM;
map<string,int> memory;
map<char,int> registers;
map<char,int> flags;
vector<string> memoryLocationsUsed;

void SET(string l, string v)
{
    memory[l] = hextodec(v);
}
void STA(string l)
{
    memory[l] = registers['A'];
}
void LDA(string l)
{
    registers['A'] = memory[l];
}
void ADD(string s)
{
    registers['A'] += registers[s[0]];
    if(registers['A']>255)
    {
        registers['A'] = registers['A']%256;
        flags['c'] = 1;
    }
}
void MOV(string d, string s)
{
    registers[d[0]] = registers[s[0]];
}

void reset_flags()
{
    flags['z'] = 0;
    flags['s'] = 0;
    flags['c'] = 0;
    flags['p'] = 0;
    flags['a'] = 0;
}
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
void display()
{
    if(dp==0)
    {
        int i;
        cout<<"Values in Registers:\n";
        char ch;
        for(ch='A';ch<='E';ch++)
        {
            cout<<ch<<" : "<<dectohex(registers[ch])<<endl;
        }
        cout<<"H : "<<dectohex(registers['H'])<<endl<<"L : "<<dectohex(registers['L'])<<endl;
        cout<<"Values of Flags:\n";
        cout<<"Z :"<<flags['z']<<endl<<"S :"<<flags['s']<<endl<<"C :"<<flags['c']<<endl<<"P :"<<flags['p']<<endl<<"A :"<<flags['a']<<endl;
        cout<<"Memory Locations Used:"<<endl;
        if(memoryLocationsUsed.size())
        {
            for(i=0;i<memoryLocationsUsed.size();i++)
            {
                cout<<memoryLocationsUsed[i]<<" : "<<dectohex(memory[memoryLocationsUsed[i]])<<endl;
            }
        }
        else
        {
            cout<<"None!"<<endl;
        }
    }
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
                cout<<memory[memreg]<<"\n";
            }
        }
        else
        {
            cout<<"Invalid Address !\n\n";
        }
    }
}
void stepORrun(int op)
{
    string s1,s2,s3,s4,o;
    int f=0;
    while(op)
    {

    if(op==1)
    {
        f=1;
    }
    if((line_number==break_point || line_number==number_of_lines))
    {
        f=1;
        if(line_number==number_of_lines)
        {
            cout<<"Program fully executed!\n";
            display();
            ++dp;
        }
        else
        {
            cout<<"Program executed till break point!\n";
            display();
        }
    }
    else
    {
        s1 = RAM[program_counter];
        if(s1.size()==3 || s1.size()==4 || s1.size()==2)
        {
            if(s1!="EOF" && s1!="HLT" && check0(s1))
            {
                if(s1=="NOP")
                     NOP();
                if(s1=="DI")
                    DI();
                if(s1=="EI")
                    EI();
                if(s1=="RIM")
                    RIM();
                if(s1=="SIM")
                    SIM();
                if(s1=="RLC")
                    RLC();
                if(s1=="RRC")
                    RRC();
                if(s1=="RAL")
                    RAL();
                if(s1=="RAR")
                    RAR();
                if(s1=="CMC")
                    CMC();
                if(s1=="STC")
                    STC();
                if(s1=="RET")
                    RET();
                if(s1=="RC")
                    RC();
                if(s1=="RNC")
                    RNC();
                if(s1=="RP")
                    RP();
                if(s1=="RM")
                    RM();
                if(s1=="RZ")
                    RZ();
                if(s1=="RNZ")
                    RNZ();
                if(s1=="RPE")
                    RPE();
                if(s1=="RPO")
                    RPO();
                if(s1=="PCHL")
                    PCHL();
                if(s1=="DAA")
                    DAA();
                if(s1=="SPHL")
                    SPHL();
                if(s1=="XTHL")
                    XTHL();

                pc = hextodec(program_counter);
                pc = pc + inst_size[s1];
                program_counter = dectohex(pc);

            }
            else
            {
                if(s1=="EOF" || s1=="HLT")
                {
                    cout<<"Program fully executed!\n";
                    display();
                    f=1;
                }
                else
                {
                    cout<<"Operand Missing at line number(s) "<<line_number<<"!\n";
                    f=1;
                    --line_number;
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
                                    ADD(o);
                                if(s2=="SUB")
                                    SUB(o);
                                if(s2=="INR")
                                    INR(o);
                                if(s2=="DCR")
                                    DCR(o);
                                if(s2=="CMP")
                                    CMP(o);
                                if(s2=="ANA")
                                    ANA(o);
                                if(s2=="XRA")
                                    XRA(o);
                                if(s2=="ORA")
                                    ORA(o);
                                if(s2=="ADC")
                                    ADC(o);
                                if(s2=="SBB")
                                    SBB(o);

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
                                    LDA(o);
                                if(s2=="STA")
                                {
                                    STA(o);
                                    memoryLocationsUsed.push_back(o);
                                }
                                if(s2=="LHLD")
                                    LHLD(o);
                                if(s2=="SHLD")
                                    SHLD(o);
                                if(s2=="JMP")
                                    JMP(o);
                                if(s2=="JC")
                                    JC(o);
                                if(s2=="JNC")
                                    JNC(o);
                                if(s2=="JZ")
                                    JZ(o);
                                if(s2=="JNZ")
                                    JNZ(o);
                                if(s2=="CC")
                                    CC(o);
                                if(s2=="CNC")
                                    CNC(o);
                                if(s2=="CP")
                                    CP(o);
                                if(s2=="CM")
                                    CM(o);
                                if(s2=="CZ")
                                    CZ(o);
                                if(s2=="CNZ")
                                    CNZ(o);
                                if(s2=="CPE")
                                    CPE(o);
                                if(s2=="CPO")
                                    CPO(o);

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
                                    ADI(o);
                                if(s2=="SUI")
                                    SUI(o);
                                if(s2=="ACI")
                                    ACI(o);
                                if(s2=="SBI")
                                    SBI(o);
                                if(s2=="CPI")
                                    CPI(o);
                                if(s2=="IN")
                                    IN(o);
                                if(s2=="OUT")
                                    OUT(o);

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
                                    STAX(o);
                                if(s2=="DAD")
                                    DAD(o);
                                if(s2=="INX")
                                    INX(o);
                                if(s2=="DCX")
                                    DCX(o);
                                if(s2=="PUSH")
                                    PUSH(o);
                                if(s2=="POP")
                                    POP(o);
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
                                s3 = s1.substr(indexOf(s1,' ')+1,1);
                                s4 = s1.substr(indexOf(s1,',')+1,1);
                                if(s2=="MOV")
                                    MOV(s3,s4);

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
                                s3 = s1.substr(indexOf(s1,' ')+1,1);
                                s4 = s1.substr(indexOf(s1,',')+1,2);
                                if(s2=="MVI")
                                    MVI(s3,s4);

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
                                s3 = s1.substr(indexOf(s1,' ')+1,1);
                                s4 = s1.substr(indexOf(s1,',')+1,4);
                                if(s2=="LXI")
                                    LXI(s3,s4);

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
                                s3 = s1.substr(indexOf(s1,' ')+1,4);
                                s4 = s1.substr(indexOf(s1,',')+1,2);
                                if(s2=="SET")
                                {
                                    SET(s3,s4);
                                    memoryLocationsUsed.push_back(s3);
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
    reset_flags();
    reset_registers();
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

#include "DataTransferInstructions.cpp"

void display()
{
    if(dp==0)
    {
        int i;
        cout<<"Values in Registers:\n";
        char ch;
        string s;
        for(ch='A';ch<='E';ch=ch+1)
        {
            s = dectohex(registers[ch]);
            cout<<ch<<" : "<<((s.size()==1)?("0"+s):s)<<endl;
        }
        s = dectohex(registers['H']);
        cout<<"H : "<<((s.size()==1)?("0"+s):s)<<endl;
        s = dectohex(registers['L']);
        cout<<"L : "<<((s.size()==1)?("0"+s):s)<<endl;
        cout<<"\nValues of Flags:\n";
        cout<<"Z  : "<<flag['z']<<endl<<"S  : "<<flag['s']<<endl<<"C  : "<<flag['c']<<endl<<"P  : "<<flag['p']<<endl<<"AC : "<<flag['a']<<endl;
        cout<<"\nMemory Locations Used:"<<endl;
        if(memoryLocationsUsed.size())
        {
            for(i=0;i<memoryLocationsUsed.size();i++)
            {
                s = dectohex(memory[memoryLocationsUsed[i]]);
                cout<<memoryLocationsUsed[i]<<" : "<<((s.size()==1)?("0"+s):s)<<endl;
            }
        }
        else
        {
            cout<<"None!"<<endl;
        }
        cout<<endl;
    }
}

void break_point_set(int ch)
{
    cout<<"\nEnter line number to set break point:\n";
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
            cout<<"\nLine number does not exist !\n\n";
            break_point = INT_MAX;
        }
        else
        {
            cout<<"\nBreak point Set !\n\n";
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
                cout<<dectohex(memory[memreg])<<"\n";
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
    //cout<<program_counter<<endl;
    if(op==1)
    {
        f=1;
    }
    if(line_number==break_point+1 || RAM[program_counter]=="HLT" || RAM[program_counter]=="EOF")
    {
        f=1;
        if(RAM[program_counter]=="HLT" || RAM[program_counter]=="EOF")
        {
            cout<<"\nProgram fully executed!\n\n";
            display();
            ++dp;
        }
        else
        {
            cout<<"\nProgram executed till break point!\n\n";
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
                if(s1=="SPHL")
                    SPHL();
                if(s1=="XTHL")
                    XTHL();
                if(s1=="CMA")
                    CMA();
                if(s1=="XCHG")
                    XCHG();

                pc = hextodec(program_counter);
                pc = pc + inst_size[s1];
                program_counter = dectohex(pc);

            }
            else
            {
                if(s1=="EOF" || s1=="HLT")
                {
                    cout<<"\nProgram fully executed!\n";
                    display();
                    f=1;
                }
                else
                {
                    cout<<"\nOperand Missing at line number(s) "<<line_number<<"!\n\n";
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
                                    ADD(o[0]);
                                if(s2=="SUB")
                                    SUB(o[0]);
                                if(s2=="INR")
                                    INR(o[0]);
                                if(s2=="DCR")
                                    DCR(o[0]);
                                if(s2=="CMP")
                                    CMP(o[0]);
                                if(s2=="ANA")
                                    ANA(o[0]);
                                if(s2=="XRA")
                                    XRA(o[0]);
                                if(s2=="ORA")
                                    ORA(o[0]);
                                if(s2=="ADC")
                                    ADC(o[0]);
                                if(s2=="SBB")
                                    SBB(o[0]);

                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"\nInvalid Operand(s) at line number "<<line_number<<"!\n\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 2: if(check2(o))
                            {
                                if(s2=="LDA")
                                {
                                    LDA(o);
                                    pc = hextodec(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = dectohex(pc);
                                }
                                if(s2=="STA")
                                {
                                    memoryLocationsUsed.push_back(o);
                                    STA(o);
                                    pc = hextodec(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = dectohex(pc);
                                }
                                if(s2=="LHLD")
                                {
                                    LHLD(o);
                                    pc = hextodec(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = dectohex(pc);
                                }
                                if(s2=="SHLD")
                                {
                                    SHLD(o);
                                    pc = hextodec(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = dectohex(pc);
                                }
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
                            }
                            else
                            {
                                cout<<"\nInvalid Operand(s) at line number "<<line_number<<"!\n\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 3: if(check3(o))
                            {
                                if(s2=="ADI")
                                    ADI(o);
                                if(s2=="ANI")
                                    ANI(o);
                                if(s2=="ORI")
                                    ORI(o);
                                if(s2=="SUI")
                                    SUI(o);
                                if(s2=="XRI")
                                    XRI(o);
                                if(s2=="ACI")
                                    ACI(o);
                                if(s2=="SBI")
                                    SBI(o);

                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"\nInvalid Operand(s) at line number "<<line_number<<"!\n\n";
                                --line_number;
                                f=1;
                            }
                            break;
                    case 4: if(check4(o))
                            {
                                if(s2=="STAX")
                                    STAX(o[0]);
                                if(s2=="DAD")
                                    DAD(o[0]);
                                if(s2=="INX")
                                    INX(o[0]);
                                if(s2=="DCX")
                                    DCX(o[0]);
                                if(s2=="PUSH")
                                    PUSH(o[0]);
                                if(s2=="POP")
                                    POP(o[0]);
                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"\nInvalid Operand(s) at line number "<<line_number<<"!\n\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 5: if(check5(o))
                            {
                                s3 = s1.substr(indexOf(s1,' ')+1,1);
                                s4 = s1.substr(indexOf(s1,',')+1,1);
                                if(s2=="MOV")
                                    MOV(s3[0],s4[0]);

                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"\nInvalid Operand(s) at line number "<<line_number<<"!\n\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 6: if(check6(o))
                            {
                                s3 = s1.substr(indexOf(s1,' ')+1,1);
                                s4 = s1.substr(indexOf(s1,',')+1,2);
                                if(s2=="MVI")
                                    MVI(s3[0],s4);

                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"\nInvalid Operand(s) at line number "<<line_number<<"!\n\n";
                                f=1;
                                --line_number;
                            }
                            break;
                    case 7: if(check7(o))
                            {
                                s3 = s1.substr(indexOf(s1,' ')+1,1);
                                s4 = s1.substr(indexOf(s1,',')+1,4);
                                if(s2=="LXI")
                                    LXI(s3[0],s4);

                                pc = hextodec(program_counter);
                                pc = pc + inst_size[s2];
                                program_counter = dectohex(pc);
                            }
                            else
                            {
                                cout<<"\nInvalid Operand(s) at line number "<<line_number<<"!\n\n";
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
                                cout<<"\nInvalid Operand(s) at line number "<<line_number<<"!\n\n";
                                f=1;
                                --line_number;
                            }
                }
            }
            else
            {
                cout<<"\nInvalid instruction present!\n\n";
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

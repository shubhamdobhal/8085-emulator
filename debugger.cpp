#include<fstream>
#include<limits.h>
#include<map>
#include "customfunctions.cpp"

int registers[7], number_of_lines = 0, break_point = INT_MAX,memregflag=0,pc;
string program_counter,start_address;
map<string,int> commands;
map<string,int> inst_size;
map<string,string> RAM;
map<int,int> memory;

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
    inst_size["SET"] = 3;
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
void break_point_set()
{
    cout<<"Enter line number to set break point:\n";
    cin>>break_point;
    if(break_point==1)
    {
        cout<<"Break point cannot set at line number 1 !\n\n";
    }
    else
    {
        if(break_point>number_of_lines || break_point<1)
        {
            cout<<"Line number does not exist !\n\n";
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
    if(memreg=="A")
    {
        cout<<registers[0]<<endl<<endl;
    }
    else
    {
        if(memreg=="B")
        {
            cout<<registers[1]<<endl<<endl;
        }
        else
        {
            if(memreg=="C")
            {
                cout<<registers[2]<<endl<<endl;
            }
            else
            {
                if(memreg=="D")
                {
                    cout<<registers[3]<<endl<<endl;
                }
                else
                {
                    if(memreg=="E")
                    {
                        cout<<registers[4]<<endl<<endl;
                    }
                    else
                    {
                        if(memreg=="H")
                        {
                            cout<<registers[5]<<endl<<endl;
                        }
                        else
                        {
                            if(memreg=="L")
                            {
                                cout<<registers[6]<<endl<<endl;
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
                                        cout<<memory[Hex_To_Dec(memreg)]<<"\n";
                                    }
                                }
                                else
                                {
                                    cout<<"Invalid Address !\n\n";
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void debugger(int file)
{
    int line_number = 1;
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
                pc = Hex_To_Dec(program_counter);
                if(line.size()==3 || line.size()==4)
                {
                    pc += inst_size[line];
                }
                else
                {
                    pc += inst_size[line.substr(0,indexOf(line,' '))];
                }
                program_counter = Dec_To_Hex(pc);
            }
            ++number_of_lines;
            //cout<<number_of_lines<<endl;
        }
        //cout<<number_of_lines<<endl; //number of lines
        code.close();
    }
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
            case 'b':break_point_set();
                     break;
            case 'h':help();
                     break;
            case 'p':print();
                     break;
            case 'r':
                     break;
            case 's':
                     break;
            default:if(ch!='q')
                    {
                        cout<<"Invalid Input ! Try Again !\n\n";
                    }
        }
    }while(ch!='q');
}

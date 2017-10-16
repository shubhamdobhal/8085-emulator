#include "Debugger.cpp"
int main()
{
    int ch,pc,f;
    set_instructions_size();
    string line="";
    cout<<"******\tWelcome To 8085 Microprocessor Emulator******\t\n\n";
    cout<<"Press:\n1 to use Pre-written code\n2 to write code\n3 to Exit\n\n";
    do
    {
        cout<<"Enter:\n";
        cin>>ch;
        fflush(stdin);
        if(!(ch==1||ch==2 || ch==3))
        {
            cout<<"Invalid Input. Try Again !\n";
        }
    }while(!(ch==1 || ch==2 || ch==3));
    if(ch==3)
    {
        return 0;
    }
    if(ch==1)//INPUT FROM FILE
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
                if((line.size()==3 || line.size()==4 || line.size()==2) && (check0(line) || line=="HLT" || line=="EOF"))
                {
                    pc += inst_size[line];
                }
                else
                {
                    if(insturctionPresent(line.substr(0,indexOf(line,' '))))
                        pc += inst_size[line.substr(0,indexOf(line,' '))];
                    else
                    {
                        cout<<"Invalid Instruction Present at line number "<<number_of_lines+1<<endl;
                        exit(0);
                    }
                }
                program_counter = dectohex(pc);
            }
            ++number_of_lines;
        }
        code.close();
        number_of_lines++;
    }
    if(ch==2)//INPUT FROM CONSOLE
    {
        cout<<"Enter starting address:\n";
        fflush(stdin);
        getline(cin,start_address);
        program_counter = start_address;
        do
        {
            ++number_of_lines;
            cout<<program_counter<<": ";
            getline(cin,line);
            if(!check0(line))
            {
                if(inst_size[line.substr(0,indexOf(line,' '))] == 0)
                {
                    --number_of_lines;
                }
            }
            RAM[program_counter] = line;
            pc = hextodec(program_counter);
            if(line.size()==3 || line.size()==4 || line.size()==2)
            {
                pc += inst_size[line];
            }
            else
            {
                pc += inst_size[line.substr(0,indexOf(line,' '))];
            }
            program_counter = dectohex(pc);
        }while(line!="HLT" && line!="EOF");
        ++number_of_lines;
    }
    do
    {
        cout<<"\nDebugger:\n1) ON\n2) OFF\n\nENTER:\n";
        cin>>f;
    }while(f!=1 && f!=2);
    if(f==2)
    {
        return 0;
    }
    debugger(ch);
    return 0;
}

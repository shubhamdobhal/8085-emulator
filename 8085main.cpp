#include "Debugger.cpp"
int main()
{
    int ch,pc;
    set_instructions_size();
    string line="";
    cout<<"******\tWelcome To 8085 Microprocessor Emulator******\t\n\n";
    cout<<"Press:\n1 to use Pre-written code\n2 to write code\n3 to Exit\n\n";
    do
    {
        cout<<"Enter:\n";
        cin>>ch;
        if(!(ch==1||ch==2 || ch==3))
        {
            cout<<"Invalid Input. Try Again !\n";
        }
    }while(!(ch==1 || ch==2 || ch==3));
    if(ch==3)
    {
        return 0;
    }
    if(ch==2)
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
            if(!((line=="XCHG")&&(line=="CMA")))
            {
                if(inst_size[line.substr(0,indexOf(line,' '))] == 0)
                {
                    --number_of_lines;
                }
            }
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
        }while(line!="HLT" && line!="EOF");
        ++number_of_lines;
    }
    //cout<<number_of_lines;
    debugger(ch);
    return 0;
}

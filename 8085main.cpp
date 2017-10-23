#include<H:\VIKRANT\GEU PROJECTS\8085-EML\Debugger.h>
int main()
{
    int pc;
    char ch,f,c;
    dp = 0;
    set_instructions_size();
    string line="";
    cout<<"******\tWelcome To 8085 Microprocessor Emulator******\t\n\n";
    cout<<"Press:\n1 to use Pre-written code\n2 to write code\n3 to Exit\n\n";
    do
    {
        cout<<"Enter:\n";
        cin>>ch;
        fflush(stdin);
        if(!(ch=='1'||ch=='2' || ch=='3'))
        {
            cout<<"Invalid Input. Try Again !\n";
        }
    }while(!(ch=='1' || ch=='2' || ch=='3'));
    if(ch=='3')
    {
        return 0;
    }
    if(ch=='1')//INPUT FROM FILE
    {
        string line;
        ifstream code;
        do
        {
            cout<<"\nAvailable Codes:\n\n1) 8 Bit Addition\t\t\t2) 8 Bit Subtraction\t\t\t3) 8 Bit Multiplication\n4) 8 Bit Division \t\t\t5) Find Largest Element In Array\t6) Find Smallest Element In Array\n7) Sort Array In Ascending Order\t8) Sort Array In Descending Order\t9) Custom Code\n\nEnter:\n";
            cin>>c;
            switch(c)
            {
                case '1': code.open("8 Bit Addition.txt",ios::in);
                        break;
                case '2': code.open("8 Bit Subtraction.txt",ios::in);
                        break;
                case '3': code.open("8 Bit Multiplication.txt",ios::in);
                        break;
                case '4': code.open("8 Bit Division.txt",ios::in);
                        break;
                case '5': code.open("8 Bit Array Find Largest.txt",ios::in);
                        break;
                case '6': code.open("8 Bit Array Find Smallest .txt",ios::in);
                        break;
                case '7': code.open("8 Bit Array Sort Ascending.txt",ios::in);
                        break;
                case '8': code.open("8 Bit Array Sort Descending.txt",ios::in);
                        break;
                case '9': code.open("inputF.txt",ios::in);
                        break;
            }
        }while(!(c>='1' && c<='9'));
        //      code.open("inputF.txt",ios::in);
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
    if(ch=='2')//INPUT FROM CONSOLE
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
        cout<<"\nDebugger:\n1) ON\n2) OFF\n\nEnter:\n";
        cin>>f;
        if(f!='1' && f!='2')
        {
            cout<<"\nInvalid Option! Try Again!\n";
        }
    }while(f!='1' && f!='2');
    if(f=='2')
    {
        return 0;
    }
    debugger(int(ch-'0'));
    return 0;
}

#include "Debugger.h"
int main(int argc, char** argv)
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
        cout<<"\nThank You for using 8085 Emulator!!\n";
        return 0;
    }
    if(ch=='1')//INPUT FROM FILE
    {
        string line;
        ifstream code;
        if(argc==2)
        {
            code.open(argv[1],ios::in);
        }
        else
        {
            do
            {
                cout<<"\nAvailable Codes:\n\nA) 8 Bit Addition\t\t\tB) 8 Bit Subtraction\t\t\tC) 8 Bit Multiplication\nD) 8 Bit Division \t\t\tE) Find Largest Element In Array\tF) Find Smallest Element In Array\nG) Sort Array In Ascending Order\tH) Sort Array In Descending Order\tI)Previous Console Written Code\nJ) Previous File Code\n\nEnter:\n";
                cin>>c;
                switch(c)
                {
                    case 'a':
                    case 'A':code.open("8 Bit Addition.txt",ios::in);
                             break;
                    case 'b':
                    case 'B':code.open("8 Bit Subtraction.txt",ios::in);
                             break;
                    case 'c':
                    case 'C':code.open("8 Bit Multiplication.txt",ios::in);
                             break;
                    case 'd':
                    case 'D':code.open("8 Bit Division.txt",ios::in);
                             break;
                    case 'e':
                    case 'E':code.open("8 Bit Array Find Largest.txt",ios::in);
                             break;
                    case 'f':
                    case 'F':code.open("8 Bit Array Find Smallest .txt",ios::in);
                             break;
                    case 'g':
                    case 'G':code.open("8 Bit Array Sort Ascending.txt",ios::in);
                             break;
                    case 'h':
                    case 'H':code.open("8 Bit Array Sort Descending.txt",ios::in);
                             break;
                    case 'i':
                    case 'I':code.open("previousConsoleCode.txt",ios::in);
                             break;
                    case 'j':
                    case 'J':code.open("previousFileCode.txt",ios::in);
                             break;
                    default: cout<<"\nInvalid Input\n";
                }
            }while(!((c>='A' && c<='J') || (c>='a' && c<='j')));
        }
        //      code.open("inputF.txt",ios::in);
        ofstream file;
        if(c!='i' && c!='I')
        {
            remove("Dummy.txt");
            file.open("Dummy.txt",ios::out);
        }
        while(!code.eof())
        {
            getline(code,line);
            if(c!='i' && c!='I')
                file<<line<<endl;
            if(line_number==1)
            {
                program_counter = line;
                start_address = line;
                line_number = 2;
                continue;
            }
            else
            {
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
                            cout<<"Invalid Instruction Present at line number "<<number_of_lines+2<<"!"<<endl;
                            exit(0);
                        }
                    }
                    program_counter = dectohex(pc);
                }
                ++number_of_lines;
            }
        }
        code.close();
        file.close();
        remove("previousFileCode.txt");
        code.open("Dummy.txt",ios::in);
        file.open("previousFileCode.txt",ios::out);
        while(!code.eof())
        {
            getline(code,line);
            file<<line<<endl;
        }
        number_of_lines++;
    }
    if(ch=='2')//INPUT FROM CONSOLE
    {
        cout<<"Enter starting address:\n";
        remove("previousConsoleCode.txt");
        ofstream code;
        code.open("previousConsoleCode.txt",ios::out);
        fflush(stdin);
        getline(cin,start_address);
        code<<start_address<<endl;
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
            code<<line<<endl;
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
        code.close();
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
        set_instructions();
        reset_flags();
        reset_registers();
        program_counter = start_address;
        stepORrun(2);
        return 0;
    }
    debugger(int(ch-'0'));
    return 0;
}

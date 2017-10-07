//flags related functions.........

void check_flags_1(char operand){				//to check flags for dcr, inr .....,carry flag never changes
	if(registers[operand]==0 || registers[operand]==128 || registers[operand]==-129){
		flag['z']=1;
		registers[operand]=0;
	}
	else{
		flag['z']=0;
	}
	//code for checking parity and auxilarry carry.............
}

void check_flags_2(){							//to check flags for add,sub........
	if(registers['A']<0){
		flag['s']=1;
		if(registers['A']<(-128)){
			flag['c']=1;		//if carry
			registers['A']=129-registers['A'];		
		}
	}
	else{	
		flag['s']=0;
		flag['c']=registers['A']/128;		//if carry
		registers['A']%=128;
	}
	if(registers['A']==0)
		flag['z']=1;
	else
		flag['z']=0;
	//code for checking auxilarry and parity flag..............
}

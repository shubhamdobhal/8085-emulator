#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<math.h>
#include<functional>
using namespace std;

int number_of_lines=0, break_point=INT_MAX,memregflag=0,pc,line_number=1,dp,sp=1000;
string program_counter,start_address;
map<string,int> commands;
map<string,int> inst_size;
map<string,string> RAM;
map<string,int> memory;
map<char,int> registers;
map<char,int> flag;
vector<string> memoryLocationsUsed;

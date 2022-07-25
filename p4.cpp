#include <iostream> 
#include <fstream> 
#include <string>
using namespace std; 
class student
{
 public:  
	string USN;  
	string Name;  
	string Branch; 
	string Semester; 
	string buffer; 
	int count; 
	int rrn_list[100]; 
	void read_data();  
	void pack();
	void write_to_file(); 
	void create_rrn(); 
	void search_by_rrn(int); 
	}; 

void student::read_data() 
{ 
cout<<"\nUsn:"; 
cin>>USN; 
cout<<"\nName:"; 
cin>>Name; 
cout<<"\nBranch:"; 
cin>>Branch; 
cout<<"\nSemster:"; 
cin>>Semester; 
} 



void student::pack() 
 { 
buffer.erase(); 
buffer=USN+'|'+Name+'|'+Branch+'|' +Semester+'$'+'\n'; 
 
} 


void student::write_to_file() 
{ 
fstream file; 
file.open("4.txt",ios::out|ios::app); 

file<<buffer; 
file.close();  
} 

void student::create_rrn()  
{ 
ifstream file; 
int pos;
count=-1;  
file.open("4.txt",ios::in); 
while (!file.eof()) 
{ 
pos=file.tellg();  
buffer.erase();  
getline(file,buffer);  
rrn_list[++count]=pos; 
} 
file.close(); 
} 


void student::search_by_rrn(int rrn)
 { 
int pos; 
fstream file; 
if(rrn>=count)
cout<<"\n Not Found"; 
else
{ 
buffer.erase();
file.open("4.txt"); 
pos=rrn_list[rrn]; 
file.seekg(pos,ios::beg); 
getline(file,buffer); 
cout<<"\n"<<buffer<<"\n" ;
file.close(); 
} 
}

int main() 
{ 
int choice,rrn,count,i; 
student s1; 

while(1)
{ 
cout <<"\nMain Menu\n 1.Add \n 2.Search \n 3.EXIT\nEnter the choice:"; 
cin>>choice; 
switch(choice) 
{ 

case 1: cout<<"\nHow many records to insert:\n";
cin>>count;
for(i=0;i<count;i++)
{
cout<<"Data\n"; 
s1.read_data(); 
s1.pack(); 
s1.write_to_file();
}
s1.create_rrn(); 
break; 
case 2: cout <<"\nEnter the RRN";  
cin>>rrn;  
s1.search_by_rrn(rrn);  
break; 
case 3: return 0; 
default:cout<<"\n\nWrong Choice";
break;  
}
}  
}

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
using namespace std; 
class student 
{ 
public: 
string USN; 
string Name; 
string Branch; 
int Semester; 
string buffer; 

void read_data(); 
void write_to_file();
void pack();
void unpack(); 
int search(string); 
int delete_from_file(string); 
void modify(string); 
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
string sem,temp; 
stringstream out;
out << Semester; 
sem = out.str();
temp.erase(); 
temp+=USN+'|'+Name+'|'+Branch+'|'+sem; 
for(;temp.size()<100;) temp+='$'; 
buffer+=temp+'\n'; 
} 

void student::write_to_file() 
{ 
fstream file; 
file.open("1.txt",ios::out|ios::app); 
file<<buffer; 
file.close(); 
} 

void student::unpack() 
{ 
string sem; 
int ch=1,i=0; 
USN.erase(); 
while (buffer[i]!='|') 
USN+=buffer[i++]; 

Name.erase(); 
i++; 
while (buffer[i]!='|') 
Name+=buffer[i++]; 
Branch.erase(); 
i++; 
while (buffer[i]!='|') 
Branch+=buffer[i++]; 
sem.erase(); 
i++; 
while (buffer[i]!='$') 
sem+=buffer[i++]; 
istringstream out(sem); 
out>>Semester; 
}
int student::search(string key) 
{ 
ifstream file; 
int flag=0, pos=0; 
file.open("1.txt",ios::in); 
while (!file.eof()) 
{ 
buffer.erase(); 
getline(file,buffer); 
unpack(); 
if (key==USN) 
{cout<<"\nFound the key.\n The record is  "<<buffer;
pos=file.tellg(); 
flag=1; 
return pos; 
} 
} 
file.close(); 
if(!flag)
{
    cout<<"\n Not Found \n\n";
    return pos;}
} 

int student::delete_from_file(string key) 
{ 
fstream file; 
char del_mark='*',t; 
int pos,flag=0; 
pos=search(key); 
if (pos){ 
file.open("1.txt"); 
pos-=101; 

file.seekp(pos,ios::beg); 
file.put(del_mark); 
flag=1; 
} 
file.close(); 
if (!flag) return 0; 
else 
return 1; 

} 

void student::modify(string key) 
{ 
int choice;
if (delete_from_file(key)){ 
    
cout<<"\n What to modify?"; 
cin>>choice; 
switch(choice) 
{ 
case 1: cout<<"\nUSN:"; 
cin>>USN; break; 
case 2: cout<<"\nName:"; 
cin>>Name;break; 
case 3: cout<<"\nBranch:"; 
cin>>Branch;break; 
case 4: cout<<"\nSemster:"; 
cin>>Semester;break; 
default: cout <<"Wrong Choice"; 
} 
buffer.erase(); 
pack(); 
write_to_file(); 
} 
} 

int main() 
{ 
int count,choice,len,i; 
student s1; 
string key; 
cout <<"\nMain Menu\n 1.Add \n\n  2.Delete \n\n 3.Modify \n\n 4.Search  \n\nEnter the choice:"; 
cin>>choice; 
switch (choice) 
{ 
case 1: cout<<"\n\nhow  many records to insert?\n"; 
cin>>count; 
for(i=0;i<count;i++) 
{ 
cout<<"Data\n"; 
s1.read_data(); 
s1.pack(); 
} 
s1.write_to_file(); 
break;
case 2: cout <<"\n\nEnter the key"; 
cin>>key; 
i=s1.delete_from_file(key); 
break; 
case 3: cout <<"\n\nEnter the key"; 
cin>>key; 
s1.modify(key); 
break; 
case 4: cout <<"\n\nEnter the key"; 
cin>>key; 
i=s1.search(key); 
break; 
default: cout<<"\n\nWrong Choice"; 
} 
return 0;
}


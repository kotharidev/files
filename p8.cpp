#include<iostream> 
#include<fstream>  
#include<string>  
using namespace std;         
class coseq  
{ 
public:  
string list[8][100];         
string outlist[100];        
int count[8];        
int current[8];        
void load_list();         
void read_file(int);        
void sort_list(int);         
void merge();        
};        

void coseq::read_file(int i) 
{ 
fstream file;         
string name;         
switch(i) 
{  
case 1:  file.open("name1.txt");       break;        
case 2:  file.open("name2.txt");       break;         
case 3:  file.open("name3.txt");       break;         
case 4:  file.open("name4.txt");       break;        
case 5:  file.open("name5.txt");       break;         
case 6:  file.open("name6.txt");       break;        
case 7:  file.open("name7.txt");       break;         
case 8:  file.open("name8.txt");       break;         
} 
while (!file.eof())  
{  
name.erase();         
getline(file,name);         
list[i][++count[i]]=name;        
}  
file.close();        
}  

void coseq::load_list()  
{ 
for (int i=1; i<=8;i++)  
{ 
count[i]=-1;         
read_file(i);         
sort_list(i);        
}  
} 
 
void coseq::sort_list(int k) 
{ 
int i,j;         
string temp;         
for(i=0;i<=count[k];i++)
{  
for(j=i+1;j<=count[k];j++) 
{ 
if(list[k][i]>list[k][j]) 
{  
temp=list[k][i];        
list[k][i]=list[k][j];       
list[k][j]=temp;        
} 
}  
}  
}  

void coseq::merge()
{ 
string smallest;        
int i,j,small_list, t=-1,start=1,avail[8],avail_lists=8;        
for(i=1;i<=8;i++)  
{ 
avail[i]=1;         
current[i]=0;        
} 

while (avail_lists>1)  
{  
if(!avail[start]) 
{ 
start++;         
continue;         
}  
small_list=start;        
smallest=list[start][current[start]];         
for(i=start+1;i<=7;i++)  
{ 
if(!avail[i]) continue;         

if(list[i][current[i]]<smallest) 
{  
smallest=list[i][current[i]];         
small_list=i;         
} 
}  
current[small_list]++;         
if(current[small_list]>count[small_list])  
{ 
avail[small_list]=0;        
avail_lists--;        
}  
outlist[++t]=smallest;         
for(j=1;j<=8;j++)  
if(j!=small_list) 
{ 
if(list[j][current[j]]==smallest)
current[j]++; 
}  
}  
for(i=1;i<=8;i++)
if(avail[i]) 
{ 
for(j=current[i];j<=count[i];j++)  
outlist[++t]=list[i][j];  
} 
cout<<"\nThe Merged List:";  
for(i=0;i<=t+1;i++) 
cout<<"\n"<<outlist[i]; 
}
  
int main() 
{  
coseq c1;
c1.load_list(); 
c1.merge(); 
return 0; 
}  


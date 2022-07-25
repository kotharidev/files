#include <iostream>  
#include <fstream> 
#include <string> 
using namespace std;         
class coseq 
{  
public:  
string list1[100], list2[100];        
int count1, count2;         
void load_list();         
void sort_list();        
void match();        
}; 
       
void coseq::load_list()  
{
fstream file1,file2;        
string name;      
count1=-1; 
count2=-1;         
file1.open("name1.txt");    
while (!file1.eof())
{ 
name.erase();        
getline(file1,name);         
list1[++count1]=name;         
}  
file1.close();        
file2.open("name2.txt");     
while (!file2.eof()) 
{ 
name.erase();   
getline(file2,name);        
list2[++count2]=name;        
}  
file2.close();

        
} 
void coseq::sort_list()
{ int i,j;        
string temp;         
for (i=0;i<=count1;i++) 
{  
for (j=i+1;j<=count1;j++) 
{  
if (list1[i]>list1[j]) 
{  
temp=list1[i];        
list1[i]=list1[j];         
list1[j]=temp;       
 } 
} 
}  
for (i=0;i<=count2;i++)  
{  
for (j=i+1;j<=count2;j++)  
{ 
if (list2[i]>list2[j])  
{ 
temp=list2[i];        
list2[i]=list2[j];         
list2[j]=temp;        
} 
} 
} 
} 
 
void coseq::match()  
{ 
int i=0,j=0;        
while (i<=count1 && j<=count2)  
{ 
if (list1[i]==list2[j]) 
{ 
cout<<list1[i];  
i++;       
j++;  
     
 } 
if (list1[i] < list2[j]) i++;         
if (list1[i] > list2[j]) j++;        
}  
} 
int main()  
{ 
coseq c1;         
c1.load_list();         
c1.sort_list();         
c1.match();         
return 0;        
}

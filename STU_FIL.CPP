/* Menu driven system to perform the following functions on a binary file “STUD.DAT”
 containing objects of the class student
1. Add Records
2. Search for a record with a given admission number
3. Modify a record with a given admission number
4. Delete a record with a given admission number
5. Instructions */

#include<graphics.h>
#include<dos.h>
#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <string.h>
const char SList[]="Stud.dat";

int getint()
{
	int x=0;
   while(!(cin>>x))
   {cin.clear();
	cin.ignore();
	cout<<"\n \t \t Invalid Entry, Try Again !!!";
   }
   return x;
}
void mainscreen()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,"");
clrscr();
char main[]=  {"   WELCOME TO C++ PROJECT    " };
char screen[]={"OF STUDENT RECORD MANAGEMENT"};
setbkcolor(RED);
for(int i=0;i<28;i++)
{
delay(100);
gotoxy(25+i,10);
cout<<main[i];
 }
for(i=0;i<30;i++)
{
delay(100);
gotoxy(24+i,12);
cout<<screen[i];
}
cleardevice();
closegraph();
}


class student
{
private:
char reg[10];
char gen;
char sssid[11];
char adhr[16]; // 1 for '\0'
int adno;
int rno;
char nam[30];
char sec,ch;
int cl;
public:
void input() ;
void show() ;
void modify();
int re_adno(){return adno;}
char* re_adhr(){return adhr;}
char* re_sssid() {return sssid;}
};
 void student :: input()
 {
 cout<<"\n Enter the following details and press Enter key:"<<endl;
 cout<<"Admission No:  \t "<<endl;
 adno=getint();

 cout<<"\n Name: \t ";
 gets(nam);
 do
 {
 cout<<"\n Class:   \t "<<endl;
 cl=getint();

 if(cl<0||cl>12)
 {
   cout<<"\n Invalid class! Try again ";
 }
 }while(cl<0||cl>12);
 cout<<"Section:  \t "<<endl;
 cin>>sec;

 cout<<"Roll No:  \t "<<endl;
 rno=getint();

 cout<<"adhar number: \t"<<endl;
 gets(adhr);

 cout<<"enter sssmid: \t"<<endl;
 cin>>sssid;

 cout<<"gender: \t"<<endl;
 cin>>gen;

 cout<<"religion: \t"<<endl;
 gets(reg);}

 void student ::  show()
 {
 cout<<" \n Details: \n \n Admission No: \t"<<adno<<"\n Name: \t "<<nam<<" \n Class: \t "<<cl<<"\n  Section: \t"<<sec<<"\n  Roll No. : \t"<<rno<<"\n  Adhar No.\t"<<adhr<<"\n  sssmid \t"<<sssid<<"\n gender \t"<<gen<<"\n religion \t"<<reg;
  }
 void student :: modify()
 {char str[30];
 char ch;
 int n;
 char P[16];

 cout<<"\n Enter Name: ('.' to keep the previous name) \t ";
  gets(str);
  if((strcmpi(str,"."))!=0) strcpy(nam,str);
 do
 {
 cout<<"\n Class: ('-1' to keep the previous class)  \t "<<endl;
 n=getint();

 if(cl<-1||cl>12)
 {
   cout<<"\n Invalid class! Try again ";
 }
else if(n!=-1) cl=n;
 }while(n<-1||n>12);
 cout<<"Section: ('.'to keep the previous section) \t "<<endl;
 cin>>ch;
 if(ch!='.') sec=ch;

 cout<<"Roll No: ('-1' to keep the previous Roll No.)  \t "<<endl;
 n=getint();
 if(n!=-1) rno=n;

 cout<<"Adhar No: ('.' to keep the previous adhar no.) \t"<<endl;
 gets(P);
 if(strcmpi(P,".")) strcpy(adhr,P);

 cout<<"sssmid : ('.' to keep the previous sssmid) \t"<<endl;
 gets(P);
 if(strcmpi(P,".")) strcpy(sssid,P);

 cout<<"gender : ('.' to keep the previous gender) \t"<<endl;
 cin>>ch;
 if(ch!='.') gen=ch;

  cout<<"\n Enter religion: ('.' to keep the previous religion) \t ";
  gets(str);
  if((strcmpi(str,"."))!=0) strcpy(reg,str);

}
int main()
{

mainscreen();
int num,i,pos,final,flag=1;
char P[16];
student X;
char op;
fstream file(SList,ios::in|ios::binary|ios::out|ios::ate);
if(!file) {
cout<<"\n Sorry, the file "<<file<<" not found ";
exit(0);
}
do {
system("cls");

gotoxy(30,3);
cout<<"_____RECORD BAR_______  ";
cout<<"\n \n Select any one of the following options by entering the respective number";
cout<<"\n 1. Enter a Student's information \n 2. View a Student's information \n 3. Modify a Student's information \n 4. Delete a Student's record \n 5. How to use this program (For new users) \n 6. Exit \n ";
op=getche();
system("cls");
if (op=='1')
{
X.input();
file.clear();
file.seekp(0,ios::end);
file.write((char*)&X,sizeof(X));
cout<<"\n Record saved successfully......... \n";
cout<<"\n \n \t \t......Press any key to continue.......";
getch();
}
else if(op=='2')
{
i=0;
cout<<"\n 1. Search by admission number ";
cout<<"\n 2. Search by adhar number ";
cout<<"\n 3. Search by SSSM ID  ";
cout<<"\n Enter your choice: \t";
flag=getint();

if(flag==1)
{
cout<<" Enter the admission no. of the required student: \t";
num=getint();
cout<<"\n \n \n";
file.clear();
file.seekg(0,ios::beg);
while(!file.eof())
{
file.read((char*)&X,sizeof(X));
if(X.re_adno()==num)
{
X.show();
i=1;
break;
}
}
if(i==0)cout<<"\n Sorry, student not found.....";
cout<<"\n \n \t \t......Press any key to continue.......";
getch();
}
if(flag==2)
{
cout<<" Enter the adhar no. of the required student: \t";
gets(P);
cout<<"\n \n \n";
file.clear();
file.seekg(0,ios::beg);
while(!file.eof())
{
file.read((char*)&X,sizeof(X));
if(strcmp(X.re_adhr(),P)==0)
{
X.show();
i=1;
break;
}
}
if(i==0)cout<<"\n Sorry, student not found.....";
cout<<"\n \n \t \t......Press any key to continue.......";
getch();
}
if(flag==3)
{
cout<<" Enter the SSSM ID of the required student: \t";
cin>>P;
cout<<"\n \n \n";
file.clear();
file.seekg(0,ios::beg);
while(!file.eof())
{
file.read((char*)&X,sizeof(X));
if(strcmp(X.re_sssid(),P)==0)
{
X.show();
i=1;
break;
}
}
if(i==0)cout<<"\n Sorry, student not found.....";
cout<<"\n \n \t \t......Press any key to continue.......";
getch();
}

}

else if(op=='3')
{
i=0;
cout<<" Enter the admission no. of the required student: \t";
num=getint();
cout<<"\n \n \n";
file.clear();
file.seekg(0,ios::beg);
while(!file.eof())
{
pos=file.tellg();
file.read((char*)&X,sizeof(X));
if(X.re_adno()==num)
{
X.modify();
file.seekg(pos);
file.write((char*)&X,sizeof(X));
i=1;
break;
}
}
if(i!=1)cout<<"\n Sorry, student not found.....";
else cout<<"\n Record modified successfully.....";
cout<<"\n \n \t \t......Press any key to continue.......";
getch();

}
else if(op=='4')
{
cout<<" Enter the admission no. of the required student: \t";
num=getint();
cout<<"\n \n \n";
file.clear();
file.seekg((-1)*sizeof(X),ios::end);
file.read((char*)&X,sizeof(X));
// final=X.re_adno();
file.seekg(0,ios::beg);
ofstream temp("temp.txt",ios::binary|ios::out);
while(file.read((char*)&X,sizeof(X)))
{
if(X.re_adno()==num)
{
i=1;
X.show();
cout<<"\n \n Do you really want to delete this record \? (y/n) \n";
char choice;
choice=getche();
if(choice=='n'||choice=='N')
{temp.write((char*)&X,sizeof(X));
}
else
{
cout<<"\n .................Record deleted successfully..............";
}
}
else temp.write((char*)&X,sizeof(X));

}
if(i!=1)cout<<"\n ..............Sorry, student not found..............";
temp.close();
file.close();
remove(SList);
rename("temp.txt",SList);
file.open(SList,ios::app|ios::binary|ios::in);
cout<<"\n \n \t \t......Press any key to continue.......";
getch();
}
else if (op=='5')
{
cout<<" How to use this program ? \n \n \n \n ";
cout<<"1. This is a C++ program which maintains the data record through a binary file. \n ";
cout<<"2. Please don't try to edit the file "<<SList<<" . Otherwise, discrepancies may creep in. \n";
cout<<"3. In this program, the primary key to identify the students is 'Admission No. , adhar no. , sssm id'. So, please take care that no two students have same Admission No.,Adhar no. , SSSMID \n";
cout<<"\n \n \n \n ........ Press any key to continue .........";
getch();
}
else if (op!='6')
 {cout<<"\n Invalid Character, Try Again!! \n ";
getch();

continue;
}

}
while (op!='6');
file.close();
return 0;
}





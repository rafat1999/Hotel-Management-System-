#include<bits/stdc++.h>
using namespace std;

class hotel
{
int room_no;
char name[30];
char address[50];
char phone[10];

public:
void main_menu();            ///to Dispay The Main Menu
void add();                 ///To Book A Room
void display();             ///To Display The Customer Record
void rooms();               ///To Display Alloted Rooms
void edit();                ///To Edit The Customer Record
int check(int);            ///To Check Room Status
void modify(int);        ///To Modify The Record
void delete_rec(int);   ///To Delete The Record
};

void hotel::main_menu()
{

int choice;
while(choice!=5)
{
cout<<"\n\t\t\t\t*************";
cout<<"\n\t\t\t\t* MAIN MENU *";
cout<<"\n\t\t\t\t*************";
cout<<"\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Customer Record";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;
switch(choice)
{
case 1: add();
break;
case 2: display();
break;
case 3: rooms();
break;
case 4: edit();
break;
case 5: break;
default:
{
cout<<"\n\n\t\t\tWrong choice!!!";
cout<<"\n\t\t\tPress any key to continue!!";

}
}
}

}

void hotel::add()
{
int r,flag,r_c;
int day, price;
cout<< "\n\t\t\t\t\t1.Single Room(Per day Price: 800)";
cout<< "\n\t\t\t\t\t2.Double Room(Per day Price: 1500)";
cout<< "\n\t\t\t\t\t3.Luxury Room(Per day Price: 3000)";
cout<< "\n\t\t\t\t\t\n\n\t\t\t\t\tFor Book A Room You have To Pay 50% Off Total Money";
cout<< "\n\t\t\t\t\t\n\t\t\t\t\tEnter Your Choice: ";
cin>>r_c;
switch(r_c)///r_c is our choice
{
case 1:

    cout<< "\n\t\t\t\t\tHow Many days you want to Stay: ";
    cin>>day;
    price = (800 * day) / 2;
    cout<< "\n\n\n\t\t\t\t\t You have to pay:-- " << price << " Taka";
    break;

case 2:

    cout<< "\n\t\t\t\t\tHow Many days you want to Stay: ";
    cin>>day;
    price = (1500 * day) / 2;
    cout<< "\n\n\n\t\t\t\t\t You have to pay:-- " << price << " Taka";
    break;

case 3:

    cout<< "\n\t\t\t\t\tHow Many days you want to Stay: ";
    cin>>day;
    price = (3000 * day) / 2;
    cout<< "\n\n\n\t\t\t\t\t You have to pay:-- " << price << " Taka";
    break;
}
cout<< "\n\t\t\t\t\tBook The Room!!!";
ofstream fout("Record.dat",ios::app);
cout<<"\n Enter Customer Detalis";
cout<<"\n ********************";
cout<<"\n\n Room no: ";
cin>>r;
flag=check(r);
if(flag)
    cout<<"\n Sorry..!!!Room is already booked";
else
{
    room_no=r;
    cout<<" Name: ";

    cin>>name;
    cout<<" Address: ";
    gets(address);
    puts(address);
   // cin>>address;
    cout<<" Phone No: ";
    gets(phone);
    puts(phone);
    //cin>>phone;
    fout.write((char*)this,sizeof(hotel));
    cout<<"\n Room is booked!!!";
}
cout<<"\n Press any key to continue!!";

}
//fout.close();


void hotel::display()
{

ifstream fin("Record.dat",ios::in);
int r,flag;
cout<<"\n Enter room no: ";
cin>>r;
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

cout<<"\n Cusromer Details";
cout<<"\n **************";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant!!";
cout<<"\n\n Press any key to continue!!";

fin.close();
}

void hotel::rooms()
{

ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\tList Of Rooms Allotted";
cout<<"\n\t\t\t*********************";
cout<<"\n\n Room No.\t\tName\t\tAddress\t\tPhone No.\n";
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t";
cout<<"\n\n "<<name<<"\t\t";
cout<<"\t\t"<<address<<"\t\t"<<phone;
}
cout<<"\n\n\n\t\t\tPress any key to continue!!";

fin.close();
}

void hotel::edit()
{

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n *******";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n Enter your choice: ";
cin>>choice;

cout<<"\n Enter room no: ";
cin>>r;
switch(choice)
{
case 1: modify(r);
break;
case 2: delete_rec(r);
break;
default: cout<<"\n Wrong Choice!!";
}
cout<<"\n Press any key to continue!!!";

}

int hotel::check(int r)
{
int flag=0;
ifstream fin("Record.dat",ios::in);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
flag=1;
break;
}
}
fin.close();
return(flag);
}

void hotel::modify(int r)
{
long pos,flag=0;
fstream file("Record.dat",ios::in|ios::out|ios::binary);
while(!file.eof())
{
pos=file.tellg();
file.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Enter New Details";
cout<<"\n ***************";
cout<<"\n Name: ";
//gets(name);
//puts(name);
cin>>name;
cout<<" Address: ";
//gets(address);
//puts(address);
cin>>address;
cout<<" Phone no: ";
//gets(phone);
//puts(phone);
cin>>phone;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified!!";
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant!!";
file.close();
}

void hotel::delete_rec(int r)
{
int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Pone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;
if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;
}
else
fout.write((char*)this,sizeof(hotel));

fin.close();
fout.close();
if(flag==0)
cout<<"\n Sorry room no. not found or vacant!!";
else
{
remove("Record.dat");
rename("temp.dat","Record.dat");
}
}
}

int main()
{
hotel h;

cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
cout<<"\n\t\t\t****************************";

cout<<"\n\n\n\tMade By:";

cout<<"\tMishat Nissat Jarin & Shihab Hossen Rafat";

h.main_menu();
}

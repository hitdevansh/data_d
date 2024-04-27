
#define string jum
#include<iostream>
#include<cstring>
using namespace std;
class account{
private:
long int acc_num;
public:
int interest;
//for wwithdrawl
string name;
int deposite;
long int balance=0;
string type;
void input(){
cout<<"Enter your name:";
cin>>name;
cout<<"Enter your account number:";
cin>>acc_num;
cout<<"Enter the type of your account (current or private) ";
cin>>type;
}
public:
void output(){
cout<<"Your name is: "<<name<<endl;
cout<<"Your account number: "<<acc_num<<endl;
cout<<"Type of your account is "<<type<<endl;
}
void deposi(){
cout<<"Enter your depostite balance"<<endl;
cin>>deposite;
if(deposite>0)
{balance=balance+deposite;
cout<<"Now your current balance is "<<balance<<endl;}
else
{cout<<"please enter a valid ammount of balance to deposite "<<endl;
exit(1);
 }
}
};
class cur_account : public account{
public:

void minimum(){
if(balance<501)
{
balance=balance-26;
cout<<"Because of penalty now your balance is "
    <<balance<<" so pls deposite in your account";
}
}
void withdrawl()
{   int w;
    cout<<"Enter your withdrawl ammount"<<endl;
    cin>>w;
    if(w>0 && w<balance)
	{balance=balance-w;
	cout<<"Now your current balance is "<<balance<<endl;}
	else
	{cout<<"Please enter a valid withdrawl ammount..."<<endl;
	 exit (1);
	}
}
};
class sav_account : public account{
public:
void  com_interest()
{
	interest=(balance*0.08);
	balance=balance+interest;
}
void withdrawl()
{   int w;
    cout<<"Enter your withdrawl ammount"<<endl;
    cin>>w;
    if(w>0 && w<balance)
	{balance=balance-w;
	cout<<"Now your current balance is "<<balance<<endl;}
	else
	{cout<<"Please enter a valid withdrawl ammount..."<<endl;
	 exit (1);
	}
}
};
int compareFunction(string s1, string s2)
{
    // comparing both using inbuilt function
    int x = s1.compare(s2);
    int flag=1;
    if (x != 0) {
        return flag;
        if (x > 0)
        return flag;
        else
        return flag;
    }
    else
       return 0;
}
int main()
{   jum:
    int w;
    string s1="current";
    string s2="Current";
	account p1;
	p1.input();
	
	if(compareFunction(p1.type,s1)==0 || compareFunction(p1.type,s2)==0)
	{ cur_account n1;
	  n1.deposi();
	  n1.withdrawl();
	  n1.minimum();
	  p1.output();
	}
	else{
	  sav_account n2;
	  n2.deposi();
	  n2.withdrawl();
      n2.com_interest();
      p1.output();
	}
	cout<<endl;
	goto jum;
}
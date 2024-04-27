#include<iostream>
using namespace std;
class govemply;
class priemply;
class person{
public:
int id;
int cibil_score;
int moth_inco;
int yos;
};
class govemply : private person
{
private:
int disiplinary;
public:
govemply(int id_,int cibil_score_,int moth_inco_,int yos_,int dis){
id=id_;
cibil_score=cibil_score_;
moth_inco=moth_inco_;
yos=yos_;
disiplinary=dis;
}
friend void checkloan(govemply g1,govemply g2,priemply p1,priemply p2);
};
class priemply : private person
{
private:
int rate;
public:
priemply(int id_,int cibil_score_,int moth_inco_,int yos_,int rate_){
id=id_;
cibil_score=cibil_score_;
moth_inco=moth_inco_;
yos=yos_;
rate=rate_;
}
friend void checkloan(govemply g1,govemply g2,priemply p1,priemply p2);
};

void checkloan(govemply g1,govemply g2,priemply p1,priemply p2)
{
char ch;
cout<<"Which type of loan you want press i for individual load and j for joint loan"<<endl;
cin>>ch;
if(ch=='i')
{
if(g1.disiplinary==1)
{cout<<"g1 r not eligible for loan"<<endl;}
else if(g1.disiplinary==0 && g1.moth_inco>=25000 && g1.yos>=15 && g1.cibil_score>=200)
{ cout<<"g1 are eligible for 5 lakh loan"<<endl;}
else if(g1.disiplinary==0 && g1.moth_inco>=50000 && g1.yos>=20 && g1.cibil_score>=300)
{ cout<<"g1 are eligible for 10 lakh loan"<<endl;}
else{cout<<"Sorry to tell p1 of id "<<g1.id
    <<" are not matching any type of loan.."<<endl;}

if(g2.disiplinary==1)
{cout<<"g2 r not eligible for loan "<<endl;}
else if(g2.disiplinary==0 && g2.moth_inco>=25000 && g2.yos>=15 && g2.cibil_score>=200)
{ cout<<"g2 are eligible for 5 lakh loan"<<endl;}
else if(g2.disiplinary==0 && g2.moth_inco>=50000 && g2.yos>=20 && g2.cibil_score>=300)
{ cout<<"g2 are eligible for 10 lakh loan"<<endl;}
else{cout<<"Sorry to tell g1 of id "<<g2.id
    <<" are not matching any type of loan.."<<endl;}

if(p1.rate<3)
{cout<<"p1 is not eligible for any loan"<<endl;}
else if(p2.rate>=3 && p2.moth_inco>=35000 && p2.yos>=15 && p2.cibil_score>=250)
{ cout<<"p1 are eligible for 5 lakh loan"<<endl;}
else if(p2.rate>=3 && p2.moth_inco>=50000 && p2.yos>=30 && p2.cibil_score>=350)
{ cout<<"p1 are eligible for 10 lakh loan"<<endl;}
else{cout<<"Sorry to tell p1 of id "<<p1.id
    <<" are not matching any type of loan.."<<endl;}

if(p2.rate<3)
{cout<<"p2 is not eligible for any loan"<<endl;}
else if(p2.rate>=3 && p2.moth_inco>=35000 && p2.yos>=15 && p2.cibil_score>=250)
{ cout<<"p2 are eligible for 5 lakh loan"<<endl;}
else if(p2.rate>=3 && p2.moth_inco>=50000 && p2.yos>=30 && p2.cibil_score>=350)
{ cout<<"p2 are eligible for 10 lakh loan"<<endl;}
else{cout<<"Sorry to tell p2 of id "<<p2.id
    <<" are not matching any type of loan.."<<endl;}
}
else if(ch=='j')
{
if(g1.disiplinary==0 && p1.rate>=3 && (g1.moth_inco+p1.moth_inco>=50000) && (g1.yos+p1.yos>=30))
{cout<<"g1 and p1 can get 5 lakh loan"<<endl;}
else if(g1.disiplinary==0 && p1.rate>=3 && (g1.moth_inco+p1.moth_inco>=100000) && (g1.yos+p1.yos>=40))
{cout<<"g1 and p1 can get 10 lakh loan"<<endl;}
else{cout<<"Sorry to tell g1 and p1 of id are not matching any type of loan.."<<endl;}

if(g2.disiplinary==0 && p1.rate>=3 && (g2.moth_inco+p1.moth_inco>=50000) && (g2.yos+p1.yos>=30))
{cout<<"g2 and p1 can get 5 lakh loan"<<endl;}
else if(g2.disiplinary==0 && p1.rate>=3 && (g2.moth_inco+p1.moth_inco>=100000) && (g2.yos+p1.yos>=40))
{cout<<"g2 and p1 can get 10 lakh loan"<<endl;}
else{cout<<"Sorry to tell g2 and p1 of id are not matching any type of loan.."<<endl;}

if(g1.disiplinary==0 && p2.rate>=3 && (g1.moth_inco+p2.moth_inco>=50000) && (g1.yos+p2.yos>=30))
{cout<<"g1 and p2 can get 5 lakh loan"<<endl;}
else if(g1.disiplinary==0 && p2.rate>=3 && (g1.moth_inco+p2.moth_inco>=100000) && (g1.yos+p2.yos>=40))
{cout<<"g1 and p2 can get 10 lakh loan"<<endl;}
else{cout<<"Sorry to tell g1 and p2 of id are not matching any type of loan.."<<endl;}

if(g2.disiplinary==0 && p2.rate>=3 && (g2.moth_inco+p2.moth_inco>=50000) && (g2.yos+p2.yos>=30))
{cout<<"g2 and p2 can get 5 lakh loan"<<endl;}
else if(g2.disiplinary==0 && p2.rate>=3 && (g2.moth_inco+p2.moth_inco>=100000) && (g2.yos+p2.yos>=40))
{cout<<"g2 and p2 can get 10 lakh loan"<<endl;}
else{cout<<"Sorry to tell g2 and p2 of id are not matching any type of loan.."<<endl;}

cout<<"Two pair g1,g2 and p1,p2 from same class not eligible to take any type of joint loan"
    <<endl;
}
else{cout<<"please give a input from given options...";}
}
int main()
{
govemply g1(2021,260,25000,15,0);
govemply g2(2025,300,50000,16,0);
priemply p1(2029,500,50000,12,3);
priemply p2(2028,400,78000,25,3);
checkloan(g1,g2,p1,p2);
}

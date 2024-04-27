#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class staff
{
public:
    string code;
    char name[100];
public:
    void set_info()
    {   cout<<"Enter your name and code"<<endl;
        cin>>name>>code;
    }
};
class teacher : public staff
{
protected:
    char sub[100], publication[100];
public:
    void set_details()
    {   cout<<"Enter your subject and publication"<<endl;
        cin>>sub>>publication;
    }
    void show()
    {
        cout << "\nName is "<<name<<"\nInserted code is "<<code<<"\nsubject is "<<sub <<"\npublication is "<<publication << endl;
    }
};
class officer : public staff
{
    char grade[100];
public:
    void set_details()
    {   cout<<"Enter your grade"<<endl;
        cin>>grade;
    }
    void show()
    {
        cout << " Name is "<<name<<"\nCode is "<<code <<"\nCategory is "<<grade << endl;
    }
};
class typist : public staff
{
protected:
    float speed;
public:
    void set_speed()
    {   cout<<"\nEnter your speed ";
        cin>>speed;
        
    }
};
class regular : public typist
{
protected:
    float wage;
public:
    void set_wage() {cout<<"Enter your wage please "<<endl;
        cin>>wage; }
    void show()
    {
        cout << "\nName is "<<name<< "\nCode is "<<code << "\nSpeed is" <<speed 
             << "\nYour wage is "<<wage<<endl;
             
    }
};
class causal : public typist
{
    float wage;
public:
    void set_wage() { cout<<"Enter your wage please "<<endl;
        cin>>wage; }
    void show()
    {
       cout << "\nName is "<<name<< "\nCode is "<<code << "\nSpeed is " <<speed 
             << "\nYour wage is "<<wage<<endl;
    }
};

int main()
{
    cout<<"Give me information about teacher"<<endl;
    teacher t;
    t.set_info();
    t.set_details();
    cout<<endl<<"Give me information about officer"<<endl;
    officer o;
    o.set_info();
    o.set_details();
    cout<<endl<<"Give me information about regular typist"<<endl;
    regular rt;
    rt.set_info();
    rt.set_speed();
    rt.set_wage();
    cout<<<<endl<<"Give me information about causal typist"<<endl;
    causal ct;
    ct.set_info();
    ct.set_speed();
    ct.set_wage();
    cout <<endl<< "  About teacher: " << endl;
    t.show();
    cout << endl<<" About officer:" << endl;
    o.show();
    cout << endl<<" About regular typist :" << endl;
    rt.show();
    cout <<endl<< " About causal typist :" << endl;
    ct.show();
    return 0;
}
#include<iostream>
using namespace std;
int count=0;
class alpha
{
    public:
    alpha()
        { count++;
        cout<<"\n no of objects are created "<<count<<endl;
        }
    ~alpha()
    {
        cout<<"\n no of objects are destructed"<<count;
        count--;
    }
    
};
int main()
{
    cout<<"\n\n enter main \n ";
    alpha a1,a2,a3,a4;
    {
        cout <<" enter block name 1\n";
        alpha a5;
    }
    {
        cout <<"/n enter block name 2\n";
        alpha a6;
    }
    alpha a9;
    cout<<"\n\n re-enter main \n ";
    return 0;
}
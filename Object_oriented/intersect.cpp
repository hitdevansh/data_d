#include<iostream>
using namespace std;
class line
{   public:
    double a,b,c;
    line(){
        cout<<"Enter the value of a,b,c"<<endl;
        cin>>a>>b>>c;
    }
    void intersect(line l1,line l2)
    {

    }
    friend void parellal(line &l1,line &l2)
    {
        if(((l1.a/l2.a)==(l1.b/l2.b))&& ((l1.b/l2.b)==(l1.c/l2.c)))
        {
            cout<<"this lines are parrella"<<endl;
        }
        else{
            cout<<"I don't care what the "<<endl;
        }
    }
};
int main()
{
line A,B;
parellal(A,B);
return 0;
}
#include<iostream>
using namespace std;
class scholl{
    int rank;
    public:
    scholl(){}
    scholl(int r){
        rank=r;
    }
    void sh()
    {
        cout<<"rank is "<<rank<<endl;
    }
};
class student{
    int id;
    public:
    student(){}
    student(int i){
        id=i;
    }
    void shs()
    {
        cout<<"id is "<<id<<endl;
    }

};
class marks :virtual public student ,virtual public scholl{
    int maths,physics;
    public:
    marks(){}
    marks(int a,int b,int c,int d):scholl(a),student(b){
        maths=c;
        physics=d;
    }
     void shsm()
    {
        cout<<"maths marks  is "<<maths <<"and physics marks is "<<physics<<endl;
    }
};
int main()
{
marks m1(12,2,3,4);
m1.sh();
m1.shs();
m1.shsm();
marks m2(m1);
m2.sh();
m2.shs();
m2.shsm();
}
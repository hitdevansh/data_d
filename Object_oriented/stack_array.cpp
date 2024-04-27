#include<iostream>
using namespace std;
#define N 5
int stack[N];
int top=-1;
void push()
{   int x;
    cout<<"enter value"<<endl;
    cin>>x;
    if(top==N-1)
    {cout<<"It is overflow";}
    else{
        top++;
        stack[top]=x;
    }
}
void display()
{
    for(int i=top;i>=0;i--)
    {cout<<stack[i];}
}
int main()
{
push();
push();
display();
return 0;
}
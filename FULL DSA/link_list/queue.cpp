#include<iostream>
using namespace std;
#define N 5
int queu[N];
int top=-1;
int rear=-1;
void enqu()
{   int x;
    cout<<endl<<"Enter a value to queue"<<endl;
    cin>>x;
    if(top==-1 && rear==-1)
    {
        top=0; rear=0;
        queu[rear]=x;
    }
    else if((rear+1)%N==top){cout<<"Queue is full";}
    else{
        rear=(rear+1)%N;
        queu[rear]=x;
    }
}
void deq()
{
    if(top==-1 && rear==-1)
    {
        cout<<"your queue is underflow";
    }
    else if(top==rear)
    {
        top=-1;
        rear=-1;
    }
    else
    {   cout<<"deque is "<<queu[top]<<endl;
        top=(top+1)%N;

    }
}
void display()
{
int i=top;
if(top==-1 && rear==-1){cout<<"underflow";}
else{
while (i!=rear && i<=rear)
{   cout<<queu[i];

    i++;
    /* code */
}
cout<<queu[rear];}
}
int main()
{
enqu();
enqu();
enqu();
deq();
display();
return 0;
}
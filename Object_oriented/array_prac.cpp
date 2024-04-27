#include<iostream>
using namespace std;
#define N 5
int array[N];
int size=-1;
int i=0;
void insertion()
{if(size==N)
{
    cout<<"its aa full sorry"<<endl;
}
else
{int p;
cout<<endl<<"enter a value to insett"<<endl;
cin>>p;
for(int i=size;i>=0;i--)
{array[i]=array[i-1];
}
array[0]=p;}}
void display()
{ 
    for(i=0;i<=size;i++)
    {
        cout<<array[i];
    }
}
int main()
{int o;
for(i=0;i<N;)
{   jump:
    cout<<"enter a element to push"<<endl;
    cin>>array[i];
    i++;
    cout<<"if u still want to push then press 1"<<endl;
    size++;
    cin>>o;
    if(o==1 ){goto jump;}
    else{goto p;}
}
p:
display();
insertion();
display();
return 0;
}
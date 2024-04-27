#include<iostream>
using namespace std;
void delet(int *a,int p);
int main()
{
int a[10];
cout<<"Enter the 10 elements for ur array:"<<endl;
for(int i=0;i<10;i++)
{
    cin>>a[i];
}
delet(a,10);
return 0;
}
void delet(int *a,int p)
{
    if(p<10 && p>0)
    {   
        for(int i=p-1;i<10;i++)
        {
            a[i]=a[i+1];
        }
    for(int i=0;i<10;i++)
    {
        cout<<a[i];
    }
    }
    else if(p==10)
    {for(int i=0;i<9;i++)
    {
        cout<<a[i];
    }

    }
    else {
        cout<<"you have entered invalid range of position"<<endl;
    }
    
   
}


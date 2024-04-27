#include<iostream>
using namespace std;
int main()
{
    int n,c=1;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
       
       if(i<n/2)
       {a[i]=i;}
       else
       {
           a[i]=-c;
           c++;
       }
    }
    return 0;
}
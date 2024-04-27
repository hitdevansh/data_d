#include<iostream>
using namespace std;
class maoperation
{   public:
    int m, n;
    maoperation(){
    cout<<"Enter the two dimention m and n for two matrix"<<endl;
    cin>>m>>n;
    int arr1[m][n];
    cout<<"enter a value rawwise"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {cin>>arr1[i][j];}
    }
    }
    void operator + (maoperation b)
    {
        if(b.m==a.m && b.n==a.n)
        {
        maoperation array[a.m][a.n];
        for(int i=0;i<m;i++)
        {
        for(int j=0;j<n;j++)
        {   array[i][j]=a[i][j]+b[i][j];
            cout<<array[i][j];}
        }
        }
        else{
            cout<<"This is not possible"<<endl;
        }
    }
};
int main()
{
maoperation a,b;
a.operator+ (b);
return 0;
}
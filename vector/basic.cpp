#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>&v)
{
    cout<<"size is "<<v.size()<<endl;
    for(int l=0;l<v.size();l++)
    {
        cout<<v[l]<<" ";
    }
    cout<<endl;
}
int main()
{
vector<vector<int>>v;
int n;
cout<<"How much vector u need "<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
    cout<<"Enter how many element u want to push in vector "<<i+1<<endl;
    int en;
    cin>>en;
    v.push_back(vector<int>());
    for(int j=0;j<en;j++)
    {
        cout<<"Enter a "<<j+1<<" element"<<endl;
        int p;
        cin>>p;
        v[i].push_back(p);
    }
}
//print(<int>>v);
for(int t=0;t<n;t++)
{
    print(v[t]);
}
return 0;
}
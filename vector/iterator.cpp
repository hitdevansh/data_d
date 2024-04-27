#include <bits/stdc++.h>
#include<iostream>
using namespace std;
//its like pointer basically
int main()
{
vector<int>v;
int n;
cin>>n;
for(int i=0;i<n;i++)
{   int x;
    cin>>x;
    v.push_back(x);
}
vector<int>::iterator it;
//it=v.begin();
for(it=v.begin();it!=v.end();it++)
{cout<<*it<<" ";}
cout<<endl;


// range base 
// val ka datatype will be a type of a vector
for(int val : v){cout<<val<<" ";}
//
return 0;
}
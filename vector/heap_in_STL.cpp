#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
vector <int> v1={8,65,12,224,32,01,0};
make_heap(v1.begin(),v1.end());
cout<<v1.front()<<endl;
v1.push_back(322);
push_heap(v1.begin(),v1.end());
cout<<v1.front()<<endl;
for(auto i:v1){cout<<i<<" ";}
cout<<endl;
v1.pop_back();
for(auto i:v1){cout<<i<<" ";}
return 0;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<int>ans;
ans.push_back(2);
ans.erase(ans.begin());
ans.push_back(5);
for(int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<i<<endl;
}
cout<<ans.size()<<endl;
return 0;
}
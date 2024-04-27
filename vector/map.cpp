#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void print(multimap<string,string> & v)
{cout<<"size is "<<v.size()<<endl;
for(auto &it: v){cout<<it.first<<" "<<it.second<<endl;}}
int main()
{
//maps stores value as a sorted following to value of  keys
multimap<string,string>v;
v.insert({"a","tej"}); //insert key size*O(log (n))
string a="a";
v.insert({"dalwadi","bap"});
//v["l"]="sakht";
//auto it;
print(v);
//auto it=v.find("l");// time com O(log (n))
v.insert({"m","tejass"});
string p1,p2;
cin>>p1>>p2;
v.insert({p1,p2});
//v.erase(it);
print(v);
return 0;
}
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// pair<int ,int>p1,p2,p3;
// p1=make_pair(0,5);
// p2=make_pair(1,2);
// p3=max(p1,p2);
// cout<<p3.first<<" "<<p3.second<<endl;
// return 0;
// }
// int main()
// {   set<string>p1;
//     p1.insert("devansh");
//     p1.insert("tejas");
//     p1.insert("neelam");
//     for(auto &p : p1)
//     {
//         cout<<p<<endl;
//     }
//     return 0;
// }
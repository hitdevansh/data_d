#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void solve()
{
    ll n,w,h;
    cin>>n>>w>>h;
    ll ac[n],ch[n];
    for(ll i=0;i<n;i++){cin>>ac[i];}
    for(ll i=0;i<n;i++){cin>>ch[i];}
    map<pair<int, int>, pair<int,int>> ranges;
    for(ll i=0;i<n;i++){
        ranges.insert({ make_pair(ac[i]-w,ac[i]+w),make_pair(ch[i]-h,ch[i]+w)});
    }
    ll diff=ac[0]-w-ch[0]+h;
    for(auto it:ranges)
    {   
        auto key_pair1 = it.first;
        auto key_pair2 = it.second;
        it.second=make_pair(key_pair2.first+diff,key_pair2.second+diff);
        // key_pair2.first+=diff;
        // key_pair2.second+=diff;
    }
    for (const auto entry: ranges)
    {
        auto key_pair1 = entry.first;
        auto key_pair2 = entry.second;
        cout << "{" << key_pair1.first << "," << key_pair1.second << "}";
        cout << "{" << key_pair2.first << "," << key_pair2.second << "}"<<endl;
    }
    int flag=0;

    diff=0;
    for(auto it:ranges)
    {   
        auto key_pair1 = it.first;
        auto key_pair2 = it.second;
        key_pair2.first+=diff;
        key_pair2.second+=diff;
        if(key_pair2.first>=key_pair1.first){cout<<"teuw"<<" ";}
        if(key_pair2.second<=key_pair1.second){cout<<"true "<<endl;}
        if(key_pair2.first>=key_pair1.first && key_pair2.second<=key_pair1.second)
        {cout<<"c1"<<endl;break;}
        else
        {   flag++;
            if(key_pair2.first<key_pair1.first){diff=key_pair1.first-key_pair2.first;}
            else{diff=key_pair1.second-key_pair2.second;}
        }
        cout<<endl;
        for (const auto entry: ranges)
        {
        auto key_pair1 = entry.first;
        auto key_pair2 = entry.second;
        cout << "{" << key_pair1.first << "," << key_pair1.second << "}";
        cout << "{" << key_pair2.first << "," << key_pair2.second << "}"<<endl;
        }
        if(flag>n){cout<<"NO"<<endl;return;}
    }
   
    cout<<"YES"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {solve();}
}
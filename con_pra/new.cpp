#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void solve()
{
    int n,m,m2;
    cin>>n>>m;
    int m1=m;
    int roomnum=ceil(n/2.0);
    
    int type[n],s[n];
    for(int i=0;i<n;i++)
    {cin>>type[i];}
    
    for(int i=0;i<n;i++)
    {cin>>s[i];}
    
    for(int i=0;i<roomnum;i++)
    {
        if(type[i]==1){m+=s[i];}
        else
        {m-=s[i];}
        if(m<0){break;} 
    }
    m2=m1;
    for(int i=n-1;i>=roomnum;i--)
    {
        if(type[i]==1){m2+=s[i];}
        else
        {m2-=s[i];}
        if(m2<0){break;}
    }
    
    int ans =max(m,m2);
    if(ans<=0){cout<<"NO"<<endl;}
    else cout<<"YES "<<ans<<endl;
}

int main() { 
    int t;
    cin>>t;
    while(t--)
    {solve();}
    return 0;
}

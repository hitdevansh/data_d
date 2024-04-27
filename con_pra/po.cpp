
#include <bits/stdc++.h>
using namespace std;

long long maximumSumOfHeights(vector<int> &a)
{
    int n = a.size();
    vector<int> lm(n, 0), ls(n, 0), rm(n, 0), rs(n, 0);
    int mini = INT_MAX;
    mini = a[0];
    for (int i = 0; i < n; i++)
    {
        if (mini > a[i])
        {
            mini = a[i];
        }
        lm[i] = mini;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << lm[i] << " ";
    // }
    // cout << endl;
    mini = a[n-1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (mini > a[i])
        {
            mini = a[i];
        }
        rm[i] = mini;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << rm[i] << " ";
    // }
    ls[n-1] = lm[n-1]; 
    for(int i=n-2;i>=0;i--){
        ls[i] = lm[i] + ls[i+1];
    }
    rs[0] = rm[0];
    for (int i = 1; i<n; i++)
    {
        rs[i] = rm[i] + rs[i-1];
    }
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ls[i] << " ";
    // }
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << rs[i] << " ";
    // }
    // cout << endl;
    long long ans = INT_MIN;
    int large = *max_element(a.begin(), a.end());
    // cout<<"large is "<<large<<endl;
    for(int i=0;i<n;i++){
        if(a[i]==large)
        {
            if(i==0){
                if (ans < a[i]+ls[i+1])
                {   ans = (a[i] +ls[i+1]);}
            }
            else if(i==n-1){
                if (ans < a[i] + rs[i - 1])
                    ans = (a[i] + rs[i - 1]);
            }
            else if (ans < (a[i] + ls[i+1] + rs[i-1]))
                ans = (a[i] + ls[i+1] + rs[i-1]);
            }
    }
    return ans;
}

int main()
{
    vector<int> A = {5, 3, 4, 1, 1};
    long long ans = maximumSumOfHeights(A);
    cout << ans << endl;
    return 0;
}
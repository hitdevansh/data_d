#include <bits/stdc++.h>
#define vinarrn vector<int> arr(n)
#define takevec                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    bool flag = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            continue;
        }
        if (!flag) {
            if (a[i] < b[i]) {
                swap(a[i], b[i]);
            }
            flag = true;
        } else {
            if (b[i] < a[i]) {
                swap(a[i], b[i]);
            }
        }
    }
    cout << a << endl << b << endl;

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

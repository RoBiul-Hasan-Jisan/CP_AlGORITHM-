#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> aa(k);
    for (int i = 0; i < k; i++) cin >> aa[i];

    int i = 0, j = 0;
    while (i < n && j < k) {
        if (a[i] <= aa[j]) cout << a[i++] << " ";
        else cout << aa[j++] << " ";
    }
    while (i < n) cout << a[i++] << " ";
    while (j < k) cout << aa[j++] << " ";
    cout << "\n";
}

int main()
{
    


    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

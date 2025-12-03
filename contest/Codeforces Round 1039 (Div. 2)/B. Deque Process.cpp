#include <bits/stdc++.h>
using namespace std;
//segment tree
using ll = long long;

const ll INF = (ll)4e18;
int n;
vector<ll> a, b;
vector<ll> seg;

void Solve(){

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int l = 0, r = n - 1;
    string ans;
    int t = 0;
    while (l < r) {
        if ((p[l] < p[r]) ^ t)
            ans += "LR";
         else
            ans += "RL";

        l++;
        r--;
        t ^= 1;
    }
    if (l == r)
        ans += 'L';

    cout << ans << "\n";
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
       // cin >> n;
        //b.resize(n);
        //for (int i = 0; i < n; i++) cin >> b[i];
          Solve();
        //cout << (Tree() ? "YES\n" : "NO\n");
    }

    return 0;
}

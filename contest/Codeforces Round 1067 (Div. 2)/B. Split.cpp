#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef int64_t ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> graph;
#define int long long
// Constants
//const int MOD = 1e9 + 7;
const int MAXI = 1e6 + 6;
const ll INF = 1e18;
const ll CH = 1e9 + 4;
const ll VH = 1e7 + 4;

// Fast I/O
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Shortcuts
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
void solve()
{
    int n;
    if (!(cin >> n)) return;

    int m=2*n;

    vector<int> cnt(m+1,0);

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int c_od = 0;
    int c_ev = 0;

    for (int i = 1; i <= m; ++i) {
        if (cnt[i] > 0) {
            if (cnt[i] % 2 != 0)
                c_od++;
            else
                c_ev++;

        }
    }

    int ans = 2*c_ev+c_od;

    if (c_od== 0) {
        if ((n % 2) != (c_ev%2))
            ans -= 2;

    }

    cout << ans <<endl;



}




int32_t main()
{
    fastio();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
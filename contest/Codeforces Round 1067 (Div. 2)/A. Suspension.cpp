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
const ll INF = 1e9;
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
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define rrep(i,a,b) for (int i = (a); i >= (b); --i)


// Debug
#define debug(x) cerr << #x << " = " << x << endl





void solve()
{
    int n,y,r;
    cin >>n>>y>>r;
        cout << min(n,r+y/ 2) << "\n";

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
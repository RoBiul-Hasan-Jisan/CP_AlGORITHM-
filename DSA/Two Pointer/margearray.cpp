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

// Constants
const int MOD = 1e9 + 7;
const int MAXI = 1e6 + 6;
const ll INF = 1e18;
const ll VH = 1e9 + 4;
const ll CH = 1e7 + 4;

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

// GCD and LCM
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

// Modular Exponentiation
ll mod_exp(ll base, ll exp, ll mod)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Upper Bound Index (first > x)
ll upper_bound_idx(const vector<ll>& arr, ll x)
{
    ll low = 0, high = arr.size() - 1, ans = arr.size();
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

// Lower Bound Index (last < x)
ll lower_bound_idx(const vector<ll>& arr, ll x)
{
    ll low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] < x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// Sieve of Eratosthenes
vector<bool> is_prime(CH, true);
void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i < CH; ++i)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j < CH; j += i)
                is_prime[j] = false;
        }
    }
}

// Primality Check
bool isPrime(ll n)
{
    if (n < CH) return is_prime[n];
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

// Input Helpers
vll read_vector(int n)
{
    vll v(n);
    for (auto &x : v) cin >> x;
    return v;
}
void print_vector(const vll& v)
{
    for (ll x : v) cout << x << ' ';
    cout << endl;
}


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
    fastio();


    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
//segment tree
using ll = long long;

const ll INF = (ll)4e18;
int n;
vector<ll> a, b;
vector<ll> seg;

void Solve(){
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int minm = 1e9+1;
    for(int i=0; i<n; i++){
        minm = min(a[i], minm);
        if(a[i]>=minm *2){
            cout << "NO" <<"\n";
            return;
        }
    }
    cout << "YES" << "\n";



};
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

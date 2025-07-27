#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n +4);
        for (int i = 1; i <= n; i++) cin >> a[i];


        vector<int> vec(n + 2, n + 1);

      //0(n*t)
        for (int i = n - 1; i >= 1; i--) {
            int j = i + 1;

            while (j <= n && a[j] <= a[i]) {
                j = vec[j];
            }
            vec[i] = j;
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += (ll)i * (vec[i] - i);
        }
        cout << ans << "\n";
    }

    return 0;
}

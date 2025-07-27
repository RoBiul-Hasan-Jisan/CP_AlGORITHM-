#include <bits/stdc++.h>
using namespace std;

#define int long long

void Solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    int c1 = 0;
    int k = 0;

    int st = n - 1;
    int ed = n - 1;

    while (st >= 0)
    {

        int pow = 1LL << min(k, 60LL);
        int diff = c / pow;


        while (st >= 0 && a[st] > diff)
            --st;


        if (st >= 0)
        {


            for (int i = st; i < ed; ++i)
                swap(a[i], a[i + 1]);

            ed--;
        }
        else
        {

            c1++;
            ed--;
        }

        st = ed;
        k++;
    }

    cout << c1 << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) Solve();

    return 0;
}

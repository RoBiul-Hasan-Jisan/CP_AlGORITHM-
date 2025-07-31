#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 2;
void solve()
{
//interview question prb 1
//4 5 6 1 3 4 1
//we need to  find largest element
//two pointer sorting  tc  nlog n
//alt : fixed a variable as its max than compair if find than it will be update tc 0(n)

    int n;
    cin >>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)cin>>arr[i];
    int maxa =arr[0];
    for(int i=0; i<n; i++)
    {
        if(maxa<arr[i])
            maxa = arr[i];
    }
    cout<<maxa<<endl;
}
signed main()
{
    IOS;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

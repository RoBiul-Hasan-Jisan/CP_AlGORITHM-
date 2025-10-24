//kth smallest pair sum
int cnt(vector<int>& a, int x)
{
    int j = a.size() - 1, c = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (j >= 0 && a[i] + a[j] > x) j--;
        c += j + 1;
    }
    return c;
}
=>slove
sort(array)
int l = 2*a[0], r = 2*a.back(), mid = r;
while (l <= r)
{
    int m = (l + r) >> 1;
    if (cnt(a, m) >= k) {
        mid = m;
        r = m - 1;
    } else {
        l = m + 1;
    }
}
cout << mid << endl;

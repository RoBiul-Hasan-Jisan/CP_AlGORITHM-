#include <bits/stdc++.h>
using namespace std;
//8 5
//1 2 3 4 1 2 3 4


//K=3 false
//k=4 false

// approch was simple just frist we think i  need  unique something 
//thats way i  go  for set  and  hare  



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];   
    }

    unordered_set<int> s;

    for(int i = 0; i < n; i++) {
      
        if(s.count(a[i])) {
            cout << "true";
            return 0;
        }

        s.insert(a[i]);

       
        if(s.size() > k) {
            s.erase(a[i - k]);
        }
    }

    cout << "false";
    return 0;
}

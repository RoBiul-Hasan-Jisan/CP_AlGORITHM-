#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n + 1, 0);      
    vector<int> diff(n + 2, 0);     
    vector<int> prefix(n + 1, 0);    

    // Apply all range updates
    for (int i = 0; i < q; i++) {
        int L, R, x;
        cin >> L >> R >> x;
        diff[L] += x;
        diff[R + 1] -= x;
    }

    
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];   
        arr[i] += diff[i];        
        prefix[i] = prefix[i - 1] + arr[i]; 
    }

   
    int queries;
    cin >> queries;
    while (queries--) {
        int L, R;
        cin >> L >> R;
        cout << prefix[R] - prefix[L - 1] << endl;
    }

    return 0;
}

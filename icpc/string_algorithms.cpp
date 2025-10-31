#include <bits/stdc++.h>
using namespace std;

// LCS 
int lcs(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// LIS
// O(n^2) 
int LIS_N2(vector<int>& nums) {
    int n = nums.size(), maxLIS = 1;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLIS = max(maxLIS, dp[i]);
    }
    return maxLIS;
}

// O(n log n) version
int LIS_NlogN(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> tails;
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) tails.push_back(num);
        else *it = num;
    }
    return tails.size();
}

//  KMP 
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
    return lps;
}

void KMPSearch(const string& text, const string& pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lps = computeLPSArray(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) { i++; j++; }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

// Rabin-Karp
void rabinKarpSearch(const string& text, const string& pattern, int d=256, int q=101) {
    int n = text.length(), m = pattern.length();
    int p = 0, t = 0, h = 1;

    for (int i = 0; i < m - 1; i++) h = (h * d) % q;
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) if (text[i + j] != pattern[j]) break;
            if (j == m) cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}


int main() {
    // LCS Example 
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << "LCS length: " << lcs(s1, s2) << endl;

    //  LIS Example
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS (O(n^2)) length: " << LIS_N2(nums) << endl;
    cout << "LIS (O(n log n)) length: " << LIS_NlogN(nums) << endl;

    //  KMP Example
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    cout << "KMP search results:" << endl;
    KMPSearch(text, pattern);

    //  Rabin-Karp Example 
    string text2 = "GEEKS FOR GEEKS";
    string pattern2 = "GEEK";
    cout << "Rabin-Karp search results:" << endl;
    rabinKarpSearch(text2, pattern2);

    // Set Search Example
    set<int> store = {1, 2, 3, 4, 5};
    int qs = 3;
    if (store.find(qs) != store.end()) {
        cout << "Element " << qs << " found in store!" << endl;
    }

    // Substring Find Example
    string A = "HELLO WORLD";
    string B = "WORLD";
    size_t index = A.find(B);
    if (index != string::npos)
        cout << "B is a substring of A at index: " << index << endl;
    else
        cout << "B is not a substring of A" << endl;

    return 0;
}

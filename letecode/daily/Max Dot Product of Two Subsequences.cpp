//tle
class Solution {
private:
    typedef long long ll;
    int n, m;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i == n || j == m) return -1e9;

        
        int c1 = nums1[i] * nums2[j];
        int c2 = (nums1[i] * nums2[j]) + solve(i + 1, j + 1, nums1, nums2);
        int c3 = solve(i + 1, j, nums1, nums2);
        int c4 = solve(i, j + 1, nums1, nums2);

        return max({c1, c2, c3, c4});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        return solve(0, 0, nums1, nums2);
    }
};


// still  worst 

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        const int INF = -1e9;

        vector<int> prev(m + 1, INF), curr(m + 1, INF);

        for (int i = 1; i <= n; i++) {
            curr.assign(m + 1, INF);

            for (int j = 1; j <= m; j++) {
                int product = nums1[i - 1] * nums2[j - 1];

                curr[j] = max({
                    prev[j],            
                    curr[j - 1],        
                    product + max(0, prev[j - 1]) 
                });
            }

            swap(prev, curr);
        }

        return prev[m];
    }
};
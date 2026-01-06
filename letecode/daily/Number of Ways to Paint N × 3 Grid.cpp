class Solution {
public:
    int numOfWays(int n) {
        

       long long  mod = 1e9+7;
        long long  a =6,b=6;
        for(int i = 2; i <= n; i++)

        {
           long long na = (a * 3+ b * 2)% mod;
           long long nb = (a * 2+ b * 2)% mod;
           a = na;
           b = nb;
        }
        return (a + b) % mod;
    }
};
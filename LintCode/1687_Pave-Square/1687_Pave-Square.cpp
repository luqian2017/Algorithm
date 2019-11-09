class Solution {
public:
    /**
     * @param n: The param n means 2*n rectangular square.
     * @return: Return the total schemes.
     */
    long long getTotalSchemes(int n) {
        vector<long long> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};
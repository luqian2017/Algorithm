class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        if (n <= 1) return 1;
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));  //dp[out][in]
        
        for (int i = 0; i <= n; ++i) dp[0][i] = 1;
        
        for (int i = 0; i <= n; ++i) {
            
            if (i > 0) dp[i][0] = dp[i - 1][1];
            
            for (int j = 0; j <= n - i; ++j) {
                if (i > 0 && j > 0)
                    dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
            }
        }
        
        return dp[n][0];
    }
};
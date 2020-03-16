class Solution {
public:
    /**
     * @param n: the number of people
     * @param m: the number of groups
     * @return: the number of grouping options
     */
    long long groupingOptions(int n, int m) {
        if (n < m) return 0;
        //dp[i][j] is the number of options that i people are divided into j groups    
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                for (int k = 1; k <= j; ++k) {
                    dp[i][j] += dp[i - j][k];                    
                }
            }
        }
        
        return dp[n][m];
    }
};
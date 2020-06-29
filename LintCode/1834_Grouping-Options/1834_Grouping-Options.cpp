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
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
        for (int i = 1; i <= m; ++i) {
            dp[i][i] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= min(i, m); ++j) {  //j<=m is also right
                for (int k = 1; k <= j; ++k) {
                    dp[i][j] += dp[i - j][k];                
                }
            }
        }
        
        return dp[n][m];
    }
};
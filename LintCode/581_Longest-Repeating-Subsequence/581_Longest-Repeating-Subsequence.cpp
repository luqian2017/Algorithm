class Solution {
public:
    /**
     * @param str: a string
     * @return: the length of the longest repeating subsequence
     */
    int longestRepeatingSubsequence(string &str) {
        int n = str.size();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str[i - 1] == str[j - 1] && i != j) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][n];
    }
};
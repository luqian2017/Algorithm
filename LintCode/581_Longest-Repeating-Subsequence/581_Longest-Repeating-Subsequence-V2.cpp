class Solution {
public:
    /**
     * @param str: a string
     * @return: the length of the longest repeating subsequence
     */
    int longestRepeatingSubsequence(string &str) {
        int n = str.size();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (str[i] == str[j] && i != j) {
                    if (i > 0 && j > 0) dp[i][j] = dp[i - 1][j - 1] + 1;
                    else dp[i][j] = 1;
                } else {
                    if (i > 0 && j > 0) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    else if (i == 0 && j > 0) dp[0][j] = dp[0][j - 1];
                    else if (i > 0 && j == 0) dp[i][0] = dp[i - 1][0];
                }
            }
        }
        
        return dp[n - 1][n - 1];
    }
};
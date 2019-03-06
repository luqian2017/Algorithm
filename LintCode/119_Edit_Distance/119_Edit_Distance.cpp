class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        int m = word1.size();
        int n = word2.size();
        if (m == 0) return n;
        if (n == 0) return m;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        bool hasSameChar = false;
        if (word1[0] == word2[0]) {
            dp[0][0] = 0;
            hasSameChar = true;
        }else {
            dp[0][0] = 1;
        }
        
        for (int i = 1; i < m; ++i) {
            if (hasSameChar) {
                dp[i][0] = i; //i + 1 chars, i operations
            } else if (word1[i] == word2[0]) {
                dp[i][0] = dp[i - 1][0];
                hasSameChar = true;
            } else {
                dp[i][0] = dp[i - 1][0] + 1;   
            }
        }
        
        hasSameChar = (dp[0][0] == 0);
        for (int i = 1; i < n; ++i) {
            if (hasSameChar) {
                dp[0][i] = i; //i + 1 chars, i operations
            } else if (word2[i] == word1[0]) {
                dp[0][i] = dp[0][i - 1];
                hasSameChar = true;
            } else {
                dp[0][i] = dp[0][i - 1] + 1;   
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
               dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
               if (word1[i] == word2[j]) {
                   dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
               } else {
                   dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
               }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
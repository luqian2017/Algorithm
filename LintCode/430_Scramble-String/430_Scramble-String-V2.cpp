class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: Another string
     * @return: whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        if (s1 == s2) return true;
        
        int n = s1.size();
        int n2 = s2.size();
        if (n != n2) return false;
        
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s1[i] == s2[j]) dp[i][j][1] = true;
            }
        }
        
        for (int k = 2; k <= n; ++k) { // k is the len of the substring
            for (int i = 0; i <= n - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    for (int w = 1; w < k; ++w) { //note: not w <= k
                      if (dp[i][j][w] && dp[i + w][j + w][k - w]) {
                          dp[i][j][k] = true;
                          break;
                      }
                      if (dp[i][j + k - w][w] && dp[i + w][j][k - w]) {
                          dp[i][j][k] = true;
                          break;
                      }
                    }
                }
            }
        }
        
        return dp[0][0][n];
    }
    
};
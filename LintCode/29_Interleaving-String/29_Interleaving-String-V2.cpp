class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        int L = s1.size();
        int M = s2.size();
        int N = s3.size();
        if (N != L + M) return false;
        
        vector<vector<bool>> dp(L + 1, vector<bool>(M + 1, false));
        
        dp[0][0] = true;

        for (int i = 1; i <= L; ++i) {
            dp[i][0] = s3[i - 1] == s1[i - 1];
        }
        
        for (int i = 1; i <= M; ++i) {
            dp[0][i] = s3[i - 1] == s2[i - 1];
        }
        
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (dp[i - 1][j]) {
                    if (s1[i - 1] == s3[i + j - 1]) dp[i][j] = true;
                } else if (dp[i][j - 1]) {
                    if (s2[j - 1] == s3[i + j - 1]) dp[i][j] = true;
                }
            }
        }
        
        return dp[L][M];
    }
    
};
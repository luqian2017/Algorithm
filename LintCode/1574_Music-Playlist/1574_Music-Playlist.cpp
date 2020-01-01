class Solution {
public:
    /**
     * @param n: the number of on his mobile phone
     * @param m: in the middle of two songs, there are at least m other songs
     * @param p: the number of songs he can listen to
     * @return: the number of playlists
     */
    int getAns(int n, int m, int p) {
        vector<vector<long long>> dp(p + 1, vector<long long>(n + 1));
        dp[0][0] = 1;
        
        for (int i = 1; i <= p; ++i) {
            for (int j = 1; j <= n; ++j) {
                //dp[i][j] can be transformed from dp[i - 1][j - 1] and dp[i - 1][j]
                //dp[i - 1][j - 1]: in the first i - 1 songs, there are j - 1 unique songs 
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % 1000000007;
                //dp[i - 1][j]: in the first i - 1 songs, there are already j unique songs
                if (j > m) {
                    dp[i][j] = (dp[i][j] + (dp[i - 1][j] * (j - m) % 1000000007)) % 1000000007;
                }
            }
        }   
        return (int)dp[p][n];
    }
};
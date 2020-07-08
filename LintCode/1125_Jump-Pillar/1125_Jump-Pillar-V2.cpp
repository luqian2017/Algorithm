class Solution {
public:
    /**
     * @param h: the height of n pillar
     * @param k: the limit
     * @return: Xiao Yi can or can't reach the n-th pillar
     */
    bool jumpPillar(vector<int> &h, int k) {
        int len = h.size();
        
        vector<vector<bool>> dp(len, vector<bool>(2, false));
        //dp[i][j] = 1 shows if jump to i is possible, 0 impossible.
        // j = 0, the super power is unused, j = 1 used.
        
        dp[0][0] = true;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j <= min(len - 1, i + k); ++j) {
                if (h[i] >= h[j]) {
                    dp[j][0] = dp[i][0] || dp[j][0];
                    dp[j][1] = dp[i][0] || dp[j][1];
                }
                dp[j][1] = dp[i][0] || dp[j][1];
            }
        }
        
        if (dp[len - 1][0] || dp[len - 1][1] ) return true;
        return false;
        
    }
};
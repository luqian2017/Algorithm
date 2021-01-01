class Solution {
public:
    /**
     * @param steps: steps you can move
     * @param arrLen: the length of the array
     * @return: Number of Ways to Stay in the Same Place After Some Steps
     */
    int numWays(int steps, int arrLen) {
        if (steps == 0 || arrLen == 0) return 0;
        vector<vector<int>> dp(steps + 1, vector<int>(arrLen + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < arrLen; i++) dp[0][i] = 0;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < arrLen; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] + dp[i - 1][j];    
            }
        }
        
        return dp[steps][0];
    }
};

//Memory space out of limit!!!
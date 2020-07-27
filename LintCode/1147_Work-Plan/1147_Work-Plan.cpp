class Solution {
public:
    /**
     * @param low: the simple task
     * @param high: the complex task
     * @return: the most value
     */
    int workPlan(vector<int> &low, vector<int> &high) {
        int n = low.size();

        //dp[i][j] the max value upto the ith week, and does the j work - 1:high, 0:low
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = low[0]; 
        dp[1][0] = low[0] + low[1];
        dp[1][1] = high[1];

        for (int i = 2; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0] + low[i], dp[i - 1][1] + low[i]);
            dp[i][1] = max(dp[i - 2][0] + high[i], dp[i - 2][1] + high[i]);
        }
        
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
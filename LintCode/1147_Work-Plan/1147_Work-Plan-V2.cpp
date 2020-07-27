class Solution {
public:
    /**
     * @param low: the simple task
     * @param high: the complex task
     * @return: the most value
     */
    int workPlan(vector<int> &low, vector<int> &high) {
        int n = low.size();

        //dp[i] the max value upto the ith week
        vector<int> dp(n, 0);
        dp[0] = low[0]; 
        dp[1] = max(low[0] + low[1], high[1]);
        
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1] + low[i], dp[i - 2] + high[i]);
        }
        
        return dp[n - 1];
    }
};
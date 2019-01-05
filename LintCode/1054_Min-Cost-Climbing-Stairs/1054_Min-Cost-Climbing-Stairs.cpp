class Solution {
public:
    /**
     * @param cost: an array
     * @return: minimum cost to reach the top of the floor
     */
    int minCostClimbingStairs(vector<int> &cost) {
        int len = cost.size();
        if (len == 0) return 0;
        
        vector<int> dp(len, 0);
        int result = 0;
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i = 2; i < len; ++i) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        
        return min(dp[len - 1], dp[len - 2]);
    }
};
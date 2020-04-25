class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int colors = costs[0].size();
        
        //dp[i][j] is the minimum cost when ith house uses color j
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        for (int i = 0; i < colors; ++i) {
            dp[0][i] = costs[0][i];
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < colors; ++j) {
                for (int k = 0; k < colors; ++k) {
                    if (k != j) dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                }
            }
        }
        
        int result = INT_MAX;
        for (int i = 0; i < colors; ++i) {
            result = min(result, dp[n - 1][i]);
        }
        
        return result;
    }
};
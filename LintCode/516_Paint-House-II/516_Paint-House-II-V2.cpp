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
        if (colors <= 1) return 0;
        
        //dp[i][j] is the minimum cost when ith house uses color j
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int min1 = 0, min2 = 1;
        
        if (costs[0][0] > costs[0][1]) {
            min1 = 1;
            min2 = 0;
        }
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        for (int i = 2; i < colors; ++i) {
            dp[0][i] = costs[0][i];
            if (dp[0][i] < dp[0][min1]) {
                min2 = min1;
                min1 = i;
            } else if (dp[0][i] < dp[0][min2]) {
                min2 = i;
            }
        }

        for (int i = 1; i < n; ++i) {
            int last1 = min1, last2 = min2;
            min1 = -1; min2 = -1;
            for (int j = 0; j < colors; ++j) {
                if (j == last1) {
                    dp[i][j] = dp[i - 1][last2] + costs[i][j];
                } else {
                    dp[i][j] = dp[i - 1][last1] + costs[i][j];
                }
                if (min1 < 0 || dp[i][j] < dp[i][min1]) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 < 0 || dp[i][j] < dp[i][min2]) {
                    min2 = j;
                }
            }
        }

        
        return dp[n - 1][min1];
    }
};
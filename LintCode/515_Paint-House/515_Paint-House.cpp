class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        int num_house = costs.size();
        if (num_house == 0) return 0;

        //dp[i][j] - min cost of up to house i, choose color j
        vector<vector<int>> dp(num_house, vector<int>(3, 1000000));
        
        for (int i = 0; i < 3; ++i) {
            dp[0][i] = costs[0][i];
        }

        for (int i = 1; i < num_house; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (k != j) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                    }
                }
            }
        }
        
        return min(dp[num_house - 1][0], min(dp[num_house - 1][1], dp[num_house - 1][2])); 
    }
};
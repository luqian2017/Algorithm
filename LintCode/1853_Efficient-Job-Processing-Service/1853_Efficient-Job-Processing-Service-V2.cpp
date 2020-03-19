class Solution {
public:
    /**
     * @param n: the number of tasks
     * @param weights: the weight for every task
     * @param tasks: the actual duration of every task
     * @param p: maximum runtime for Pigeon in an hour
     * @return: the maximum total weight that the Pigeon service can achieve in an hour
     */
    int maxWeight(int n, vector<int> &weights, vector<int> &tasks, int p) {
        vector<vector<int>> dp(n + 1, vector<int>(p + 1));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= p; ++j) {
                if (j < 2 * tasks[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 2 * tasks[i - 1]] + weights[i - 1]);
                }
            }
        }
        
        return dp[n][p];
    }
};
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
        vector<int> dp(p + 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = p; j >= 2 * tasks[i]; --j) {
                dp[j] = max(dp[j], dp[j - 2 * tasks[i]] + weights[i]);
            }
        }
        
        return dp[p];
    }
};
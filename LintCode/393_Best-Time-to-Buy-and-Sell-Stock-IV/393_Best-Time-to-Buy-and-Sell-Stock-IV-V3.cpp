class Solution {
public:
    /**
     * @param K: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int result = 0;
     
        if (k >= n / 2) {
            for (int i = 1; i < n; ++i)
                result += max(prices[i] - prices[i - 1], 0);
            return result;
        }
        
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j][i] = dp[j - 1][i]; //initial value is no transaction on day j
                for (int x = 0; x < j; ++x) {
                    dp[j][i] = max(dp[j][i], dp[x][i - 1] + prices[j] - prices[x]);
                }
            }
            result = max(result, dp[n - 1][i]); 
        }
        return result;
    }
};
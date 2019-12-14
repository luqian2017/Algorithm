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
            //maxTmp records the maximum vlue of dp[j][i - 1] - prices[j], for fixed i, j=1..n-1
            int maxTmp = -prices[0];  //dp[0][i - 1]-prices[0], j=0
            for (int j = 1; j < n; ++j) {
                dp[j][i] = max(dp[j - 1][i], maxTmp + prices[j]);
                maxTmp = max(maxTmp, dp[j][i - 1] - prices[j]);
            }
            result = max(result, dp[n - 1][i]); 
        }
        return result;
    }
};
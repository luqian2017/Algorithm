class Solution {
public:
    /**
     * @param n: the money of you
     * @param prices: the price of rice[i]
     * @param weight: the weight of rice[i]
     * @param amounts: the amount of rice[i] 
     * @return: the maximum weight
     */
    int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts) {
        int itemCount = prices.size();   //count of items
        vector<vector<int>> dp(2, vector<int>(n + 1, 0)); //dp[i][j] means the maximum weight of first i tems with total price <= j
        
        for (int i = 1; i <= itemCount; ++i) { // 遍历每种物品
            for (int k = 1; k <=n; ++k) {
                dp[i % 2][k] = dp[(i - 1) % 2][k];
            }

            for (int j = 0; j <= amounts[i - 1]; ++j) { // 对每种物品，遍历其个数
                for (int k = 1; k <= n; ++k) { //k->  1 .. n
                    if (k >= j * prices[i - 1]) {
                        dp[i % 2][k] = max(dp[i % 2][k], dp[(i - 1) % 2][k - j * prices[i - 1]] + j * weight[i - 1]);
                    }
                }
            }
        }

        return dp[itemCount % 2][n];
    }
};
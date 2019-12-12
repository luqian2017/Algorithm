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
    
        if (k >= n / 2) {
            int result = 0;
            for (int i = 1; i < n; ++i)
                result += max(prices[i] - prices[i - 1], 0);
            return result;
        }
        
        vector<vector<int>> global(n, vector<int>(k + 1, 0));
        vector<vector<int>> local(n, vector<int>(k + 1, 0));
        
        for (int i = 1; i < n; ++i) {
            //for (int j = 1; j <= k; ++j) { // is also OK
            for (int j = k; j >= 1; --j) {
               local[i][j] = max(global[i - 1][j - 1], local[i - 1][j]) +  prices[i] - prices[i - 1];
               //local[j] = max(global[j - 1], local[j]) + prices[i] - prices[i - 1];
               global[i][j] = max(global[i - 1][j], local[i][j]);
               //global[j] = max(global[j], local[j]);
            }
        }
        return global[n - 1][k];
    }
};
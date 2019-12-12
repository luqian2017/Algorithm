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
            for (int i = 1; i < n; ++i) {
                if (prices[i] - prices[i - 1] > 0)   
                    result += prices[i] - prices[i - 1];
            }
        
            return result;
        }
        
        vector<int> global(k + 1);
        vector<int> local(k + 1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = k; j >= 1; --j) {
               local[j] = max(global[j - 1], local[j]) + prices[i] - prices[i - 1];;
               global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }
};
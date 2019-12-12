class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int result = 0;
        for (int i = 1; i < n; ++i)
            result += max(prices[i] - prices[i - 1], 0);
        return result;
    }
};
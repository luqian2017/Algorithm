class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        
        int len = prices.size();
        int minV = INT_MAX;
        int result = 0;
        for (int i = 0; i < len; ++i) {
            if (prices[i] < minV) {
                minV = prices[i];
            }
            
            if ((prices[i] - minV) > result) {
                result = prices[i] - minV;
            }
        }
        
        return result;
    }
};
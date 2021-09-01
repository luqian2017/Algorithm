class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int ret = 0;
        int min_so_far = prices[0];
        for (int i = 1; i < n; ++i) {
            ret = max(ret, prices[i] - min_so_far);
            if (prices[i] <= min_so_far) min_so_far = prices[i];
        }
        return ret;
    }
};
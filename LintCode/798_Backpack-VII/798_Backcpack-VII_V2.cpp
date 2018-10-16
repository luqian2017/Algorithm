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
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= itemCount; ++i) { // i->item[i]
            for (int j = 1; j <= amounts[i - 1]; ++j) { //j-> amount[0]..amount[i-1]
                for (int k = n; k >= prices[i - 1]; --k) { //k->  1 .. n
                    dp[k] = max(dp[k], dp[k - prices[i - 1]] + weight[i - 1]);
                }
            }
        }

        return dp[n];
    }
};
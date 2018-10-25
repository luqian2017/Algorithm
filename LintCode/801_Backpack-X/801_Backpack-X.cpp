class Solution {
public:
    /**
     * @param n: the money you have
     * @return: the minimum money you have to give
     */
    int backPackX(int n) {
        
        vector<int> dp(n + 1, 0); 
        //dp[x] means the maximum amount (that is less than x) used to buy the mechandises
        vector<int> prices = {150, 250, 350};
        
        for (int i = 0; i < 3; ++i) {
            for (int j = prices[i]; j <= n; ++j) {
                dp[j] = max(dp[j], dp[j - prices[i]] + prices[i]);        
            }
        }
        
        return n - dp[n];
    }
};
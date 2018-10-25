class Solution {
public:
    /**
     * @param n: Your money
     * @param prices: Cost of each university application
     * @param probability: Probability of getting the University's offer
     * @return: the  highest probability
     */
    double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
        vector<double> dp(n + 1, 1.0);
        //dp[x] is the min probability that no one offer is received when money x are used.
        int count = prices.size();
        
        for (int i = 0; i < count; ++i) {
            //for (int j = prices[i]; j <= n; ++j) {
           for (int j = n; j >= prices[i]; --j) {
                dp[j] = min(dp[j], dp[j - prices[i]] * (1.0 - probability[i]));
            }
        }
        
        return 1 - dp[n];
    }
};
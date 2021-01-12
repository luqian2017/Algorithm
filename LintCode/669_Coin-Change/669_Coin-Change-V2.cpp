class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        if (n == 0 || amount == 0) return 0;
        vector<int> dp(amount + 1, INT_MAX / 3);
   
        dp[0] = 0;
     //   for (int i = 1; i <= n; i++) 
     //       dp[coins[i - 1]] = 1;
        
        for (int i = 1; i <= n; i++) {

            for (int j = coins[i - 1]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
        return (dp[amount] == INT_MAX / 3) ? -1 : dp[amount];
    }
};
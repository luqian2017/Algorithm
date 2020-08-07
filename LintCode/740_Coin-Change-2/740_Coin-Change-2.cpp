class Solution {
public:
    /**
     * @param amount: a total amount of money amount
     * @param coins: the denomination of each coin
     * @return: the number of combinations that make up the amount
     */
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        //dp[i][j] the # of combinations that first i group coins make up the amount j
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= amount / coins[0]; ++i) {
            dp[1][i * coins[0]] = 1;
        }
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                //dp[i][j] += dp[i - 1][j]; //we do not pick any coin in group i
                for (int k = 0; k <= amount / coins[i - 1]; ++k) {
                    if (j >= k * coins[i - 1]) {
                        dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
                    }
                }
            }
        }
        
        return dp[n][amount];
    }
};
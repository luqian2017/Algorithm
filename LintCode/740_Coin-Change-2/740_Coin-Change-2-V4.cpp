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
        vector<vector<int>> dp(2, vector<int>(amount + 1, 0));
        
        for (int i = 0; i <= 1; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= amount; ++j) {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if (j >= coins[i - 1]) dp[i % 2][j] += dp[i % 2][j - coins[i - 1]];
            }
        }
        
        return dp[n % 2][amount];
    }
};
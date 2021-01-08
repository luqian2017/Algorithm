class Solution {
public:
    /**
     * @param amount: a total amount of money amount
     * @param coins: the denomination of each coin
     * @return: the number of combinations that make up the amount
     */
    int change(int amount, vector<int>& coins) 
    {
        if(amount == 0) return 1;
        vector<int> dp(amount + 1, 0); //dp[i] 
        dp[0] = 1;
        for(int i: coins)
            for(int j = i; j <= amount; j++)
                dp[j] += dp[j - i];
        return dp[amount];
    }
};
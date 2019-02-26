class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int len = values.size();
        if (len < 3) return true;
        int sum1 = values[len - 1];
        int sum2 = values[len - 1] + values[len - 2];

        vector<int> dp(len, 0);
        dp[len - 1] = values[len - 1];
        dp[len - 2] = values[len - 1] + values[len - 2];
        
        for (int i = len - 3; i >= 0; --i) {
            dp[i] = max(sum2 - dp[i + 1] + values[i],
                        sum1 - dp[i + 2] + values[i] + values[i + 1]);
            sum1 = sum2;
            sum2 += values[i];
        }
        
        return sum2 - dp[0] < dp[0];
    }
};
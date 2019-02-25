class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int len = values.size();
        if (len < 3) return true;
        vector<int> sums(len, 0);
        sums[len - 1] = values[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            sums[i] = sums[i + 1] + values[i];
        }
        
        vector<int> dp(len, 0);
        dp[len - 1] = values[len - 1];
        dp[len - 2] = values[len - 1] + values[len - 2];
        
        for (int i = len - 3; i >= 0; --i) {
            dp[i] = max(sums[i + 1] - dp[i + 1] + values[i],
                        sums[i + 2] - dp[i + 2] + values[i] + values[i + 1]);
        }
        
        return sums[0] - dp[0] < dp[0];
    }
};
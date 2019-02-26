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

        int dp2 = sum2;
        int dp1 = sum1;
        
        for (int i = len - 3; i >= 0; --i) {
         
            int dp = max(sum2 - dp2 + values[i],
                      sum1 - dp1 + values[i] + values[i + 1]);
            dp1 = dp2;
            dp2 = dp;
            sum1 = sum2;
            sum2 += values[i];
        }
        
        return sum2 - dp2 < dp2;
    }
};
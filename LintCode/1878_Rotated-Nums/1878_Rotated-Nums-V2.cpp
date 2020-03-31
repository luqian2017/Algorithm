class Solution {
public:
    /**
     * @param n: length of good nums
     * @return: The num of good nums of length n
     */
    long long RotatedNums(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 5;
        if (n == 2) return 6;
        
        vector<long long> dp(n + 1);
        dp[1] = 5;
        dp[2] = 6;
        for (int i = 3; i <= n; ++i) {
            // i is odd
            if (i & 0x1) {
                dp[i] = dp[i - 1] * 5;
            } else {
                dp[i] = dp[i - 1] + dp[i - 2] * 2;
            }
        }
        
        return dp[n];
    }
};
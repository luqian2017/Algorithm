class Solution {
public:
    /**
     * @param n: the number of sectors
     * @param m: the number of colors
     * @return: The total number of plans.
     */
    int getCount(int n, int m) {
        //dp[i] is the total # of plans with a circle with i sectors
        vector<int> dp(n + 1, 0);
        dp[1] = m;
        dp[2] = (long) dp[1] * (m - 1) % 1000000007;
        dp[3] = (long) dp[2] * (m - 2) % 1000000007;
        
        for (int i = 4; i <= n; ++i) {
            //if the first sector and the last sector are same color
            dp[i] = (long) dp[i - 2] * (m - 1) % 1000000007;

            //if the first sector and the last sector are not same color
            dp[i] += (long) dp[i - 1] * (m - 2) % 1000000007;
            dp[i] %= 1000000007;
        }
        
        return dp[n];
    }
};
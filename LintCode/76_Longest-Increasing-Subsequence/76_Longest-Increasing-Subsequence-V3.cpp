class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n);
        int gMaxLen = 1;
        
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    gMaxLen = max(gMaxLen, dp[i]);
                }
            }
        }
        
        return gMaxLen;
    }
};
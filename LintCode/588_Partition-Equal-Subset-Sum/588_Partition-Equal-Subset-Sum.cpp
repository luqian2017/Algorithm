class Solution {
public:
    /**
     * @param nums: a non-empty array only positive integers
     * @return: true if can partition or false
     */
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return false;
        
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        if (sum & 0x1) return false;
        sum /= 2;
        
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] |= dp[j - nums[i]];
            }
        }
        
        return dp[sum];
    }
};
class Solution {
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums 
     */
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        
        vector<int> dp(sum / 2 + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = sum / 2; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        
        for (int i = dp[sum / 2]; i >= 0; i--) {
            if (dp[i] > 0) return (sum - 2 * dp[i]);
        }
        
    }
};
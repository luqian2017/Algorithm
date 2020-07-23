class Solution {
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums 
     */
    int findMin(vector<int> &nums) {
        int n = nums.size();
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        
        vector<int> dp(sum / 2 + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = sum / 2; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        
        for (int i = sum / 2; i >= 0; i--) {
            if (dp[i]) return (sum - 2 * i);
        }
    }
};
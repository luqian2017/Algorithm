class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, 0);  //dp[i] is the number of possible fill i
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        
        return dp[target];
    }
};
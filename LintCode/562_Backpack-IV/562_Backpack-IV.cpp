class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1 , 0); //dp[x] shows the max ways that can fill size x knapsack
        
        dp[0] = 1;        
        for (int i = 0; i < n; ++i) {
            
            for (int j = nums[i]; j <= target; ++j) {

                dp[j] += dp[j - nums[i]];  //old dp[j] is the # of ways to fill j that do have item i,
                                           //dp[j - nums[i]] is the # of ways to fill j- nums[i] that do not have item i

            }
        }
        
        return dp[target];
    }
};
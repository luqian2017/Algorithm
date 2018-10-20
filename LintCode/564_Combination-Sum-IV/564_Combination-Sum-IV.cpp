class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, 0);  //dp[i] is the number of possible combinations that add up to i
        
        dp[0] = 1;
        
        for (int j = 0; j <= target; ++j) {
            for (int i = 0; i < n; ++i) {
                if (j >= nums[i])
                    dp[j] += dp[j - nums[i]];    
              //  cout<<"i="<<i<<" j="<<j<<" dp="<<dp[j]<<endl;
            }
        }
        
        return dp[target];
    }
};
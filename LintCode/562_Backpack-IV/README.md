Typical complete knapsack problem.
Note that we need to use 
    dp[j] += dp[j - nums[i]]

Here old dp[j] is the # of ways to fill j that do have item i,
dp[j - nums[i]] is the # of ways to fill j- nums[i] that do not have item i.

Note： 
The following code is incorrect!
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        int n = nums.size();
        int count = 0;
        vector<int> dp(target + 1 , 0); //dp[x] shows the max volumes that the size x knapsack can hold. 
        
        for (int i = 0; i < n; ++i) {
            for (int j = nums[i]; j <= target; ++j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
   //             cout<<"i = "<<i<<" j = "<<j<<" "<<dp[j]<<endl;
                if (dp[j] == target) count++;
            }
        }
        
        return count;
    }
};

If we use the input
[2,2,3]
7
The debug information is below:
i = 0 j = 2 2
i = 0 j = 3 2
i = 0 j = 4 4
i = 0 j = 5 4
i = 0 j = 6 6
i = 0 j = 7 6
i = 1 j = 2 2
i = 1 j = 3 2
i = 1 j = 4 4
i = 1 j = 5 4
i = 1 j = 6 6
i = 1 j = 7 6
i = 2 j = 3 3
i = 2 j = 4 4
i = 2 j = 5 5
i = 2 j = 6 6
i = 2 j = 7 7
Output
1
Expected
3

We can see that, in the loop i, j, dp only reaches 7 once. It is because dp[7] actually includes all the optimical cases, but the count only increment once.
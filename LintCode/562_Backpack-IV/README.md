Typical complete knapsack problem.
Note that we need to use 
    dp[j] += dp[j - nums[i]]

Here old dp[j] is the # of ways to fill j that do have item i,
dp[j - nums[i]] is the # of ways to fill j- nums[i] that do not have item i.
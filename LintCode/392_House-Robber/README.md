392. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example
Example 1:

Input: [3, 8, 4]
Output: 8
Explanation: Just rob the second house.
Example 2:

Input: [5, 2, 1, 3]
Output: 8
Explanation: Rob the first and the last house.
Challenge
O(n) time and O(1) memory.

解法1：经典前缀型DP。dp[i]表示rob到house i的时候累计所得到的最大值。
dp[i] = dp[i - 2] + A[i] > dp[i - 1] ? dp[i - 2] + A[i] : dp[i - 1]

2刷
dp[i] = max(dp[i - 2] + A[i - 1], dp[i - 1]);
顺便说一下，为什么max里面是dp[i-2]+A[i-1]而肯定不是dp[i-3]+A[i-2]呢？因为这里面dp[]肯定是一个单调非递增的数组，dp[i-2]肯定比dp[i-3]大。


解法2：解法1加上滚动数组优化。空间O(1)。

解法3：坐标型DP，多加一个状态表示rob the house or not
        dp[i][0] - maximum value at house i if does not rob the house i 
        dp[i][1] - maximum value at house i if rob the house i
注意： 如果rib house i，dp[i][1]应为dp[i-2][1]和dp[i-2][0]的最大值。这样的话，dp[i][1]的值可能比下面2种选项小些，但是没关系，最优解要么在dp[i][1]中，要么在dp[i][0]中，而dp[i][0]的值是能保证最优的。
这里其实也可以取dp[i-2][1]和dp[i-1][0]的最大值，因为dp[i-1][0]肯定>=dp[i-2][1]。也可以直接取dp[i-1][0]，更简单。
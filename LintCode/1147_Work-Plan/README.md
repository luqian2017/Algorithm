1147. Work Plan

Xiaomei is the manager in charge of the team and needs to make the work plans for the team to help the team generate the most value. Every week, the team will have alternative tasks, one is a simple task, and the other is a complex task. In week i, the value of the team’s completion of simple tasks is low_ilow
​i
​​ , and the value of completion of complex tasks is high_ihigh
​i
​​ . Due to the technical difficulty of the complex task itself, if the team chooses to perform the complex task in week i, they need to concentrate on preparation without doing any task in week i-1. If the team choose to perform a simple task in week i, there is no need to make any preparations in advance. Now that Xiaomei's team has received a list of expected tasks for the next n weeks, please help Xiaomei determine the weekly work schedule that help the team generate the most value.

Example
Example 1:

Input:low=[4,2,3,7],hard=[3,5,6,9]
output:17
Explanation:
Pick simple task in the first week, value = 4
Prepare for the second week and pick complex task in the third week, value = 4 + 6 = 10
Pick a simple task in the fourth week, value = 10 + 7 = 17
Example 2:

Input:low=[1,3,5,9],high=[3,5,7,9]
Output:19
Notice
1 \leq |low|,|high| \leq 100001≤∣low∣,∣high∣≤10000
1 \leq low[i],high[i] \leq 100001≤low[i],high[i]≤10000


解法1：前缀和DP
dp[i] the max value upto the ith week
转移方程为：dp[i] = max(dp[i - 1] + low[i], dp[i - 2] + high[i])
当第i周从事low工作时，第i-1周可能是high或low，dp[i-1]包括了这2种可能。为什么不用考虑dp[i-2]呢？因为第i-2周从事high或low的情况都已经考虑在dp[i-1]周。
当第i周从事high工作时，第i-1周只可能休息，所以前i-1周的工作量和前i-2周的工作量一样，只需看dp[i-1]即可。

解法2：坐标型DP
dp[i][j]: the max value upto the ith week, and does the work j - 1:high, 0:low
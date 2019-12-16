91. Minimum Adjustment Cost
Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.

If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]|

Example
Example 1:
Input: [1,4,2,3], target=1
Output: 2

Example 2:
Input: [3,5,4,7], target=2
Output: 1

Notice
You can assume each number in the array is a positive integer and not greater than 100.

解法1：DP
思路：dp[i][j]为前i个元素中最后一个元素以高度j(1<=j<=100)结束的最优值，则第i-1个元素应该是在j-target到j+target中取，所以
dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - A[i - 1])); //k=[j-target, j+target]
注意，dp[i][j]取决于dp[i - 1][k] + abs(j - A[i - 1]), k=[j-target, j+target]中最小的那个。第i-1个元素取高度k，第i个元素取高度j，所以要加上abs(j-A[i-1])。
————————————————
版权声明：本文为CSDN博主「纸上得来终觉浅 绝知此事要躬行」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/roufoo/article/details/103562385
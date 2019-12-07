
512. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example
Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as AB (1 2) or L (12).
Example 2:

Input: "10"
Output: 1
Notice
我们不能解码空串，因此若消息为空，你应该返回0。

解法1：DP
每次有两步：
第一步, 若 s[i] 表示的数字在 1~9 范围内, dp[i] += dp[i-1]
第二步, 若s[i-1]和s[i]连起来的数字在 10~26 范围内, dp[i] += dp[i-2] (注意，若i==1, 则dp[i] += 1)
注意stoi()函数。

1834. Grouping Options

There are nn people in a row. They must all be divided into mm contiguous groups from left to right. If each group must be at least as large as the group to its left, determine how many distinct ways groups can be formed. For a group to be distinct, it must differ in size for at least one group when sorted ascending. For example, [1, 1, 1, 3] is distinct from [1, 1, 1, 2] but not from [1, 3, 1, 1].

Example
Input:
8
4
Output: 5
Explanation: [1, 1, 1, 5], [1, 1, 2, 4], [1, 1, 3, 3], [1, 2, 2, 3], [2, 2, 2, 2]
Notice
1 \leq n,m \leq 2001≤n,m≤200


解法1：
这个思路其实不太好想。参考的网上的答案。
dp[i][j] 表示前i个人分成j组的分法。
那么dp[i][i], i=1..n肯定是1。
对于dp[i][j]而言，我们可以把这j个组每个组分一个，那么剩下i-j个人，这i-j个人可以全部分配到最后1个组(对应dp[i-j][1])，也可以全部分配到最后2个组(对应dp[i-j][2])，...，也可以全部分配到全部的j个组(对应dp[i-j][j])。所以要用再用一个循环把这些方案都加起来就是dp[i][j]。
注意：
1) for i的循环可以从1开始，也可以从2开始。但从1开始没有必要，因为j<i，那么j==0。
2) for j的循环可以是j<=i，因为我们知道dp[i][i]==1，所以用j<i就可以了。
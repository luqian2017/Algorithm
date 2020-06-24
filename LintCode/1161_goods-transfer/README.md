1161. goods transfer
中文English
There are n backpacks, each of which can carry a[i] goods, and the maximum capacity of each backpack is b[i]. If it takes 1 second to transfer one piece of goods, how many backpacks can hold all the goods at least, and how much time does it take to transfer?

Example
Example

Input
4
[3, 3, 4, 3]
[4, 7, 6, 5]
Output 2 6 
Explanation:
We can put the goods in the first bag all moved to the second backpack, take time for 3 seconds, at this point the second of the residual capacity of backpack is 1, and then put the goods in the fourth incubator transfer a into the second bag, transfer the last two to the third in the backpack. Take time for 3 seconds, so the minimum heat preservation box number is 2, at least spend time for 6 seconds.
Notice
1<=n<=100
1<=ai<=1000
1<=bi<=1000
ai<=bi

解法1：用DP。
from jiuzhang:
dp[i][j]表示前i个箱子，挑出若干个箱子后构成j的容量时的最优挑选方案<x,y>是什么。其中，x表示最优方案里的箱子总数最少是多少(即若干个箱子是多少个)，y表示最优方案里在箱子总数最小的情况下这些箱子里的食物之和最大是多少。
x越小越优，
x相等y越大越好。

考虑第i个箱子要不要被选中，产生2种决策：
1) 不选中，相当于要在前i-1个箱子里选出j的体积，转移到<f[i-1][j].x, f[i][j - 1].y>
2) 选中，相当于要在前i-1个箱子里选出j-b[i]的体积，转移到<f[i-1][j-b[i]].x + 1, f[i - 1][j - b[i]].y + a[i]>

比较两者得到最优的二元组，赋值给f[i][j]即可。

时间复杂度
设n=箱子个数(大约100)，m=箱子体积之和(大约10000)。O(n*m)=大约10^6.

我的想法：
这题非常难，我是照抄的网上的答案然后学习。

首先这题求2个东西，
1）how many backpacks can hold all the goods at least, 
2）how much time does it take to transfer?
1)是求最少包数；2)是在1)的基础上最少时间，即最少转移的食物piece数。

首先1)可以用贪婪法来解决。比如说a = {3,3,4,3}, b = {4,7,6,5}，因为sum_a = 13，而b里面找尽量大的元素，使得其和加起来大于sum_a即可。
但2)不能用贪婪法，比如说1)的最少包数决定后，比如说X个包，然后2)是不是就找最大的X个包就可以了呢？答案是否定的。比如说a={4,1}, b={5,6}。可知用sum_a=5，可知用1个包就可以了，但取6是错的，因为要转移的食物数为4。实际上应该取5，此时要转移的食物数为1。

最后是只能用DP。注意要同时保存2个数组。dp和weight。
dp[i][j]表示前i个箱子，挑出最少的箱子个数后构成j的容量时，那个最少的箱子总数。注意dp[i][j]可以优化成1维数组dp[j]。
weight[j]表示上面的最优方案里这些箱子里的食物之和最大是多少。

转移方程怎么写呢？

                int res = max(j - b[i], 0);
                dp[j] = min(dp[j],dp[max(0, j-b[i])]+1)
即取b[i]后，如果dp个数更少，则更新dp[j]和weight[j]。如果dp个数一样，则weight[j]取大的情况。
注意：
1) 转移方程应以b[]为主，因为b[i]不能拆分，而不能以a[]为主，因为a[i]可以拆分。
2) dp越小越优，当dp相等时weight越大越优。
3) 一个难点是j循环内j<=b[i]时的处理。注意这里跟01背包问题不一样，01背包问题的j的下限就是A[i]。这里还要处理0<j<=b[j]的情况呢？我的理解是01背包问题里面，A[i]是物品的大小，k<A[i]时，A[i]只可能不取，那么dp值就是不取A[i]的情况，不变即可。
见https://blog.csdn.net/roufoo/article/details/102996040
这里b[j]是包的大小，即使j<=b[i]，还是可以取这个包。




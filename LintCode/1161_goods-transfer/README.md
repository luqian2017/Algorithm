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
dp[i][j]表示前i个箱子，挑出若干个箱子后构成j的容量时的最优挑选方案<x,y>是什么。其中，x表示最优方案里的箱子总数最少是多少(即若干个箱子是多少个)，y表示最优方案里在箱子总数最小的情况下这些箱子里的食物之和最大是多少。
x越小越优，
x相等y越大越好。

考虑第i个箱子要不要被选中，产生2种决策：
1) 不选中，相当于要在前i-1个箱子里选出j的体积，转移到<f[i-1][j].x, f[i][j - 1].y>
2) 选中，相当于要在前i-1个箱子里选出j-b[i]的体积，转移到<f[i-1][j-b[i]].x + 1, f[i - 1][j - b[i]].y + a[i]>

比较两者得到最优的二元组，赋值给f[i][j]即可。

时间复杂度
设n=箱子个数(大约100)，m=箱子体积之和(大约10000)。O(n*m)=大约10^6.




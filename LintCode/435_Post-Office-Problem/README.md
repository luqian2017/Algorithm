435. Post Office Problem
中文English
There are n houses on a line. Given an array A and A[i] represents the position of i-th house. Now you need to pick k position to build k post offices.

What is the minimum sum distance from these n houses to the nearest post office?

Example
Example 1:

Input: A = [1, 2, 3, 4, 5], k = 2
Output: 3
Explanation: Build post offices on position 2 and 4.
Example 2:

Input: A = [1, 2], k = 1
Output: 1
Explanation: Build post office on position 1 or 2.
Challenge
O(n^2) time

Notice
All positions are integers.

解法1：DP。

该题就是一维的K-Median问题，其中最优解必须在输入的N个离散点中选择。
解法1：DP。思路见网上。

这个DP解法有一个很重要的思想：
(为简便起见，我们假定所有数组index都从1开始) 在第1…i个房子中建立j个邮局的最短距离，是在1…z个房子中建立j-1个邮局的最短距离，与在z+1到第i个房子建立1个邮局的最短距离的和，其中z可以在j-1到i中间选择，然后遍历所有z，得到的最小值即为最优解。
有个难以理解的点是：为什么加了

用dp[i][j] 表示前 j 栋房子建立 i 个邮局时的最优解. 对于这个状态我们需要决策的就是在dp[i-1][j-1]的基础上，再在[1…j]之间加一个新邮局。这个新邮局的位置可以取在[1…j]的某个位置上。
最优的dp[i][j]可理解为在dp[i-1][] j 之前有多少栋房子共用第 i 个邮局, 故有:
f[i][j] = min{f[i - 1][j - x] + sumDis[j - x][j - 1]}
其中 sumDis[l][r] 表示[l, r] 的房子之间建一个邮局, 这些房子与该邮局的最短距离
(注意f[i][j]中的j表示的第j栋房子从1计数, sumDis从0计数。下面的程序里面的i,j互换，为了编程的方便)。

打个比方。A={1,2,3,4,9,10,11,12},k=2。当算到A={1,2,3,4,9}, k=1时，dp[1][5]最优解是在pos=3(median)处建这个邮局。假设我们现在处理dp[2][6] (A[6]=10)。第2个邮局的位置不是只在{10,11,12}处选，那样的话我们选择11，而前面的9也会被吸引过来，那dp[5][1]就不对了。第2个邮局的位置应该是A[1…6]处选，即从最开始到A[6]。而dp[2][6]的最优解就是从dp[1][1] + sumDis(2…6), dp[1][2]+sumDis(3…6), dp[1][3]+sumDis(4…6), dp[1][4]+sumDis(5…6), dp[1][5] + sumDis(6…6)中选一个最小值。这样，如果我们选了11为第2个邮局地址，把9吸引过来了也没关系，因为我们此时是基于dp[1][4]，而不是dp[1][5]来决定dp[2][6]。

注意：
1）3重循环中，for (int i = 1; i <= k; ++i) 先做，因为j循环取决于i。也可以理解为先决定第1个邮局的选址，再决定第2个邮局的选择，一直到第k个邮局的选址。注意，第k个邮局选址决定好之后，最优解里面的第1…k-1个邮局的选择不一定是之前的k-1个邮局的最优选址。
2）dp的初始值不能是INT_MAX，因为还要加sumDis，可能溢出。所以选0x3f3f3f3f比较好。

1439. Consecutive Numbers Sum

Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

Example
Example 1:

Input: 5
Output: 2
Explanation: 5 = 5 = 2 + 3
Example 2:

Input: 9
Output: 3
Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
Example 3:

Input: 15
Output: 4
Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
Notice
1 <= N <= 10 ^ 9.

解法1：

这是一道数学题。假设某数a满足a + a+1 + a+2 + ... + a+k-1 = N，即从a开始连续k个数的和为N。我们的任务就是要找出这些a出来。因为上面的式子可以得出 k * (2 * a + k - 1) = 2 * N，所以 k * k <= 2 * N，即 k <= sqrt(2 * N)。所以我们遍历k=1 到 sqrt(2*N)，看 a = (2 * N - k * k + k) / 2k是不是为整数就可以了。

注意，为什么for循环里面k<=thresh而不是<呢？因为k可能为1，如果N=1的时候，thresh=1，所以如果k<1的话就退出来了，结果返回0，但正确结果为1。
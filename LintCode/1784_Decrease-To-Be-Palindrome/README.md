1784. Decrease To Be Palindrome

Given a string s with a-z. We want to change s into a palindrome with following operations:

1. change 'z' to 'y';
2. change 'y' to 'x';
3. change 'x' to 'w';
................
24. change 'c' to 'b';
25. change 'b' to 'a';
Returns the number of operations needed to change s to a palindrome at least.

Example
Example 1:

Input: "abc"
Output: 2
Explanation: 
  1. Change 'c' to 'b': "abb"
  2. Change the last 'b' to 'a': "aba"
Example 2:

Input: "abcd"
Output: 4

解法1：暴力法。时间复杂度O(n^3)。

解法2：O(n^2)。即算回文的同时count++。
注意用这种方法的时候要注意从i:i开始和i:i+1开始是不一样的，前者算的是类似(3:3, 2:4, 1:5)，后者算的是(3:4, 2:5, 1:6)，互不重合。

解法3：DP。时间复杂度O(n^2)。
dp[i][j]表示str(i…j)是否为回文串。
这里要非常注意i和j的递增方向。因为dp[i][j]取决于dp[i+1][j-1]是否为回文，即i应该递减，j应该递增。所以i是n-1->0,j是i->n-1。
另外，为什么dp[i+1][j-1]不会出现越界呢？即为什么永远i+1<=n-1，j-1>=0呢？
因为首先str[i]==str[j]，这里i和j的范围都是0…n-1之间。另外j-i<=2，
如果i=n-1，因为j>=i，j一定为n-1，j-i<=2必定满足。
同样，如果j=0，因为j>=i，所以i一定为0，j-i<=2必定满足。

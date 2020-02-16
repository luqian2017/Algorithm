630. Knight Shortest Path II

Given a knight in a chessboard n * m (a binary matrix with 0 as empty and 1 as barrier). the knight initialze position is (0, 0) and he wants to reach position (n - 1, m - 1), Knight can only be from left to right. Find the shortest path to the destination position, return the length of the route. Return -1 if knight can not reached.

Example
Example 1:

Input:
[[0,0,0,0],[0,0,0,0],[0,0,0,0]]
Output:
3
Explanation:
[0,0]->[2,1]->[0,2]->[2,3]
Example 2:

Input:
[[0,1,0],[0,0,1],[0,0,0]]
Output:
-1
Clarification
If the knight is at (x, y), he can get to the following positions in one step:

(x + 1, y + 2)
(x - 1, y + 2)
(x + 2, y + 1)
(x - 2, y + 1)

解法1: BFS

解法2: DP
注意此处行方向可上可下，而列方向只能往右，所以先列循环在外，再行循环在内，即对每列，行要全部遍历一遍。
也就是说，执行到列j时，需要保证所有的行0..m都遍历过了，才能保证dp[i][j]能够在dp[0..n][j-1]的可行解中找到最大值。
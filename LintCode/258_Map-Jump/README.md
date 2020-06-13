258. Map Jump

Given a map of n×n, each cell has a height. Each time you can only move to an adjacent cell, and the height difference between the two cells is required to not exceed target. You cannot get out of the map. Find the the smallest target that satisfies from the upper left corner (0, 0) to the lower right corner (n-1, n-1).

Example
Example 1:

Input:[[1,5],[6,2]],
Output:4,
Explanation:
There are 2 ways:
1. 1 -> 5 -> 2 The target in this way is 4.
2. 1 -> 6 -> 2 The target in this way is 5.
So the answer is 4.
Example 2:

Input:[[1,5,9],[3,4,7],[6,8,1]],
Output:6
Notice
n≤100
0≤arr[i][j]≤1000



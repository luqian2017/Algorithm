1676. Skip Stones
cat-only-icon
CAT Only
中文English
There are n stones between the starting point and the end point. The distance between the starting point and the ith (i starts from 0) stone is d[i]. And the distance between the starting point and end point is target. From the starting point, we can only jump to the adjacent stone until the end point.

Now you can remove at most m stones. Return the maximum value of the shortest jump distance in your jumping from start point to end point.

Example
Example 1:

Input: n = 5, m = 2, target = 25, d = [2,11,14,17,21]
Output: 4
Explanation: Remove the first stone and the third stone. Then the jump path is :
  1. 0 -> 11  11
  2. 11 -> 17 6
  3. 17 -> 21 4
  4. 21 -> 25 4 
Example 2:

Input: n = 0, m = 0, target = 10, d = []
Output: 10
Explanation: No stones and no need to remove any stone. Just jump from starting point (0) to end point (10).
Notice
0 \leq m \leq n \leq 50,0000≤m≤n≤50,000
1 \leq target \leq 1,000,000,0001≤target≤1,000,000,000
These stones are given in order from small to large distances from the starting point, and no two stones will appear in the same place.

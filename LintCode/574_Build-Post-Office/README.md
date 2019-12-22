574. Build Post Office
中文English
Given a 2D grid, each cell is either an house 1 or empty 0 (the number zero, one), find the place to build a post office, the distance that post office to all the house sum is smallest. Return the smallest distance. Return -1 if it is not possible.

Example
Example 1:

Input：[[0,1,0,0],[1,0,1,1],[0,1,0,0]]
Output： 6
Explanation：
Placing a post office at (1,1), the distance that post office to all the house sum is smallest.
Example 2:

Input：[[0,1,0],[1,0,1],[0,1,0]]
Output： 4
Explanation：
Placing a post office at (1,1), the distance that post office to all the house sum is smallest.
Notice
You can pass through house and empty.
You only build post office on an empty.
The distance between house and the post office is Manhattan distance


解法1：
我的方法是先预处理，得到left2RightCount, right2LeftCount, left2RightDist, right2LeftDist这4个二维数组。注意我们不需要up2down和down2up这样的数组，因为根据Manhattan距离，先左后下和先下后左是一样的。
然后我们遍历整个grid，对每个0元素，固定列，遍历行(0..nRow-1)，对每行的left2RightDist和righ2LeftDist加起来，然后再根据每行到i的距离乘以left2RightCount和right2LeftCount的和(注意如果[k][j]是1的话，和要减1)。
该法还是稍慢，因为复杂度是O(m^2*n)。
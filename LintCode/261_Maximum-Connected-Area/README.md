261. Maximum Connected Area
Description

There is a two-dimensional array, only consists of 00 and 11.
You can change a 00 to 11 at most once, please calculate the maximum area of connected 1s1s.
If two 1s1s are adjcent up to down or left to right, they are regrarded connected.

the two-dimensional array has nn rows and mm columns, 1 \le n, m \le 5001≤n,m≤500.

Have you met this question in a real interview?  
Clarification
In example, change any 00 to 11, you can get a connection with an area 33.

Example
Input：
[[0,1]
,[1,0]]
Output：
3

解法1：union-find
思路是将2维降1维。然后先按岛屿最大面积的思路把所有连通块都求出来，每个连通块的root存储其面积。
然后再把matrix里面的所有0节点遍历一遍，上下左右4个方向把所有连通块的面积加起来，再加1。然后求所有的0节点所得到的最大值。
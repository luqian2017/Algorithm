778. Pacific Atlantic Water Flow
中文English
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Example
Example 1:

Input:
matrix = 
[[1,2,2,3,5],
[3,2,3,4,4],
[2,4,5,3,1],
[6,7,1,4,5],
[5,1,1,2,4]]
Output:
[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation:
Pacific ~ ~ ~ ~ ~
      ~ 1 2 2 3 5 *
      ~ 3 2 3 4 4 *
      ~ 2 4 5 3 1 *
      ~ 6 7 1 4 5 *
      ~ 5 1 1 2 4 *
        * * * * * Atlantic
Example 2:

Input:
matrix =
[[1,2],
[4,3]]
Output:
[[0,1],[1,0],[1,1]]
Notice
1.The order of returned grid coordinates does not matter.
2.Both m and n are less than 150.


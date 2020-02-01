161. Rotate Image

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Example
Example 1：

Input:[[1,2],[3,4]]
Output:[[3,1],[4,2]]
Example 2:

Input:[[1,2,3],[4,5,6],[7,8,9]]
Output:[[7,4,1],[8,5,2],[9,6,3]]
Challenge
Do it in-place.

解法1：
先按主对角线反转，然后列按中轴线反转。
比如说
input = [[1,2,3], [4,5,6],[7,8,9]]，先反转成[[]1,4,7],[2,5,8],[3,6,9]]，再反转成[[7,4,1],[8,5,2],[9,6,3]]。
注意：
1) 按主对角线反转的循环是
        for (int i = 1; i < rowSize; ++i) {
            for (int j = 0; j < i; ++j) {   //注意j<i
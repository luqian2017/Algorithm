1136. High Click Induction Area
中文English
On a two-dimensional matrix, every position is a integer pixel value between 00 and 1010.
The position that is larger than pixelThresholdpixelThreshold is called high click induction position.
The area of connected high click positions which is larger than areaThresholdareaThreshold is called high click induction area.
The positions which are adjacent positions are connected.
Please count the number of high click induction area on the two-dimensional matrix.

Example
Sample

Input：
matrix = [[6,2,8],[1,3,7],[6,9,5]]
pixedThreshold = 5
areaThreshold = 1

Output：
2
Clarification
There are three parts of connected high click induction positions:

[(0, 0)]
[(0, 2), (1, 2)]
[(2, 0), (2, 1)]
Two parts of them are which area is larger than 11.

Notice
The length nn and width mm of this matrix are satisfing 1 \le n, m \le 3001≤n,m≤300.
0 \le matrix[x][y] \le 100≤matrix[x][y]≤10
0 \le pixelThreshold \le 100≤pixelThreshold≤10
0 \le areaThreshold \le n * m0≤areaThreshold≤n∗m


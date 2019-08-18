817. Range Sum Query 2D - Mutable
中文English
Given a 2D matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2). And the elements of the matrix could be changed.

You have to implement three functions:

NumMatrix(matrix) The constructor.
sumRegion(row1, col1, row2, col2) Return the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
update(row, col, val) Update the element at (row, col) to val.
Example
Example 1:

Input:
  NumMatrix(
    [[3,0,1,4,2],
     [5,6,3,2,1],
     [1,2,0,1,5],
     [4,1,0,1,7],
     [1,0,3,0,5]]
  )
  sumRegion(2,1,4,3)
  update(3,2,2)
  sumRegion(2,1,4,3)
Output:
  8
  10
Example 2:

Input:
  NumMatrix([[1]])
  sumRegion(0, 0, 0, 0)
  update(0, 0, -1)
  sumRegion(0, 0, 0, 0)
Output:
  1
  -1
Notice
The matrix is only modifiable by update.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.

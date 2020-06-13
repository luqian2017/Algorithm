260. Same Diagonal Elements

Given a n * n matrix, if each diagonal line from top left to bottom right has the same value you should return true, otherwise return false.
For example：
1，2，3
5，1，2
6，5，1
This test should return true.

But
1，2，3
2，1，5
6，5，1
This test should return false.

Example
Sample 1:
Input: [[1,2,3], [5,1,2], [6,5,1]]
Output: true
Explanation: Each slash from top left to bottom right is the same element, returning true.

Example 2:
Input: [[1,2,3], [2,1,5], [6,5,1]]
Output: false
Explanation: The second slash and the fourth slash are [2, 5]. These two slashes do not satisfy this condition, so return false.

Notice
n within the range is: [1, 500]


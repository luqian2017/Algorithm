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

解法1：
这题是判断从对角线(右上到左下)的镜像，这个映像其实不好转换。如果是判断主对角线(左上到右下)的镜像就很容易了(A[i][j]==A[j][i])即可。那怎么转换到主对角线来处理呢？只要把matrix上下翻个个就可以了，即最下面一行跟第一行互换，倒数第二行跟第二行互换，如此反复。
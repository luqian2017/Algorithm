162. Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Example
Example 1:

Input:[[1,2],[0,3]]
Output:[[0,2],[0,0]]
Example 2:

Input:[[1,2,3],[4,0,6],[7,8,9]]
Output:[[1,0,3],[0,0,0],[7,0,9]]
Challenge
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


解法1：用set。

解法2：不用额外空间的解法。
参考了网上的解法。思路比较奇妙，就是把每行或每列的有无0的信息放在行头或列头。
注意：
1) 假设仅仅做下面两个循环：

```cpp
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = (matrix[i][0] == 0 || matrix[0][j] == 0) ? 0 : matrix[i][j];
            }
        }
```

以下面input为例：
[[-4,-2147483648,6,-7,0],[-8,6,-8,-6,0],[2147483647,2,-9,-6,-10]]
如果不单独处理row0hasZero和col0hasZero，在处理第0行 (和第1行) 的时候就会把matrix[0][0] (和matrix[1][0]) 置零。第2个forfor循环处理到matrix[2][0]时发现matrix[0][0]=0，就会把matrix[2][0]设为0。但这是不对的，事实上第0列根本没有0元素。
原因是第0行和第0列本身还要承担该行或该列是否有0的信息，该信息不应该和其它行列含0信息混淆。

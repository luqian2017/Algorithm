897. Island City

Given a matrix of size n x m, the elements in the matrix are 0、1、2. 0 for the sea, 1 for the island, and 2 for the city on the island(You can assume that 2 is built on 1, ie 2 also represents the island).
If two 1 are adjacent, then these two 1 belong to the same island. Find the number of islands with at least one city.

Example
Example1

Input: 
[
[1,1,0,0,0],
[0,1,0,0,1],
[0,0,0,1,1],
[0,0,0,0,0],
[0,0,0,0,1]
]
Output: 0
Explanation:
There are 3 islands, but none of them contain cities.
Example2

Input: 
[
[1,1,0,0,0],
[0,1,0,0,1],
[0,0,2,1,2],
[0,0,0,0,0],
[0,0,0,0,2]
]
Output: 2
Explanation:
There are 3 islands, and two of them have cities.
Notice
We only consider up, down, left and right as adjacent.
n <= 100，m <= 100.
You can assume that the four sides of the matrix are surrounded by the sea.

解法1：BFS

注意 grid[curNode.first][curNode.second] = 0 要在for循环前面执行，不然for 循环里面又碰到它是1或2的时候就出错了。

解法3：Union-Find

注意，并查集算法并不需要上下左右4个方向，只需要下和右两个方向就可以了。为什么呢？因为union算法决定了连在一起的都是一个连通块，所以不需要再往左和上再搞一次了。

而BFS和DFS则必须要上下左右4个方向处理。为什么呢？我们看下面的矩阵M：

[[1,1,0,0,0],
 [0,1,0,0,1],
 [0,0,2,1,2],
 [0,0,0,0,0],
 [0,0,0,0,2]]
M[1][4]=1，此时如果只往下和右方向走就只会处理M[2][4]，而不会处理与之相连的M[2][2]和M[2][3]。

而并查集算法则会把M[1][4]和M[2][4]的祖先合成一个，到时候再处理M[2][2]和M[2][3]的时候又把其祖先合成一个，处理M[2][3]和M[2][4]的时候又把其祖先合成一个。这样，大家就都是一个连通块了。
注意，并查集并不需要把grid[][]元素改成0，而BFS/DFS可以这样做，从而省掉一个visited数组。
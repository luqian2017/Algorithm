1237. Number of Boomerangs

Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

解法1：
如果一个点有n个点跟它距离一样，那么就可以凑出n*(n-1)个Bommerangs来。
比如说如果节点1有节点2,3,4跟它距离一样，那么就有6个Boomerangs:
（1,2,3) (1,3,2)
  (1,2,4) (1,4,2)
  (1,3,4) (1,4,3)
说白了就是那n个点中任取2个的permutation n!/2! = n*(n-1)
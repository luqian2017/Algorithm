864. Equal Tree Partition

Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example
Example 1:

Input: {5,10,10,#,#,2,3}
Output: true
Explanation:
  origin:
     5
    / \
   10 10
     /  \
    2    3
  two subtrees:
     5       10
    /       /  \
   10      2    3
Example 2:

Input: {1,2,10,#,#,2,20}
Output: false
Explanation:
  origin:
     1
    / \
   2  10
     /  \
    2    20
Clarification
Binary Tree Representation

Notice
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000
You can assume that the tree is not null


解法1：DFS。判断某非根节点下面的sum为totalSum的一半就行了。
注意：
1) totalSum可能为0，所以空节点不能存0到sums数组中。
2) for循环到< sums.size() - 1就可以了，因为只需要考虑非根节点。
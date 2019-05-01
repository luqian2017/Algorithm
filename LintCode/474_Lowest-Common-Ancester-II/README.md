474. Lowest Common Ancestor II
中文English
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

The node has an extra attribute parent which point to the father of itself. The root's parent is null.

Example
Example 1:

Input:
      4
     / \
    3   7
       / \
      5   6
and 3,5
Output: 4
Explanation:LCA(3, 5) = 4

Example 2:

Input:
      4
     / \
    3   7
       / \
      5   6
and 5,6
Output: 7
Explanation:LCA(5, 6) = 7


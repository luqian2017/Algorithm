475. Binary Tree Maximum Path Sum II

Given a binary tree, find the maximum path sum from root.

The path may end at any node in the tree and contain at least one node in it.

Example
Example 1:

Input: {1,2,3}
Output: 4
Explanation:
    1
   / \
  2   3
1+3=4
Example 2:

Input: {1,-1,-1}
Output: 1
Explanation:
    1
   / \
  -1 -1

解法1：DFS。
注意：
1）当左右最大分枝返回负数时，此时用root->val即可。
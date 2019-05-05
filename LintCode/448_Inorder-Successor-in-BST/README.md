448. Inorder Successor in BST
中文English
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return null.

Example
Example 1:

Input: tree = {1,#,2}, node value = 1
Output: 2
Explanation:
  1
   \
    2
Example 2:

Input: tree = {2,1,3}, node value = 1
Output: 2
Explanation: 
    2
   / \
  1   3
Binary Tree Representation

Challenge
O(h), where h is the height of the BST.

Notice
It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)


242. Convert Binary Tree to Linked Lists by Depth
中文English
Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

Example
Example 1:

Input:
{1,2,3,4}
    1
   / \
  2   3
 /
4
Output:
[
  1->null,
  2->3->null,
  4->null
]
Example 2:

Input:
{1,#,2,3}
 1
 \
  2
 /
3
Output:
[
  1->null,
  2->null,
  3->null
]

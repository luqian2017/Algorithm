66. Binary Tree Preorder Traversal
中文English
Given a binary tree, return the preorder traversal of its nodes' values.

Example
Example 1:

Input：{1,2,3}
Output：[1,2,3]
Explanation:
   1
  / \
 2   3
it will be serialized {1,2,3}
Preorder traversal
Example 2:

Input：{1,#,2,3}
Output：[1,2,3]
Explanation:
1
 \
  2
 /
3
it will be serialized {1,#,2,3}
Preorder traversal
Challenge
Can you do it without recursion?

Notice
The first data is the root node, followed by the value of the left and right son nodes, and "#" indicates that there is no child node.
The number of nodes does not exceed 20.

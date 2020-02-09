854. Closest Leaf in a Binary Tree

Given a binary tree where every node has a unique value, and a target key k.

Find the value of the nearest leaf node to target k in the tree. If there are multiple cases, you should follow these priorities:

The leaf node is in the left subtree of the node with k;
The leaf node is in the right subtree of the node with k;
The leaf node is not in the subtree of the node with k.
Example
Example 1:

Input: {1, 3, 2}, k = 1
Output: 3
Explanation:
    1
   / \
  3   2
Example 2:

Input: {1}, k = 1
Output: 1
Clarification
A node is called a leaf if it has no children.

About binary tree representation

Notice
root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000][1,1000].
There exists a node in the given binary tree for which node.val == k.

解法1：
这题感觉并不容易。难点就在当答案不在target node的子树时，需要从该节点的父节点链上挨个找最近节点，然后接上该节点到该祖宗节点的距离。
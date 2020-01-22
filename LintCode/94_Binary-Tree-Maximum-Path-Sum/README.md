94. Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Example
Example 1:
	Input:  For the following binary tree（only one node）:
	2
	Output：2
	
Example 2:
	Input:  For the following binary tree:

      1
     / \
    2   3
		
	Output: 6

	
	
解法1：递归，即divide and conquer
思路：
1) if leftSum >= 0, rightSum >= 0, 取max(leftSum, rightSum) + root->val
2) if leftSum和rightSum只有一边>0，取其与root->val的和。  
3) if leftSum < 0, rightSum < 0, 直接返回root
4) 同时我们要考虑到左，中，右为一条路径的情况，比如说{1,2,3}，所以
        gMaxSum = max(gMaxSum, max(leftSum + rightSum + root->val, result));

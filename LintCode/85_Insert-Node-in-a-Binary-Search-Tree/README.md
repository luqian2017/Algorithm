85. Insert Node in a Binary Search Tree
中文English
Given a binary search tree and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.

Example
Example 1:
	Input:  tree = {}, node = 1
	Output:  1
	
	Explanation:
	Insert node 1 into the empty tree, so there is only one node on the tree.

Example 2:
	Input: tree = {2,1,4,3}, node = 6
	Output: {2,1,4,3,6}
	
	Explanation: 
	Like this:



	  2             2
	 / \           / \
	1   4   -->   1   4
	   /             / \ 
	  3             3   6
		
Challenge
Can you do it without recursion?

Notice
You can assume there is no duplicate values in this tree + node.


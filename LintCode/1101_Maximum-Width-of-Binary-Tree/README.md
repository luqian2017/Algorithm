1101. Maximum Width of Binary Tree
中文English
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example
Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,#,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
		
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,#,#,#,#,#,#,7).
Notice
The answer will be in the range of 32-bit signed integer.

解法2：
注意节点的值没有什么用，可以用来存序号。根节点序号为i,则其左节点序号为2*i，右节点序号为2*i+1。每次把queue中的q.back()-q.front()+1算出来与gMaxWidth比较即可。
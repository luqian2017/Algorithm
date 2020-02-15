1235. Serialize and Deserialize BST

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Example
Example 1:

Input：[2,1,3]
Output：[2,1,3]
Explanation：
     2
    / \
   1   3
Example 2:

Input：[1,#,2]
Output：[1,#,2]
Explanation：
  1
   \
    2

解法1：
serialize()用preOrder遍历，如果遇到空节点，就输出”# “，否则就输出val + " "。
deserialize()检查节点为空则输出NULL，否则递归调用deserialize()为当前节点的左节点和右节点。
注意：
1）我们以前学过光靠preOrder或postOrder或inOrder是不能决定一个Binary Tree的，这里为什么可以呢？因为这里serialize()把该Binary Tree变成了全二叉树或满二叉树。对于全二叉树或满二叉树，preOrder/postOrder/inOrder是可以决定这棵树的。
2) stringStream 很有用，自动把string按“ ”split成tokens。

解法2：
serialize()和deserialize()都是按层次遍历来处理。
注意：
1） if (!(ss >> val)) 说明ss的token已经处理完了。
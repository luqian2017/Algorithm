这题有很多解法。

解法1. 根据BST的中序遍历是非递减序列这个性质。 见.cpp
该代码的时间复杂度是O(n), 最好最坏都是。空间复杂度都是O(n)。

解法2： 
BST In-order Traversal的非递归版 
有个好处就是可以用个counter来计数。 
用 stack，从第一个点开始，走 k-1 步，就是第 k 个点了。 
时间复杂度是 O(h + k) h 是树的高度。 
下次实践。

解法3：Quick-Select。 
详见 
https://www.jiuzhang.com/solution/kth-smallest-element-in-a-bst/#tag-highlight 
下次实践。

Challenge 
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

答案是用QuickSelect方法做预处理，把每个BST节点的子树的节点个数记录下来，可以在建树的时候一起完成。下次实践一下。
利用In-Order Traversal的思路。 
引用自九章 
https://www.jiuzhang.com/solution/binary-search-tree-iterator/#tag-highlight-lang-java

这是一个非常通用的利用 stack 进行 Binary Tree Iterator 的写法。

stack 中保存一路走到当前节点的所有节点，stack.peek() 一直指向 iterator 指向的当前节点。 
因此判断有没有下一个，只需要判断 stack 是否为空 
获得下一个值，只需要返回 stack.peek() 的值，并将 stack 进行相应的变化，挪到下一个点。

挪到下一个点的算法如下：

如果当前点存在右子树，那么就是右子树中“一路向西”最左边的那个点 
如果当前点不存在右子树，则是走到当前点的路径中，第一个左拐的点

注意： 
1) 该方法的next()的平均时间复杂度是O(1)。因为不管什么样的二叉树，每个节点都只进/出栈一次。平均起来，时间复杂度就是O(1)。 
最坏时间复杂度应该是O(n)？？？
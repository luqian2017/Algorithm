这题是经典宽搜(BFS)题。有3种解法，BFS，并查集和DFS。 
解法1： BFS 
注意： 
1）遍历每个节点，若为1，则调用bfs。 
2）bfs的主要作用就是从该节点向4个方向扩展，把相连的节点设为false。这里要注意的是，把相连的节点设为false后，该节点还是要进queue，不然该方向的宽搜就断了。 
3）可以用两个数组dirX和dirY和一个for循环(0..3)来搜索4个方向。 
4）每次调用bfs的时候，该节点本身要设为false，这样就不会重复查找了。 
5) 每次调用bfs的时候，num_islands只加1，因为所有相连的节点加起来只能算一个。 
6) queue里面放coordinate的值而不是指针。 
7) queue的操作是 
queue.pop() //不返回值 
queue.push(node) //从back push 
queue.front() //返回queue最front的元素 
注意网上有的地方用queue.pop_front()和queue.push_back()。这两个函数我试了不支持，可能是C++版本不一样的原因?

解法2：并查集 union-find。下次写。

解法3：深搜DFS。 下次写。
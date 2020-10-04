930. Connected Components in List

Given a doubly linked list and an array of nodes. If the nodes are connected with each other(which means we can access any nodes through any one of them), we can consider them as one block. Find the number of blocks in the given array.

Example
Example 1:

Input：1<->2<->3<->4,[1,3,4]
Output：2
Explanation：There is no node connected with 1, and node 3 is connected with 4. So the number of blocks is 2.
Example 2:

Input：1<->2<->3<->4,[1,2,3,4]
Output：1
Explanation：All nodes  are connected.So the number of blocks is 1.
Notice
You can assume that there is no duplicate node in the given doubly linked list.

解法1：
我开始的想法是枚举nodes数组，每次往前和往后遍历链表，如果发现链表节点不在node数组中就相当于发现了一个新的component。注意在遍历链表过程中，set visited flag。需要用到list_mp和node_mp两个map。
list_mp<int, node*>保存node->val和node地址的映射，
node_mp<int, bool> 保存nodes中的节点和其是否访问过的关系。所以链表中的节点可以有3种状态：
1. 在node_mp中，状态为unvisited;
3. 在node_mp中，状态为visited;
3. 不在node_mp中;

解法2：
解法1需要往前和往后遍历链表，其实我们如果从前往后遍历链表，就不需要再往前走回头路了。
解法2的nodes_mp跟解法1的nodes_mp一样，也是保存3种状态。

解法3:
我们其实不需要visited状态。因为我们是从前往后单向遍历链表，不会走回头路。所以用set即可。

解法4：union-find，find用非递归路径压缩算法。
注意：
1) 通常father[]可以用数组表示，但这里因为我们要考虑链表的元素个数，而不是nodes[]的数组个数。而我们又不知道链表有多少个，所以最好用map，要不就要搞一个很大的数组了。
2）算count的时候，可以先把count设为nodes.size()，每次merge减一。
也可以不这么做，在最后遍历father，看father.first==father.second，即father(a)==a，就相当于发现了一个并查集的顶点，然后res+1即可。

解法5：
union-find的另一个版本，find用递归版路径压缩算法。
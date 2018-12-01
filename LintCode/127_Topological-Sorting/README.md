127. Topological Sorting
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

Clarification
Learn more about representation of graphs

Notice
You can assume that there is at least one topological order in the graph.

Solution 1: Using BFS.
拓扑排序的算法是典型的宽度优先搜索算法，其大致流程如下：

统计所有点的入度，并初始化拓扑序列为空。
将所有入度为 0 的点，也就是那些没有任何依赖的点，放到宽度优先搜索的队列中
将队列中的点一个一个的释放出来，放到拓扑序列中，每次释放出某个点 A 的时候，就访问 A 的相邻点（所有A指向的点），并把这些点的入度减去 1。
如果发现某个点的入度被减去 1 之后变成了 0，则放入队列中。
直到队列为空时，算法结束，
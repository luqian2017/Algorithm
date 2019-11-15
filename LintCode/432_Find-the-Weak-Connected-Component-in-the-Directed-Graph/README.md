432. Find the Weak Connected Component in the Directed Graph

Find the number Weak Connected Component in the directed graph. Each node in the graph contains a label and a list of its neighbors. (a weak connected component of a directed graph is a maximum subgraph in which any two vertices are connected by direct edge path.)

Example
Example 1:

Input: {1,2,4#2,4#3,5#4#5#6,5}
Output: [[1,2,4],[3,5,6]]
Explanation:
  1----->2    3-->5
   \     |        ^
    \    |        |
     \   |        6
      \  v
       ->4
Example 2:

Input: {1,2#2,3#3,1}
Output: [[1,2,3]]
Clarification
graph model explaination:
https://www.lintcode.com/help/graph

Notice
Sort the elements of a component in ascending order.

解法1：Union-Find
这题最好用并查集做。用BFS/DFS也可以做，但因为是有向图，必须把有向链接转换成无向链接才行。为什么呢？
比如说Input: {1,2,4#2,4#3,5#4#5#6,5}
Output: [[1,2,4],[3,5,6]]
Explanation:
  1----->2    3-->5
   \     |        ^
    \    |        |
     \   |        6
      \  v
       ->4
如果用BFS/DFS的话，到了3就找不到6了，所以没法知道3和6是一组。
注意：
1）merge()的写法要注意。特别是最后是father[fatherX]=fatherY。不能写成father[x]=fatherY，这样x是连到了fatherY，但是fatherX到fatherY的链接就断了。为了简单起见，可以将merge(int x, int y)写成这样的模板：

```
void merge (int x, int y) {
    int x = find(x);
    int y = find(y);
    if (x != y) father[x]=y;
}
```
2) 当union完成后，以input={1,2,3,4#2,3#3#4}为例，其各个节点的father如下。
1's father is 3
2's father is 4
3's father is 4
4's father is 4
此时并不能看出它们都是同一个father，所以最后的for循环里面还是必须用find(x)来找到各个节点的最上层祖宗，不能直接用father[x]。

3) father在这里必须用map，不能直接用数组，因为label可能很大(不一定是1,2,3,4,5)，另外也可能是负数。
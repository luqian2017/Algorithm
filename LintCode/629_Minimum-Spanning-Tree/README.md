
629. Minimum Spanning Tree
Given a list of Connections, which is the Connection class (the city name at both ends of the edge and a cost between them), find some edges, connect all the cities and spend the least amount.
Return the connects if can connect all the cities, otherwise return empty list.

Example
Gievn the connections = ["Acity","Bcity",1], ["Acity","Ccity",2], ["Bcity","Ccity",3]

Return ["Acity","Bcity",1], ["Acity","Ccity",2]

Notice
Return the connections sorted by the cost, or sorted city1 name if their cost is same, or sorted city2 if their city1 name is also same.

Solution:
1. Prim algorithm.
我的方法是先将City按名称排序，先取第一个放入joint set，然后更新每个节点跟joint set的距离，再看那个节点离joint set 最近，将该节点放入joint set，同时更新每个节点跟joint set的距离，如此反复，直到所有节点都放入了joint set。
但我的solution不能pass，我看了一下fail的case，我的方案的output跟expected基本一样，只有一个distance不同 ，但distance的cost是一样的。这个可能是因为MST不唯一。
顺便提一下，什么样的图的MST唯一呢? 根据
https://zhidao.baidu.com/question/509521548.html
1) 当带权连通图的任意一个环中所包含的权值均不相同，其MST是唯一的。
2) 先正常求出最小生成树，再求次小生成树（具体可以枚举图上其他边加到树里，同时删去重复的边，找到权值和最小的删边方法），如果求出次小生成树的权值和与最小生成树不相等，则最小生成树唯一，否则不唯一。

2. Kruskal + union-find
解法2：Kruskal + union-find
Kruska 算法：⾸首先按照每条边的边权排序。然后依次按下面步骤将各条边加入MST：
1) 判断该边两个端点是否都已经在MST中。若都在，说明连这条边就会形成环，故不能选该边；否则至少有一端点不在MST中，所以把这条边加⼊入MST中。
2) 如何判断两个端点是否在一个结合中呢？并查集。
注意：最后result里面的connection数应为所有城市数-1。因为2个城市一个connection，而且又没有环。
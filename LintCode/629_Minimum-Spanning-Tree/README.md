
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
My solution still has issue to pass. The sum of the mst is the same as the stand solution, but the generated tree is lightly different. It might because the solution is not unique.

2. Kruskal + union-find
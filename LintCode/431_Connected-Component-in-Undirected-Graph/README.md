431. Connected Component in Undirected Graph
中文English
Find connected component in undirected graph.

Each node in the graph contains a label and a list of its neighbors.

(A connected component of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)

You need return a list of label set.

Example
Example 1:

Input: {1,2,4#2,1,4#3,5#4,1,2#5,3}
Output: [[1,2,4],[3,5]]
Explanation:

  1------2  3
   \     |  | 
    \    |  |
     \   |  |
      \  |  |
        4   5
Example 2:

Input: {1,2#2,1}
Output: [[1,2]]
Explanation:

  1--2

Clarification
Learn more about representation of graphs

Notice
Nodes in a connected component should sort by label in ascending order. Different connected components can be in any order.


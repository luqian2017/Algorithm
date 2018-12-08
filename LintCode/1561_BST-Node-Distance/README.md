1561. BST Node Distance
Given a list of numbers, construct a BST from it(you need to insert nodes one-by-one with the given order to get the BST) and find the distance between two given nodes.

Example
input:
numbers = [2,1,3]
node1 = 1
node2 = 3
output:
2
Notice
If two nodes do not appear in the BST, return -1
We guarantee that there are no duplicate nodes in BST
The node distance means the number of edges between two nodes

Solution:
First constuct the BST according to input sequence, then find the LCA of the two nodes, then add the distances of the two nodes to the LCA.
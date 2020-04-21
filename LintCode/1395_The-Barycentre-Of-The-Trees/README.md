1395. The Barycentre Of The Trees

For a multi-branch tree, if there is a node R with R as the root, and the largest sub-tree of all its sub-trees has the least number of nodes, the node R is said to be the center of gravity of the tree.
Now give you a multi-branch tree with n nodes. Find the center of gravity of this tree. If there are multiple centers of gravity, return the one with the lowest number.
x[i], y[i] represents the two points of the i-th edge.

Example
Example 1:

Given x = `[1]`, y = `[2]`, return `1`.
Input:
[1]
[2]
Output:
1

Explanation:
Both 1 and 2 can be center of gravity, but the number of 1 is the smallest.
Example 2:

Given x = `[1,2,2]`, y = `[2,3,4]`, return `2`.
Input:
[1,2,2]
[2,3,4]
Output:
2

Explanation:
2 is the center of gravity.
Notice
2 <= n <= 10^5
1 <= x[i], y[i] <= n


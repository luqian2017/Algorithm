1637. Tree problem
Given a tree of n nodes. The ith node's father is fa[i-1] and the value of the ith node is val[i-1]. Especially, 1 represents the root, 2 represents the second node and so on. We gurantee that -1 is the father of root(the first node) which means that fa[0] = -1.
The average value of a subtree is the result of the sum of all nodes in the subtree divide by the number of nodes in it.
Find the maximum average value of the subtrees in the given tree, return the number which represents the root of the subtree.

Example
Given fa=[-1,1,1,2,2,2,3,3], representing the father node of each point, and val=[100,120,80,40,50,60,50,70] , representing the value of each node, return 1.

Sample diagram：
                      -1  ------No.1
                    /     \
         No.2 ----1        1---------No.3
               /  |  \     /  \
              2   2   2    3   3
No.1 node is (100+120+80+40+50+60+50+70) / 8 = 71.25
No.2 node are (120 + 40 + 50 + 60) / 4 = 67.5
No.3 node are (80+50+70) / 3 = 66.6667
So return 1.
Notice
the number of nodes do not exceed 100000
If there are more than one subtree meeting the requirement, return the minimum number.

Solution 1:
Use map<int, Node> to record the relationship between the index and the sum/count.
First, go through the vector to record each one's sum and count.
Second, reversely go through the vector to add the sum and count to the fathers.
Third, go through the vector to record the maximum average.
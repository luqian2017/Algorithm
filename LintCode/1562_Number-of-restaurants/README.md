1562. Number of restaurants
Give a List of data representing the coordinates[x,y] of each restaurant and the customer is at the origin[0,0]. Find the n restaurants closest to the customer firstly. Then you need to pick n restaurants which appeare firstly in the List and the distance between the restaurant and the customer can't more than the longest distance in the n closest restaurants. Return their coordinates in the original order.

Example
Given : n = 2 , List = [[0,0],[1,1],[2,2]]
Return : [[0,0],[1,1]]
Given : n = 3,List = [[0,1],[1,2],[2,1],[1,0]]
Return :[[0,1],[1,2],[2,1]]
Notice
1.Coordinates in range [-1000,1000]
2.n>0
3.No same coordinates


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


这题实际上就是求N个无序数中的最小的n个数，所以用最大堆。
堆的大小为n。遍历完后取堆top，然后再遍历一遍，列出最先的n个比top小的数。
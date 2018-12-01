1563. Shortest path to the destination
Given a 2D array representing the coordinates on the map, there are only values 0, 1, 2 on the map. value 0 means that it can pass, value 1 means not passable, value 2 means target place. Starting from the coordinates [0,0],You can only go up, down, left and right. Find the shortest path that can reach the destination, and return the length of the path.

Example
Given:

[
 [0, 0, 0],
 [0, 0, 1],
 [0, 0, 2]
]
Return: 4

Notice
1.The map must exist and is not empty, there is only one target

Solution 1:
Using BFS.
Note: 
1) It is not necessary to use a visited map, as we can simply change the targetMap[i][j] = 1.
2) For struct Point, if we add the value field, make sure it will not update the target 2 as otherwise it will return -1.
3) In the validPlace(), make sure checking the p.x and p.y is inbound first.
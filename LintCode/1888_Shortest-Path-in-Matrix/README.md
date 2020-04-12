1888. Shortest Path in Matrix

Given the matrix of M rows and N columns, 0 represents empty space,- 1 represents obstacle, and 1 represents target points (there are multiple target points).

For each empty space, if you want to reach a target point at the shortest distance, please mark the direction of the first step.

If starting up, you should mark the point as 2. if starting down , you should mark the point as 3. if starting left , you should mark the point as 4. if starting right , you should mark the point as 5.

The priority of direction is up, down, left and right from big to small, that is, if you can reach the target point with the shortest distance from a point up or down, you are supposed to start up.

Returns the matrix after marking.

Example
input:[[1,0,1],[0,0,0],[1,0,0]]
output:[[1,4,1],[2,2,2],[1,4,2]]

Notice
0<m,n<1000

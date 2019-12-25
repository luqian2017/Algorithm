573. Build Post Office II

Given a 2D grid, each cell is either a wall 2, an house 1 or empty 0 (the number zero, one, two), find a place to build a post office so that the sum of the distance from the post office to all the houses is smallest.

Return the smallest sum of distance. Return -1 if it is not possible.

Example
Example 1:

Input：[[0,1,0,0,0],[1,0,0,2,1],[0,1,0,0,0]]
Output：8
Explanation： Placing a post office at (1,1), the distance that post office to all the house sum is smallest.
Example 2:

Input：[[0,1,0],[1,0,1],[0,1,0]]
Output：4
Explanation： Placing a post office at (1,1), the distance that post office to all the house sum is smallest.
Challenge
Solve this problem within O(n^3) time.

Notice
You cannot pass through wall and house, but can pass through empty.
You only build post office on an empty.

注意这题跟Build Post Office I 不一样，那道题目没有wall，并且可以穿过房屋和空地，所以肯定只要有房屋和空地就肯定有解，而这道题不能穿墙和房屋，有可能有的房屋永远到不了某个空地，所以就无解。
另外Build Post Office I可以简单的把4个方向的累加房屋数加起来，然后再根据Manhattan距离加上相应的累加距离即可。这题不能用这个方法，因为不能穿墙和房屋，所以用BFS比较好，因为BFS可以算最短距离。
房屋和墙的区别是：房屋要累加其到起始点的距离。
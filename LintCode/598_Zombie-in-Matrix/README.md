598. Zombie in Matrix

Given a 2D grid, each cell is either a wall 2, a zombie 1 or people 0 (the number zero, one, two).Zombies can turn the nearest people(up/down/left/right) into zombies every day, but can not through wall. How long will it take to turn all people into zombies? Return -1 if can not turn all people into zombies.

Example
Example 1:

Input:
[[0,1,2,0,0],
 [1,0,0,2,1],
 [0,1,0,0,0]]
Output:
2
Example 2:

Input:
[[0,0,0],
 [0,0,0],
 [0,0,1]]
Output:
4


解法1：BFS
将所有的zombie同时放入queue中，然后就跟正常bfs一样了。
注意：
1) 最后返回round-1，因为最后返回的时候会多算一空的一轮。
2) 当最后仍有people时，返回-1。这种情形就是people被封闭起来，zombie进不去。
3) 本来我想当某个round没有发现people时就返回当前round，这样round就不会多加1。但是不能直接返回当前round，因为可能有people没发现，参考2)。
4) 如果要返回round, q.size()一定要保存下来，因为queue的长度会变。
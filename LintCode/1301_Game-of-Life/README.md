1301. Game of Life

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example
Example :

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Challenge
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

解法1：

这个题目要注意的一点是矩阵的所有元素是一起变的，也就是说如果某个节点算出来最终会从0变到1，它的相邻节点计算的时候仍然会将其视为0。因为这个题目要求in-place，所以我们要把每个节点的起始值和计算后的值放在一起。

我的方法是1变成0时，将其存为3，这是因为3的最后一个bit还是1，这样别的节点只需要看最后一位比就可以了。
0变成1时，将其存为2，这是因为2的最后一个bit时0。

最后记得把整个矩阵再扫描一遍，3变成1，2变成0。
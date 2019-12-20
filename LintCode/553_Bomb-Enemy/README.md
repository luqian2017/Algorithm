553. Bomb Enemy
中文English
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.

Example
Example1

Input:
grid =[
     "0E00",
     "E0WE",
     "0E00"
]
Output: 3
Explanation:
Placing a bomb at (1,1) kills 3 enemies
Example2

Input:
grid =[
     "0E00",
     "EEWE",
     "0E00"
]
Output: 2
Explanation:
Placing a bomb at (0,0) or (0,3) or (2,0) or (2,3) kills 2 enemies
Notice
You can only put the bomb at an empty cell.

解法1：
参考自网上。
对每个i,j, 如果i==0，或上面一个元素为W，则计算j列从当前行到nRow累计的Enemy数。
如下图所示，当i=0,j=1时，所计算的累计enemy数为2(因为列1有2个E)。但grid[0][1]不为0，所以将colCount[1]保存下来，当i=1,j=1的时候就可以用上了。注意这里如果不保留下来colCount[j]，仅仅用一个colEnemy的话，对固定的i，每个j都会重新计算colEnemy，那样就会不准了，即i=0,j=1算好的colEnemy的值会被i=0,j=2计算的colEnemy替代。
而rowEnemy因为j本来就是从大到小迭代过来的，所以用一个rowEnemy就足够了。
[0 E 0 0]
[E 0 W E]
[0 E 0 0]

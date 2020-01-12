802. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the number 0.

You may assume that there will be only one unique solution.

Example
Example 1:

Given a Sudoku puzzle:


Return its solution:


解法1：DFS
注意：
1）从起始条件(0,0)开始，每次往后调用(x, y+1)，y越界后进入下一行(x+1,0)。x越界后说明成功得到一个可行解，故返回true。
2) dfs一定要返回boolean。如果是返回void，那么没法知道到底是不是得到了可行解。
3) 该题只要得到第一个可行解就可以了，所以不需要对dfs(x,y)进行x=0..9, y=0..9的循环调用。

1828. Lake Escape

Albert is stranded on a frozen lake. He wants to know if he can make it back to shore. He is currently on a snowbank that gives him some traction, but once he steps the ice. he will slide in the same direction until he hits another snowbank. There are also treacherous holes in the ice that he must avoid.

As a cruel twist of fate, Albert's young pup, Kuna, is also stranded, but on a different snowbank. Can Albert reach his pup AND make it to shore?

Albert can only move horizontally and vertically. He makes it to shore by leaving the lake grid.

The input contains these parameters:

side_length: the length of a side of the lake (it's a square)
lake_grid: a 2D matrix representing the lake 0 = ice, 1 = snowbank, -1 = hole
albert_row: row of Alber'ts snowbank
albert_column: column of Albert's snowbank
kuna_row: row of Kuna's snowbank
kuna_column: column of Kuna's snowbank
Example
Input:
7
[[0,0,0,0,0,0,0],[0,0,-1,0,0,0,0],[0,0,1,-1,0,-1,0],[-1,0,1,0,0,0,0],[0,1,1,0,0,1,0],[-1,0,-1,0,-1,0,0],[0,0,0,0,0,0,0]]
4
1
3
2
Output: true
Explanation:

As it seen in the picture. Yellow ceil is Albert's location and red ceil is Kuna's location. Albert can turn right to (4,2) and up to (3,2) then turn right to leave the lake grid.

![Avatar](map.jpg)

Challenge
Albert can't go to the shore and then find Kuna.

Notice
It is guaranteed
∣albert_row−kuna_row∣+∣albert_column−kuna_column∣>0。


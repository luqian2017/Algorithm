123. Word Search
中文English
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example
Example 1:

Input：["ABCE","SFCS","ADEE"]，"ABCCED"
Output：true
Explanation：
[    
     A B C E
     S F C S 
     A D E E
]
(0,0)A->(0,1)B->(0,2)C->(1,2)C->(2,2)E->(2,1)D
Example 2:

Input：["z"]，"z"
Output：true
Explanation：
[ z ]
(0,0)z

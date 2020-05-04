844. Number Pair Statistics

Given a List <Point> p, find the number of (i,j) pairs that satisfy both p[i].x + p[j].x and p[i].y + p[j].y(i < j) can be divisible by 2.

Example
Example1

Input: p = [[1,2],[3,4],[5,6]]
Output: 3
Explanation:
p[0],p[1],p[2] Pairwise Covering, the sum of their x and y can be divided by 2
Example2

Input: p = [[0,3],[1,1],[3,4],[5,6]]
Output: 1
Explanation:
Only when p [2] and p [3] are combined, their sum of x and y can be divided by two.
Notice
The length of given list len <= 10000.

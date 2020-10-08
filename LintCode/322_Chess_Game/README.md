322. Chess Game

In a game of chess, you are given two binary arrays:
a binary array queen with size N, which represents the coordinates of N queens;
a binary array knight with size M, which represents the coordinates of M knights.
A queen can attack any knight chess in the same row, column and diagonal.
You are asked to return an answer array with size M, the ith element of which shows whether the ith knight can be attacked.

Example
Example:
Input: [[1,1],[2,2]]
[[3,3],[1,3],[4,5]]
Output: [true,true,false]
Explanation: The first knight can be attacked by queen 1 and 2.
The second knight can be attacked by queen 1 and 2.
The last knight can not be attacked.

Notice
1≤N,M≤10^​5
​​ 
The range of chess coordinates is a positive integer from 1 to 10^9
​​ 


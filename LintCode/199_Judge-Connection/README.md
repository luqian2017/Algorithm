199. Judge Connection

Given a matrix of integers arr and an integer k, determine if all instances of value k in arr are connected. Two cells in a matrix are considered "connected" if they are horizontally or vertically adjacent and have the same value.

Example
Example 1:

Input:arr=[
[2,2,2,0],
[0,0,0,2],
[0,1,0,2],
[1,1,1,2]]
k=2
Output:false
Explanation: Not all `2` are connected to each other

Example 2:

Input:arr=[
[2,2,2,0],
[0,0,0,2],
[0,1,0,2],
[1,1,1,2]]
k=1
Output:true
Notice
∣arr∣≤500
∣arr[i]∣≤500
0≤arr[i][j]≤10000

[[2,2,2,0],[0,0,0,2],[0,1,0,2],[1,1,1,2]]
2

946. 233 Matrix
中文English
Given a matric A. The first row of matrix A is 0, 233, 2333, 23333...(i.e., A(0,0)=0,A(0,1)=233,A(0,2)=2333,A(0,3)=23333...). Besides, A(i,j)=A(i-1,j)+A(i,j-1).

Given an array X with n integers. X[i] is A(i+1,0), (i.e., X[0] is A(1,0), X[1] is A(2,0) ...), and a positive integer m.

Return the value of A(n,m) % 10000007.

Example
Example1

Input: X=[1], m=1
Output: 234
Explanation:
[[0,233],
 [1,234]]
Example2

Input: X=[0,0], m=2
Output: 2799
Explanation:
[[0,233,2333],
 [0,233,2566],
 [0,233,2799]]
Notice
n <=1 0, m <= 10^9
0 =< A(i,0) < 2^31


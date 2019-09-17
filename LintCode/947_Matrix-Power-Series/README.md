947. Matrix Power Series
中文English
Given a n × n matrix A and a positive integer k and a positive integer m, find the sum S = A + A^2 + A^3 + … + A^k,return the elements of S modulo m

Example
Example 1:

Input:
[[0,1],[1,1]]
2
4
Output:
[[1,2],[3,4]]
Example 2:

Input:
[[1,1],[1,1]]
7
10
Output:
[[7,7],[7,7]]
Notice
n<=30,1<=k<=10^9,1<=m<10^4
the range of the element of the Matrix A is [0,10000]

解法1：矩阵快速幂
当k是偶数时：

S(k) = A + A ^ 2 + ... + A ^ k
     = A + A ^ 2 + A ^ (k/2) + A ^ (k/2 + 1) + A ^ (k/2 + 2) + A ^ k
     = (E + A ^ (k/2)) *  (A + A ^ 2 + ... + A ^ (k/2))
     = (E + A ^ (k/2)) * S(k/2)

当k是奇数时，我们有s(k) = s(k - 1) + A ^ k
注意：
1） S(k) = (E + A ^ (k/2)) * S(k/2)，其中的+号两边和乘号两边都可互换。
因为当矩阵A * B的时候，如果A和B中有一个是单元矩阵，或A=B时满足交换律。
2） operator * 里面的最内层循环，可以先加完之后再模，这样省时间。当然前提是保证不溢出。

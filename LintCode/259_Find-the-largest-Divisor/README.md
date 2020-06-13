259. Find the largest Divisor

There are a positive integer array A and a positive integer k.
You need to find the largest factor d which satisfy:
upper(a_0/d)+upper(a_1/d)+...+upper(a_{n-1}/d) >= k

It's promised that there is a solution.

Example
Example 1

input：[1,2,3,4,5] 6
output：4
explain：upper(1/4) = 1, upper(2/4) = 1, upper(3/4) = 1, upper(4/4) = 1, upper(5/4) = 2, 1+1+1+1+2 = 6
Example 2

input：[5,15,20,25] 6
output：19
explain：upper(5/19) = 1, upper(15/19) = 1, upper(20/19) = 2, upper(25/19) = 2, 1+1+2+2 = 6

Notice
0<|A|<=1000
0<A[i], k<=1e9
d is an integer and d is no more than the largest value in array A.
upper() means round up.

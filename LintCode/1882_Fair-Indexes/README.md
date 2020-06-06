1882. Fair Indexes

You are given two arrays A and B consisting of N integers each.

Index K is named fair if the four sums(A[0]+...A[K-1]),(A[K]+...+A[N-1]),(B[0]+...+B[K-1]) and (B[K]+...+B[N-1]) are all equal, In other words, K is the index where the two arrays, A and B, can be split (into two non-empty arrays each) in such a way that the sums of the resulting arrays’ elements are equal.

For example, given arrays A = [4,-1, 0, 3] and B = [-2, 5, 0, 3], index K = 2 is fair. The sums of the subarrays are all equal: 4+(-1) = 3; 0+3 = 3; -2 + 5 = 3 and 0 + 3 = 3.

Now you have to figure out the number of fair indexes.

Example
Example 1:

Input: [4,-1,0,3] [-2,5,0,3]
Output: 2
Example 2:

Input: [2,-2,-3,3] [0,0,4,-4]
Output: 1
Example 3:

Input: [4,-1,0,3] [-2,6,0,4]
Output: 0
Example 4:

Input: [1,4,2,-2,5] [7,-2,-2,2,5]
Output: 2
Notice
2<=N<=100000
-1000000000<=a[i],b[i]<=1000000000 (0<=i<N)

Solution 1:
Based on binary search: trying to search the Kth smallest number between the two sorted arrays.

Each time search K/2 of arrayA and arrayB.

1) If startA exceeds A.size(), then the Kth smallest elements should be B[startB + K -1];
If startA exceeds A.size(), then the Kth smallest elements should be B[startB + K -1];

2) if K == 1, then return the min of A[startA] and B[startB]

3) if startA + K / 2 is still within arrayA, and
startB + K / 2 is still within arrayB, then compare halfKOfA and halfKOfB: 

if halfKOfA > halfKOfB, then the Kth smallest number should be in
 A[startA..startA+K/2] and B[startB+K/2..startB+K] 

if halfKOfA < halfKOfB, then the Kth smallest number should be in
 A[startA+K/2..startA+K] and B[startB..startB+K/2]

Time complexity O(log(m+n)).
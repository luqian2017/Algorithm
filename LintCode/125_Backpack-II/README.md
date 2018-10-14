Solution 1:
Typical 0-1 backpack problem.
Use DP.
Time complexity O(MN).  //M: item count    N: packet size
Space complexity O(MN).

Note dp[][] range is [0..itemCount][0..packSize]   //m=packSize
both indexes needs to start from 1.
A[] and V[] index from 0.

Solution 2:
Solution 1 + Rotation array optimization.
Time complexity O(MN)
Space complexity O(N).

Solution 3:
Reverse the sequence order in the second loop:
Note: At time i, dp[j] is updated, dp[j - A[i - 1]] is still not updated, so it is still the value at time i - 1.
Time complexity O(MN).
Space complexity O(N). But only one-dimension array is used.


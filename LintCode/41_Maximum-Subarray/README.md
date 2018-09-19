Solution 1: O(n).

result is for the final result.
sum is for the current partial sum.

Go through the array. If sum + nums[i] < nums[i], it means we can just start from nums[i].

Note: 
1) Initial condition: result = INT_MIN, sum = 0.
We can not set both result and sum = INT_MIN as the nums[i] can be -1, thus INT_MIN+nums[i] lead to overflow.
We cannot set both result and sum = 0 as nums[i] can be all < 0.
 

Solution 2: Divide and Conquer. 
Time complexity O(nlogn).
TBD.



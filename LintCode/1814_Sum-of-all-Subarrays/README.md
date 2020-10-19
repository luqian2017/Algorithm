1814. Sum of all Subarrays

Given a list of nums, return the sum of all subarrays.

Example
Example1:
Input: nums = [1, 2, 3]
Output: 20
Explanation : {1} + {2} + {3} + {2 + 3} + {1 + 2} + {1 + 2 + 3} = 20
Example2
Input : [1, 2]
Output : 6
Explanation :{1} + {2} + {1, 2} = 6 
Notice
if nums = [2, 4, 1], subarrays is {[2], [4], [1], [2, 4], [4, 1], [2, 4, 1]}
Guaranteed that the result returned is the type of int
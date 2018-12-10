609. Two Sum - Less than or equal to target
Given an array of integers, find how many pairs in the array such that their sum is less than or equal to a specific target number. Please return the number of pairs.

Example
Given nums = [2, 7, 11, 15], target = 24.
Return 5.
2 + 7 < 24
2 + 11 < 24
2 + 15 < 24
7 + 11 < 24
7 + 15 < 25

Solution:
1) Two pointers. 
It is a variant of two-pointer algorithm.
Note that when nums[p1] + nums[p2] <= target, we do not need to decrease p2, as we need to get the count increment p2 - p1.
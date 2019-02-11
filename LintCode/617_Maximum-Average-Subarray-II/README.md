617. Maximum Average Subarray II

Given an array with positive and negative numbers, find the maximum average subarray which length should be greater or equal to given length k.

Example
Given nums = [1, 12, -5, -6, 50, 3], k = 3

Return 15.667 // (-6 + 50 + 3) / 3 = 15.667

Notice
It's guaranteed that the size of the array is greater or equal to k.

Solution:
1) Use prefix sum. O(MK). But it will exceed time limit
2) Use Binary Search.
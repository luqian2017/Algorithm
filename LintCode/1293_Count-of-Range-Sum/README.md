1293. Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Example
Example 1:

Input：[-2, 5, -1],-2,2
Output：3
Explanation：The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
Example 2:

Input：[0,-3,-3,1,1,2],3,5
Output：2
Explanation：The three ranges are : [3, 5], [4, 5] and their respective sums are: 4, 3.
Notice
A naive algorithm of O(n^2) is trivial. You MUST do better than that.


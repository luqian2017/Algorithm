1529. Triplet Subarray With Absolute Diff Less Than or Equal to Limit

Given an increasing array of integers nums and an integer limit, return the number of the triplet subarray in which the absolute difference between any two elements is less than or equal to limit.

In case there is no subarray satisfying the given condition return 0.

Example
Example 1:

Input：[1, 2, 3, 4], 3
Output：4
Explanation：We can choose (1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4). Therefore, the number of the triplet subarray is 4.
Example 2:

Input: [1, 10, 20, 30, 50], 19
Output：1
Explanation：The only triplet array is (1, 10, 20), so the answer is 1。
Challenge
Can you figure out a solution with time complexity of O(n)?

Notice
1 ≤ len(nums) ≤ 1e4，1 ≤ limit ≤ 1e6，0 ≤ nums[i] ≤ 1e6
Since the answer may be too large, return it modulo 99997867.


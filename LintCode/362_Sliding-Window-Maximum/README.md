Description
Given an array of n integer with duplicate number, and a moving window(size k), move the window at each iteration from the start of the array, find the maximum number inside the window at each moving.

Have you met this question in a real interview?  
Example
For array [1, 2, 7, 7, 8], moving window size k = 3. return [7, 7, 8]

At first the window is at the start of the array like this

[|1, 2, 7| ,7, 8] , return the maximum 7;

then the window move one step forward.

[1, |2, 7 ,7|, 8], return the maximum 7;

then the window move one step forward again.

[1, 2, |7, 7, 8|], return the maximum 8;

Challenge
o(n) time and O(k) memory

Solution:
Using non-increasing queue (a.k.a monotonous decreasing queue)

Note: 
1) For non-increasing queue, uses (nums[i] > nums[dq.back()])
   For non-decreasing queue, uses (nums[i] < nums[dq.back()])
2) The condition (i - dq.front() == k) is used to judge to pop out a num.
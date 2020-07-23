724. Minimum Partition

Given a set of positive integers, write a function to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example
Example1

Input: nums = [1, 6, 11, 5]
Output: 1
Explanation: 
Subset1 = [1, 5, 6], sum of Subset1 = 12 
Subset2 = [11], sum of Subset2 = 11   
abs(11 - 12) = 1     
Example2

Input: nums = [1, 2, 3, 4]
Output: 0
Explanation: 
Subset1 = [1, 4], sum of Subset1 = 5
Subset2 = [2, 3], sum of Subset2 = 5   
abs(5 - 5) = 0

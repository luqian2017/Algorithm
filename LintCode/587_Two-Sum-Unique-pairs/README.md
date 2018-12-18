587. Two Sum - Unique pairs
Given an array of integers, find how many unique pairs in the array such that their sum is equal to a specific target number. Please return the number of pairs.

Example
Given nums = [1,1,2,45,46,46], target = 47
return 2

1 + 46 = 47
2 + 45 = 47

Solution:
Typical two-pointers algorithm + Map.
Note:
   mp[nums[p1]] = nums[p2];  //should not be written as mp[p1] = p2;

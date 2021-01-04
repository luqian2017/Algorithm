### 1879. Two Sum VII



Given an array of integers that is already sorted in ascending absolute order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are zero-based.

You are not allowed to sort this array.

### Example

```plain
Input: 
[0,-1,2,-3,4]
1
Output: [[1,2],[3,4]]
Explanation: nums[1] + nums[2] = -1 + 2 = 1, nums[3] + nums[4] = -3 + 4 = 1
You can return [[3,4],[1,2]], the system will automatically help you sort it to [[1,2],[3,4]]. But [[2,1],[3,4]] is invaild.
```

### Challenge

O(*n*) time complexity and O(1) extra space

### Notice

- It is guaranteed that all numbers in the nums is distinct.
- The length of nums≤100000.
- The number in nums is 10^9.

Input test data (one parameter per line)How to understand a testcase?
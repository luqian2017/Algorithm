
16. Permutations II
中文English
Given a list of numbers with duplicate number in it. Find all unique permutations.

Example
Example 1:

Input: [1,1]
Output:
[
  [1,1]
]
Example 2:

Input: [1,2,2]
Output:
[
  [1,2,2],
  [2,1,2],
  [2,2,1]
]
Challenge
Using recursion to do it is acceptable. If you can do it without recursion, that would be great!

解法1：

这题跟Permutation那题的区别就是在于有重复元素，比如说
input: {1,2,2}, 
output: { {1,2,2} , {2,1,2} , {2,2,1} } 

所以关键在于去重。
我们可以把2,2看成2个不同的2，先排序，然后根据nums[i]==nums[i-1]就可以知道重复元素出来了。我们的原则是保证前面的2排在后面的2前面，避免后面的2排在前面的2的前面，这样就可以去重了。 

注意： 

1) 要先排序，不然没法知道是不是重复元素出来了。 

2) if (visited[i]) continue; 这行还是适用，因为这里i=0..nums.size()-1，所以两个2的visited[]不一样！！！ 

3) 去重的关键在于下面者一行 
if (i > 0 && (nums[i] == nums[i-1]) && !visited[i - 1]) continue; 
如果nums[i]==nums[i-1]但nums[i-1]又没有被visited过，说明后面的2要被排在前面的2前面了，这种情况要绝对避免，所以continue。

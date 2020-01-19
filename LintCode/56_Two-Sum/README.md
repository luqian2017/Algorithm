56. Two Sum
中文English
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are zero-based.

Example
Example1:
numbers=[2, 7, 11, 15], target=9
return [0, 1]
Example2:
numbers=[15, 2, 7, 11], target=9
return [1, 2]
Challenge
Either of the following solutions are acceptable:

O(n) Space, O(nlogn) Time
O(n) Space, O(n) Time
Notice
You may assume that each input would have exactly one solution

解法1：先排序后双指针
O(n) Space, O(nlogn) Time
解法1：先排序后双指针
O(n) Space, O(nlogn) Time
这个是最经典的解法了。但我在网上看到关于其原理的真正阐述清楚的好像不多，因为细想一下就不清楚为什么这个解法不会漏掉解呢？比如说sum<target时，为什么是p1++，为什么不会是p2--呢？

下面我提一下我的证明。
假设p1,p2已经分别指向i, j，其中0<=i<j<n，我们用状态(i,j)来表示p1,p2所处的状态。这里的i,j是排序后的序号。现在sum(i,j)=nums[i]+num[j]，根据我们的算法，(i,j)要么来自(i-1,j)，要么来自(i, j+1)。
假定sum < target (sum>target的情况类似)：
1) 假设上个状态是(i-1,j)，那么根据我们的算法，sum(i-1, j) = nums[i-1]+nums[j]<target。现在我们已经是(i,j)，当然我们不需要再选择i--了。我们也不能选择j-1，因为nums[j-1]<nums[j]，所以sum(i, j-1)<target。那么我们为什么不选择j+1呢? 假设j+1还是小于n的话，因为(i,j)之前的某个状态必定是(?,j+1)，这里0<=?<=i-1。之前可能有很多这样的状态(即p1=0..i, p2=j+1)。
现在我们假定这里面最近的那个状态是(x,j+1)。那么状态变化必定是下面的情况：
(x, j+1)=>(x,j)=>...=>(i,j).
sum(x,j+1)>target,so it moves to sum(x,j)
sum(x,j)<target, x < i, so it moves to sum(x-1, j, and so on, to sum(i,j) < target
sum(i,j+1) > sum(x,j+1) > target，故不用考虑(i,j+1)这种情况。
为什么不会是情况(x,j+1)=>(x-1,j+1)=>...=>(i,j)，因为我们已经说了x是p2=j+1的最近的那个状态。

解法2：hashmap
O(n) Space, O(n) Time
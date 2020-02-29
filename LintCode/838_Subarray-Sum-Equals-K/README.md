838. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example
Example1

Input: nums = [1,1,1] and k = 2
Output: 2
Explanation:
subarray [0,1] and [1,2]
Example2

Input: nums = [2,1,-1,1,2] and k = 3
Output: 4
Explanation:
subarray [0,1], [1,4], [0,3] and [3,4]

解法1：
参考的网上的解法。感觉很巧妙。
主要思路就是用Hashmap<int, int>来存储Presum和其freq。
如果扫描到某个元素时发现hashmap[presum - k] > 0，说明前面某个presum = 当前presum - k，则把当前的hashmap[当前presum-k]加入到count中。
注意：为什么要设hashmap[0]=1?
看看input: [1,1,1] k = 2
当i=1时,presum = 2，而hashmap[2-2]=hashmap[0]，此时count应该加1，所以hashmap[0]=1。
注意后面这个hashmap[0]还可能会变的。
比如说input: [0,0,0,0,0,0,0]，hashmap[0]一开始设为1，后面每个i都会逐步累加，一直加到8。
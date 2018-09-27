这题我参考的九章的答案，感觉不容易。

解法1:

先求出所有数组的元素数目之和totalCount，然后直接用二分法查找从0到INT_MAX的所有数，检查函数是findKthLargestNumber()，它会检查某个vector以及所有vector中有多少个数大于等于该数。

二分法的具体实现中，如果已经有多于k个数大于该数，那么说明这第k个数在(mid…end]，若小于k个数大于该数，说明这第k个数在[start, mid)。关键点在于如果刚好k个数大于该数的处理，

注意:

为防溢出，even number的情况用

findKthLargestNumber(nums, totalCount / 2) / 2.0 +
findKthLargestNumber(nums, totalCount / 2 + 1) / 2.0;

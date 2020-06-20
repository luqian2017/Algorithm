264. Counting Universal Subarrays

You will be given an array comprised of '2's or '4's. A subarray (A subarray is a group of contiguous elements in an array and cannot be empty) of such an array is called " universal" if it matches the following conditions:

The 2's and 4's are grouped consecutively (e.g., [4, 2],[2, 4],[4, 4, 2, 2],[2, 2, 4, 4],[4, 4, 4, 2, 2, 2], etc.).
The number of 4's in the subarray is equal to the number of 2's in the subarray.
Subarrays with the same element but different positions are treated differently. For example, there are two [4, 2] subarrays in array[4, 2, 4, 2].
You need to return an integer value, the number of "universal" subarrays in a given array.

Example
Sample 1:
Input sample: array = [4, 4, 2, 2, 4, 2]
Output sample: 4
Sample explanation: The 4 subarrays that match these two criteria are: [4, 4, 2, 2]，[4,2]，[2,4]，[4,2]. Note that there are two subarrays [4,2], in indexes 1-2 and 4-5, respectively.

Sample 2:
Input sample: array = [4, 4]
Output sample: 0
Sample explanation: the given array does not have 2, certainly cannot satisfy the condition two, so the result is 0.

Notice
1 ≤ |array| ≤ 10^5
array[i] ∈ (2, 4)

解法1：
我开始的想法是把数组里面的2和4分别替换成1和-1。这样，求presums只需要看某一段是不是0就可以了。
如果某一段[i..j]的sum是0，注意i到j的数目是偶数个，比如说{4,4,2,2,4,2}, sum(0..3)=0 (注意是把4和2换成了1和-1), 我们可以对其进一步处理，否则就不用管了。如何进一步处理呢？注意{4,4,2,2}会转换成{1,1,-1,-1}，那么前半段累加起来的绝对值(因为前半段也可能都是-1)就应该是总数目的一半，即2。这样，可以排除掉{4,2,2,4}的情形，因为这种情况下它会转换成{1,-1,-1,1}，前半段累加起来的绝对值是0。

这个算法应该是正确的，不过时间复杂度是O(n^2)，还是会超时。

解法2：
参考了牛人的解法。直接将{4,4,2,2,4,2}转换成freq数组，即{2,2,1,2}。那么，结果就是sum of min{freq[i - 1], freq[i]}。非常巧妙！
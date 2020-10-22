1814. Sum of all Subarrays

Given a list of nums, return the sum of all subarrays.

Example
Example1:
Input: nums = [1, 2, 3]
Output: 20
Explanation : {1} + {2} + {3} + {2 + 3} + {1 + 2} + {1 + 2 + 3} = 20
Example2
Input : [1, 2]
Output : 6
Explanation :{1} + {2} + {1, 2} = 6 
Notice
if nums = [2, 4, 1], subarrays is {[2], [4], [1], [2, 4], [4, 1], [2, 4, 1]}
Guaranteed that the result returned is the type of int

解法1：

这题有点像数学题。我开始想成了subset，后来发现是求subarray。
那么，我们可以这么看这么一个问题。长度为n的array里面的subarray的个数是多少呢？
比如说arr = {a,b,c,d}，那么subarray就有a, ab, abc, abcd, b, bc, bcd, c, cd, d, abcd共10个。
假设共n个元素，那么
包含下标0的subarray有n个，
包含下标1的，前面没算过的subarray 有n-1个,
...,
包含下标n-1的，前面没算过的subarray有1个。
所以，总共subarray的个数为sum{0..n-1}(n-i) = n*n-sum{0..n-1}i=n^2-n*(n-1)/2=n*(n+1)/2。
那么，对本题而言，对每个下标i，我们可以知道所有subarray的个数为n*(n+1)/2。而下标i左边的元素个数为i(i从0开始)，所以下标i的左边的subarray的个数为i*(i+1)/2。下标i右边的元素个数为r=max(0, len-i-1)，所以下标i的右边的subarray的个数为r*(r+1)/2。用减法，可得包含下标i的subarray的个数。


解法2：上面解法稍繁琐，但效率可能还高些，因为用的减法。
网上看到的标准解法如下。
对元素nums[i]，包含其的subarray可以看成左边和右边的拼接。
而包含nums[i]的左边subarray共有i+1个(i从0开始)。比如说nums={a,b,c,d}, 那么包含c的左边subarray共有3个(c,bc,abc), i=2。
nums[i]的右边subarray共有(n-i)个。
两边的拼接，一共有(i+1)*(n-i)种可能。
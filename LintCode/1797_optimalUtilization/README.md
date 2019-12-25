1797. optimalUtilization

Give two sorted arrays. To take a number from each of the two arrays, the sum of the two numbers needs to be less than or equal to k, and you need to find the index combination with the largest sum of the two numbers. Returns a pair of indexes containing two arrays. If you have multiple index answers with equal sum of two numbers, you should choose the index pair with the smallest index of the first array.

The sum of the two numbers <= k
The sum is the biggest
Both array indexes are kept to a minimum
Example
Example1

A = [1, 4, 6, 9], B = [1, 2, 3, 4], K = 9
return [2, 2]
Example2:

Input: 
A = [1, 4, 6, 8], B = [1, 2, 3, 5], K = 12
Output:
[2, 3]



这题标成容易题，我觉得并不好想。特别是Binary Search很不容易调通。网上看到不少解法也不完善，主要是不满足“Both array indexes are kept to a minimum"这个条件。

解法1：双指针指针
这个比较好想。两个指针分别指向A,B，都从0开始，当sum<=K并且sum<maxCount时记录结果。注意这里是用的sum<maxCount，所以当后面有新的B的元素有同样的sum时，也没法更新result，同时i也是从0开始的，这样就保证了两个数组的下标尽量小。



解法2：Binary Search
A数组从0到n-1遍历，对每个A元素，B数组用二分法找出相应元素，满足sum<=K，同时sum尽量大而且两个数组下标又尽量小。这个其实非常不容易调通，主要是因为有重复元素。
注意:
1) 用二分法模板时，当sum==K时，记录result，同时end=mid，注意这里不能返回，因为可能还有index更小的B元素也满足条件(重复元素)。
2) 当while()结束后，还要考虑start和end两个边界条件的情况。这里start<end。我们先考虑start的情况，end的情况只有sum2 > maxCount (而不是>=)才更新result，这样就保证了数组下标最小。
如果我们不考虑start和end两个边界条件会怎么样呢？
以input=
[1, 4, 6, 8]
[1, 2, 3, 5]
12
为例，
Output
[3,2]  //{8,3}
Expected
[2,3] //{6,5}
即在while()中，当i=2//A[2]=6时，B数组只考虑到了mid=3的情况，没有考虑end=4的情况。
3) 如果我们最后不考虑重复元素的情况，即尽量把重复元素往前挪动，结果仍然不对。
以input=
[1, 1, 3, 3, 6, 11, 12, 14, 15, 18]
[5, 5, 9, 12, 18]
9
为例：
Output
[2,1]
Expected
[2,0]
即我们仍应该手动找出重复元素中第一个出现的那个下标。这里应该还可以用Binary Search优化，下次再做。
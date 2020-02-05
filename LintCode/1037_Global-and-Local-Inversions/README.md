1037. Global and Local Inversions

Given a permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of global inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions, otherwise returh false.

Example
Example 1:

Input: [0, 1, 2]
Output: true
Explanation: There is 0 global inversion, and 0 local inversion.
Example 2:

Input: [1, 2, 0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Notice
A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.

解法1：参考自九章。非常牛！
这道题目表述明确，问题清晰，其解法也有很多种。这里我们介绍一种在时间和空间上高效，同时便于理解，亦可扩展的方法。
2. 首先思考全局逆序数和局部逆序数的定义，不管是哪种逆序数，都是这一对元素大小颠倒。而且发现，局部逆序数一定是全局逆序数，而全局逆序数不一定是局部逆序数，当且仅当全局逆序数的i和j相差大于1时，这就只是一组全局逆序数，但不是局部逆序数。
3. 进而，想返回true，对于任意的i，A[0]到A[i - 2]（如果i >= 2）必须都要小于A[i]，A[i + 2]到A[N - 1]（如果i <= N - 3）都必须要大于A[i]。否则，一定返回false。
4. 更进一步，我们只用检查所有的i，使得A[0]到A[i - 2]是否都小于A[i]即可。而且A[i]的右侧不用检查。这是因为如果A[i]右侧存在比A[i]小的数，记它为A[k]，则在以后检查A[k]的左侧时，就能检查出A[i]存在问题。
5. 所以，我们只需要初始化i为2，不断自增i，同时记录A[0]到A[i - 2]的最大值max_value，并保证max_value不大于A[i]，否则直接返回false。在一次遍历完之后，直接返回true即可。
6. 复杂度分析：
1. 时间复杂度：O(N)，这里只需要一次遍历数组A。
2. 空间复杂度：O(1)，只需要max_value，不断更新即可。
7. 一些扩展：该方法的适用范围其实强于这道题，因为这道题限定了数组元素一定是[0, 1, 2, ... N - 1]。但是如果使用该方法，我们并不需要这种限制。不过这个限制带给我们的额外好处是可以初始化max_value为0，因为不存在比0小的元素。
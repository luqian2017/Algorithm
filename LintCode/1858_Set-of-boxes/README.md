1858. Set of boxes

We have a lot of boxes to transport. To save space, we put the boxes together. Give you the length and width of each box. What is the maximum number of layers?

Example
Input: boxes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation:The maximum number of boxes is 3 ([2,3] => [5,4] => [6,7]).
Input: boxes = [[1,5],[6,2]]
Output: 2
Explanation:The maximum number of boxes is 2 ([1,5] => [2,6]).
Notice
The input may not be length in front, wide in back.You can see Examle 2.
You can rotate the box, but make sure that the four sides are parallel to the four sides of the original box, that is, do not place it diagonally.
This number of boxes is between [1,50000]
The thickness of the box is not negligible, so it must be strictly smaller.

这题的思路有个难点是要把箱子都按长对长，宽对宽排列，因为这样的话肯定比不管长宽乱比结果来得好。所以每个箱子要按长宽排好序。

解法1：DP，时间复杂度O(n^2)，会超时。

注意operator<的第二维比较可以是y>a.y,也可以是y<a.y。因为dp里面我们会同时比较x和y。

解法2：单调递增队列。

这道题类似LIS(LintCode 76)那道题，不过这里是2维的，更难一点。

难点：排序的时候，第1维升序，第2维降序。假设排序后队列如下：

(1,8)
(2,3)
(5,4)
(5,2)
(6,7)
(6,4)

为什么第2维要降序呢？因为看下面的例子，(5,4)排在(5,2)前面。单调递增队列轮到(5,2)的时候，binary search返回的序号就是(5,4)的序号(lower_bound，按y来搜索)，所以它会踢掉(5,4)。如果第2维升序的话，那么(5,2)排在(5,4)前面，单调递增队列先把(5,2)放进来，再看(5,4)的时候因为4>2，所以(5,4)也会放进队列，这样队列里面有2个箱子第1维都是5，就不对了。

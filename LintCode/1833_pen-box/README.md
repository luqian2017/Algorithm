### 1833. pen box

Given you an array boxes and a target. Boxes[i] means that there are boxes[i] pens in the ith box. Subarray [i, j] is valid if sum(boxes[i] + boxes[i+1] + ... + boxes[j]) == target. Please find two not overlapped valid subarrays and let the total length of the two subarrays minimum. Return the minimum length. If you can not find such two subarrays, return -1.

boxes.length <= 10 ^ 6106 and boxes[i] > 0

### Example

**Example 1**

```plain
Input:
boxes = [1,2,2,1,1,1],
target = 3

Output: 4
```



解法1：这题我感觉O(n)的解法并不容易。参考网上的答案。

思路是presums加上同向双指针。为啥是同向双指针呢？因为presums是递增数组，那么，这题就可以看成是两数之差等于定值那题(Lintcode 610)的变种了。
我们采用挡板法，每个挡板i处求出left_min[i]和right_min[i]。然后求其和的最小值即可。
left_min[]数组的求法和两数之差等于定值那题一样，但是我们不光要求两数之差等于target，而且还要求这两个数之间的间隔最小，所以还要用到 left_min[right] = min(left_min[right - 1], left_min[right])。
求right_min[]数组也一样。
如果输入是[1,1,1,2,1,1,1,1,1,1,2,1,1,1]，target=2，那么结果应该等于2。因为第1个2和第2个2都等于target, 它们的长度都为1，加起来是2。
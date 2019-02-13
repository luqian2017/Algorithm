414. Divide Two Integers

Divide two integers without using multiplication, division and mod operator.

If it will overflow(exceeding 32-bit signed integer representation range), return 2147483647

Example
Example 1:

Input: dividend = 0, divisor = 1
Output: 0
Example 2:

Input: dividend = 100, divisor = 9
Output: 11

这题看起来很容易，其实很难。首先这题不能排序，也不能用hash，因为题目要求不能动数组，只能用O(1)空间。也不用考虑XOR了，因为重复数可以重复n多次(n>1)。

思路1：基于binary search。
假设数组[6,6,7,6,3,6,6,6,6,6,10]，共11个元素。n=10。假设重复数是d,
规律1：对于某个数x，如果数组中小于等于x的数的个数<x，那么x<d。
举例: 数组中<=3的数的个数是1。原因很简单，因为<3的数中某些被6替代了。
规律2：对于某个数x，如果数组中小于等于x的数的个数>x，那么x>=d。
举例: 数组中<=6的数的个数是9，<=7的个数是10，<=10的个数是11。
注意这里是x>=d，而不是x>d。
规律3：对于某个数x，如果数组中小于等于x的数的个数=x，那么x<d。
举例：数组[5,5,4,3,2,1]， 小于等于3的个数是3，而3<5。

实际上，规律1和规律3可以合并，即
规律4：对于某个数x，如果数组中小于等于x的数的个数<=x，那么x<d。

注意：

calCount()里面比较大小一定要用<=，而不是<
该模板最后结束while()循环后，把范围缩小到start和end两个元素。如果calCount(start) > start, 根据规律2，start >= dup，既然start已经大于dup，那当然轮不到end了。否则calCount<=start，根据规律4，start < dup，此时返回end即可。


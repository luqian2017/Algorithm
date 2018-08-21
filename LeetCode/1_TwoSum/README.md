这题比较简单。 两种解法：

1) 双指针法。
将原数组排序后用两个指针，一前一后凑。 然后找到后还要从原数组中把index找出来。 时间复杂度O(nlogn)

2)用unordered_map。
注意unordered_map内部用Hash实现，所以查找只用O(1)，总时间复杂度O(n)。如果用map的话，因为其内部为RB树，查找需要O(logn)，所以时间复杂度还是O(nlogn)。

另外 需要注意最后输出的时候
vector<int>{um[diff], i};
不是vector<int>{i, um[diff]}。因为是从前往后扫描，要等到后面才能发现前面已经有了,所以um[diff]放在前面。
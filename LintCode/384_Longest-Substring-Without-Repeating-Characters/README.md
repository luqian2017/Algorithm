384. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Example
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

Challenge
O(n) time



解法1：
思路：
1) 用table[s[i]] = i记录每个字符上次出现的位置。
2) 当table[s[i]] >= 0时说明s[i]重复出现。
3) 用指针pos表示当前segment开始位置。
4) 当table[s[i]] > pos时说明需要考虑从pos到i的这段新segment。


解法2：双指针
count[256]存储每个字符在p1..p2窗口内重复次数。一开始p1=0,p2=0。
p2先跑，一直跑到出现某个字符重复次数>1，然后p1再跑，一直跑到p2的那个重复元素为止。每次更新maxLen。
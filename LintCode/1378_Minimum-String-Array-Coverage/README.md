1378. Minimum String Array Coverage

Given a string collection tag_list, an array of strings all_tags, find the smallest all_tags sub-array contains all the string in the tag_list, output the length of this sub-array. If there is no return -1.

Example
Example1

Input:  tag_list = ["made","in","china"], all_tags = ["made", "a","b","c","in", "china","made","b","c","d"]
Output: 3
Explanation:
["in", "china","made"] contains all the strings in tag_list,6 - 4 + 1 = 3.
Example2

Input:  tag_list = ["a"], all_tags = ["b"]
Output: -1
Explanation:
Does not exist.
Notice
1 <= |tag_list|,|all_tags| <=10000
All string length <= 50
String is not repeated in tag_list


解法1：
双指针法。p2先往右移动，直到包含所有目标字符串。
然后p1往右移动，同时调整hashmap的值。如果窗口中的目标字符串都在的话，p1会一直移到p2，直到窗口中的目标字符串不全，此时p1停下，p2继续往右移动。
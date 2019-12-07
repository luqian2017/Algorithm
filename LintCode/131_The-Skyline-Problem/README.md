131. The Skyline Problem

Given N buildings in a x-axis，each building is a rectangle and can be represented by a triple (start, end, height)，where start is the start position on x-axis, end is the end position on x-axis and height is the height of the building. Buildings may overlap if you see them from far away，find the outline of them。

An outline can be represented by a triple, (start, end, height), where start is the start position on x-axis of the outline, end is the end position on x-axis and height is the height of the outline.

Building Outline

Example
Example 1

Input:
[
    [1, 3, 3],
    [2, 4, 4],
    [5, 6, 1]
]
Output:
[
    [1, 2, 3],
    [2, 4, 4],
    [5, 6, 1]
]
Explanation:
The buildings are look like this in the picture. The yellow part is buildings.
图片

Example 2

Input:
[
    [1, 4, 3],
    [6, 9, 5]
]
Output:
[
    [1, 4, 3],
    [6, 9, 5]
]
Explanation:
The buildings are look like this in the picture. The yellow part is buildings.
图片

Notice
Please merge the adjacent outlines if they have the same height and make sure different outlines cant overlap on x-axis.

解法1：这题不容易。思路参考自网上。注意这题一定只要比较每个building的开始时间，不能把开始时间和结束时间混在一起。

1) 用multiset(相当于最大堆)，存储buildings的高度。
2) 遍历buildings，每次当building的起始位置时进堆，结束位置时出堆。
3) 当本次heap的最大值与上次记录heap的最大值不一致(不管是变大还是变小)时，检查上次heap记录的最大值的高度和时间，若都非0，则记录{preTime, curTime, preHeight}，同时更新curTime, preHeight, preTime。
4) multiset一定要先插入一个0，不然堆可能为空。
5) buildings排序有讲究:
    a) if two time are the same, but different time type, the starting time is ahead of ending time
    b) if two time are the same, and are both starting time, then higher building first
    c) if two time are the same, and are both ending time, then lower building first
    d) if two time are different, smaller time first

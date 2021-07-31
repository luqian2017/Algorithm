1251 · Split Array Largest Sum

Algorithms

Hard

Description

Solution

Notes

Discuss

Leaderboard

Description

Given an array which consists of non-negative integers and an integer m, we are going to split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

If `n` is the length of array, assume the following constraints are satisfied:`1 ≤ n ≤ 1000``1 ≤ m ≤ min(50, n)`https://kns.cnki.net/kns8/defaultresult/index

Example

**Example 1:**

```
Input：[7,2,5,10,8], m = 2
Output：18
Explanation：
    There are four ways to split nums into two subarrays.
    The best way is to split it into [7,2,5] and [10,8],
    where the largest sum among the two subarrays is only 18.
```

**Example 2:**

```
Input：[1,4,4], m = 3
Output：4
Explanation：
    There is a way to split nums into three subarrays.
    The best way is to split it into [1], [4] and [4],
    where the largest sum among the three subarrays is only 4.
```
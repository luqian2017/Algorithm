1707 · Knight Dialer

Algorithms

Medium

Accepted Rate44%



Description

Solution

Notes

Discuss

Leaderboard

Description

A chess knight can move as indicated in the chess diagram below:

![图片](https://media-cdn.jiuzhang.com/markdown/images/7/5/adc3f2ca-9ec9-11e9-be84-0242ac110002.jpg) ![图片](https://media-cdn.jiuzhang.com/markdown/images/7/5/abadead6-9ec9-11e9-be84-0242ac110002.jpg)

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes `N-1` hops. Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing `N` digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, **output the answer modulo 10^9 + 7**.

1 \leq N \leq 50001≤*N*≤5000

Example

**Example 1:**

```
Input: 1
Output: 10
Explanation:
The answer may be 0, 1, 2, 3, ..., 9. 
```

**Example 2:**

```
Input: 2
Output: 20
Explanation:
The answer may be 04, 06, 16, 18, 27, 29, 34, 38, 43, 49, 40, 61, 67, 60, 72, 76, 81, 83, 94, 92.
```

**Example 3:**

```
Input: 3
Output: 46
```

Tags

Company

FacebookDropboxMicrosoftGoogle
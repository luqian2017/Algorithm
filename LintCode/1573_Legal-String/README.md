1573 · Legal String

Algorithms

Medium

Accepted Rate65%



Description

Solution

Notes

Discuss

Leaderboard

Description

Given a string `S` containing only uppercase letters, insert as few `'_'` as possible in `S` so that the distance of same kind of letters no less than `k`, and if there are multiple solutions,just make the lexicographical order of the target string as small as possible. For example, given `S = ”AABACCDCD”`, `k = 3`, the target string is `“A__AB_AC__CD_CD”`. Since the length of target string may be very long, we only need to return the number of `'_'` inserted before each position of the original string. For example, the previous example returns `[0,2,0,1,0,2,0,1,0]`.
(The lexicographical order of `'_'` is greater than`'Z'`)

1<=`|S|`,`k`<=5000001<=‘∣*S*∣‘,‘*k*‘<=500000

Example

**Example 1:**

```
Given`S="AABACCDCD"`,`k = 3`,return `[0,2,0,1,0,2,0,1,0]`
Input:
3
“AABACCDCD”
Output:
[0,0,0,2,1,4,0,0]

Explanation：
The target string is "A__AB_AC__CD_CD"
```

**Example 2:**

```
Given`S = "ABBA"`,`k = 2`,return`[0,0,1,0]`
Input:
2
“ABBA”
Output:
[0,0,1,0]

Explanation：
The target string is”AB_BA”
```

Tags

Company

Facebook
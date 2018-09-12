There are two solutions:

**1) DFS + memorization**

**2) DP**

For DFS + memorization, the solution is similar to the wildcard matching.

Note:

1) We need to check p[Index + 1] instead of p[Index] as the '*' or '.' is after the character.

2) If p[pIndex + 1] is * and pIndex + 1 < p.size(), we need to check if s[sIndex] and p[pIndex] matches. If not, we have the second chance as '*' can represent zero chars.

For example, s = "abc", p = "a*abc"
s[1] and p[0..1] matches fails, but we can compare s[0] and p[2] and it passes.


3) If p[pIndex + 1] is * and pIndex + 1 = p.size(), the * reduces back to a '.' and can be treated as '.'. Thus it can be treated in the else branch.


Some important test cases:
1)
"bbbba"
".*a*a"
1464 · The K-th Combination

Algorithms

Hard

Description

Solution

Notes

Discuss

Leaderboard

Description

There are n individuals whose numbers are `1,2,3,...,n`, `n` are even numbers. Selecting half of them have `C(n, n/2)` combinations. Each combination is sorted by number from small to large, and then the sorted combination is sorted in lexicographic order. Please find the k-th combination.

1 \leq n \leq 20, 1 \leq k \leq C(n, n/2)1≤*n*≤20,1≤*k*≤*C*(*n*,*n*/2)

Example

**Example 1:**

```
Input:  n=2, k=1  
Output: [1]
Explanation:
All sorted combinations: [1],[2]
```

**Example 2:**

```
Input: n=4, k=2
Output: [1,3]
Explanation:
All sorted combinations: [1,2],[1,3],[1,4],[2,3],[2,4],[3,4]
```

Tags

Company

Facebook
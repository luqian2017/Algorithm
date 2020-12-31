### 1835. Number of Ways to Stay in the Same Place After Some Steps I

You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer still at index 00 after **exactly** steps.

Since the answer may be too large, return it **modulo** 10^9 + 7.

### Example

**Example 1:**

```
Input: 
3
2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
```

**Example 2:**

```
Input: 
2
4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
```

**Example 3:**

```
Input: 
4
2
Output: 8
```

### Notice

- 1≤*s**t**e**p**s*≤15
- 1≤*a**r**r**L**en≤106

Input test data (one parameter per line)How to understand a testcase?
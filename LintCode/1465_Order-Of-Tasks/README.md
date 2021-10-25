1465 · Order Of Tasks

Algorithms

Medium

Accepted Rate52%



![img](https://js.lintcode.com/react/assets/ade1d8c6a840a106f80c427909c31dcc.svg)



Description

Solution

Notes

Discuss

Leaderboard

Description

There are `n` different tasks, the execution time of tasks are `t[]`, and the probability of success are `p[]`. When a task is completed or all tasks fail, the operation ends. Tasks are performed in a different order, and it is expected that the time to stop the action is generally different. Please find out the order in which the tasks are performed to minimize the expected end time of actions. If the expected end time of the two task sequences is the same, the lexicographic minimum order of tasks is returned.

1 \leq n \leq 50, 1 \leq t_i \leq 10, 0 \leq p_i \leq 11≤*n*≤50,1≤*t**i*≤10,0≤*p**i*≤1n*n* is a positive integer, t_i*t**i* is a positive integer, p_i*p**i* is a floating-point number

Example

**Example 1:**

```
Input：n=1，t=[1]，p=[1.0]
Output：1
Explanation:
The shortest expected action end time is 1.0*1+(1.0-1.0)*1=1.0
```

**Example 2:**

```
Input：n=2，t=[1,2]，p=[0.3, 0.7]
Output：[2,1]
Explanation:
The shortest expected action end time is 0.7*2+(1.0-0.7)*0.3*(2+1
```
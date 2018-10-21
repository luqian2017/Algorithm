It looks like a 01 knapsack problem.
However, there is one big difference: the solution sequence matters.
For example:
Given nums = [1, 2, 4], target = 4

The possible combination ways are:
[1, 1, 1, 1]
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
[2, 2]
[4]
return 6

We can see that [1, 1, 2], [1, 2, 1] and [2, 1, 1] contribute to 3 answers. But in general 01 knapsack problem they will be considered as 1 answer.

If we use the general 01 knapsack problem, it will return 4 as it will consider [1, 1, 2], [1, 2, 1] andd [2, 1, 1] as 1 solution.

So the two loop should be in a reversed order. That is, column-first (instead of row-first which is used by general knapsack problem).
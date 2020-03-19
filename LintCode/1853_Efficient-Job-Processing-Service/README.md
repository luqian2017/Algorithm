1853. Efficient Job Processing Service

Twitter is testing a new job processing service called Pigeon.

Pigeon processes any task in double the actual duration of the task and every task has a weight. Also, Pigeon can serve only for a limited duration(maximum runtime) in an hour.

Given the maximum runtime of the Pigon service, the list of tasks with their lengths and weights, determine the maximum total weight that the Pigeon service can achieve in an hour.

The input contains these parameters:

nn: the number of tasks
weightsweights: the weight for every task
taskstasks: the actual duration of every task
pp: maximum runtime for Pigeon in an hour
Example
Example 1

Input:
4
[2,4,4,5]
[2,2,3,4]
15
Output: 10
Explanation:You can run No.0 No.1 and No.2 task. It will cost 2 * (2 + 2 + 3) = 14 minutes and get 2 + 4 + 4 = 10 weight.
Example 2

Input:
3
[3,2,2]
[3,2,2]
9
Output: 4
Explanation:You can run No.1 and No.2 task. It will cost 2 * (2 + 2) = 8 minutes and get 2 + 2 = 4 weight.
Clarification
Every task can be processed only once.

Notice
1 \leq n \leq 10^31≤n≤10
​3
​​ 
1 \leq weights[i] \leq 10^61≤weights[i]≤10
​6
​​ 
1 \leq tasks[i] \leq 1001≤tasks[i]≤100
1 \leq p \leq 10^31≤p≤10
​3
​​ 

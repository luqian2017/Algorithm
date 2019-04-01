LintCode-Logo
Home
Algorithms
AI
CATnew
VIP
Language
avatarroufoo
Back
462. Total Occurrence of Target
Description
中文
English
Given a target number and an integer array sorted in ascending order. Find the total number of occurrences of target in the array.

Have you met this question in a real interview?  
Example
Example1:

Input: [1, 3, 3, 4, 5] and target = 3, 
Output: 2.
Example2:

Input: [2, 2, 3, 4, 6] and target = 4, 
Output: 1.
Example3:

Input: [1, 2, 3, 4, 5] and target = 6, 
Output: 0.
Challenge
Time complexity in O(logn)

Related Problems
Algorithm

10 - Additional - Dynamic Programming

100%
DifficultyEasy
Total Accepted8064
Total Submitted27204
Accepted Rate29%
 Show Tags
Leaderboard - C++

fzhou
623ms

yangmetoo1983
654ms

GoldenRetriever
654ms

liuhb-a
654ms

noben
654ms
Note
九章给的solutio不是按模版写的。 要考虑边界条件： [4] 3 以及： [1,1,1,1,1,1,1,1,1,1,1] 1
avatarrong682
Created at 6 days ago
* 找到第一个等于 target 的位置 m * 找到最后一个等于 target 的位置 n * 返回 n - m + 1
avataryuqian37
Created at 11 days ago
注意不要比到index 跟 target if head or tail == -1: 是 head == -1 or tail == -1 兩次搜尋的差異是在mid == target是 要往左走還是往右走
avataryaxauw
Created at 12 days ago
Discuss
bsniaoBronze II · Last reply by · LAQ · 2 months ago
  
462. Total Occurrence of Target
中文English
Given a target number and an integer array sorted in ascending order. Find the total number of occurrences of target in the array.

Example
Example1:

Input: [1, 3, 3, 4, 5] and target = 3, 
Output: 2.
Example2:

Input: [2, 2, 3, 4, 6] and target = 4, 
Output: 1.
Example3:

Input: [1, 2, 3, 4, 5] and target = 6, 
Output: 0.
Challenge
Time complexity in O(logn)


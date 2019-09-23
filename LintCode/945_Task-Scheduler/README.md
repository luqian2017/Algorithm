945. Task Scheduler
中文English
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example
Example1

Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation:
A -> B -> idle -> A -> B -> idle -> A -> B.
Example2

Input: tasks = ['A','A','A','B','B','B'], n = 1
Output: 6
Explanation:
A -> B -> A -> B -> A -> B.
Notice
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

解法1：
以tasks="AAABBBC", n=2为例。因为每个同名task之间要隔开n，所以可以将tasks分成若干个间隔。假设最多的task有max个(这里max=3)，共有numOfMaxTask个task并列最多(这里numOfMaxTask=2，即A和B)，则共有max个间隔，其中max-1个间隔长度为n+1，还剩下最后一个间隔长度为numOfMaxTask。
即(ABC)(AB_)AB。
但要注意这仅仅是当max的长度和tasks.size()可以比拟的情况。当max的长度 << tasks.size()时，max个task可以均匀分布到tasks字符串里面。比如说tasks="AAABCDEFGQWRT", n=2，则AAA完全可以跟其他task均匀打散。
所以最后返回max(taskSize, (data[25] - 1) * (n + 1) + numOfMaxTasks);。
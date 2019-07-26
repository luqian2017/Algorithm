872. Kill Process
中文English
In this problem, each process has a unique PID (process id) and PPID (parent process id).

Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

Example
Example 1:

Input: PID = [1, 3, 10, 5], PPID = [3, 0, 5, 3], killID = 5
Output: [5, 10]
Explanation: Kill 5 will also kill 10.
     3
   /   \
  1     5
       /
      10
Example 2:

Input: PID = [1, 2, 3], PPID = [0, 1, 1], killID = 2
Output: [2]
Notice
The given kill id is guaranteed to be one of the given PIDs.
There is at least one PID in the list.

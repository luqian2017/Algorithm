1678. Train compartment problem
cat-only-icon
CAT Only
中文English
There is a railroad track and a transfer station in the middle of the railroad track. You can imagine a structure like "T". You can think of this transfer station as a stack - the carriage is FILO(first-in last-out). There are n train carriages arranged on the rails on the right side of the transfer station from 1 to n.

Now we want to transfer these n carriages to the rail on the left side of the transfer station, to be in the order of the array arr. And each carriage enters the transfer station at most once.

Your task is to determine if the order of the arr can be reached. If possible, return the number of cars in the transfer station. If not, return -1.

Example
Example 1:

Input: arr = [4,5,3,2,1]
Output: 3
Explanation: 
  1 enter the transfer station
  2 enter the transfer station
  3 enter the transfer station
  4 directly to the railroad on the left
  5 directly to the railroad on the left
  3 from the transfer station to the railroad on the left
  2 from the transfer station to the railroad on the left
  1 from the transfer station to the railroad on the left
  Therefore, [4, 5, 3, 2, 1] is legal, and the number of transfer stations which is the maximum is 3.
Example 2:

Input: arr = [3,1,2]
Output: -1
Explanation: 
  To make the first carriage is 3, we need to let 1, 2 enter the transfer station continuously.
  The transfer station is FILO, that is to say, 1 can not get the railroad on the left before 2.
Notice
n ≤ 10^5


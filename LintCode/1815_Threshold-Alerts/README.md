1815. Threhold Alerts
中文English
A smoke alarm will monitor the smoke value in len seconds. If the average smoke value is greater than k during this time, the alarm will alarm. Now, give you n numbers which represent the smoke value monitored by the alarm within n seconds (the alarm will determine whether it will alarm from the len-th second). How many times will the alarm sound during this time(1-n)?

Example
Input: n = 8, k = 4, len = 3, num = [2, 2, 2, 2, 5, 5, 5, 8].
Output: 2
Explanation: from T = 3 to T = 8, the average smoke value are 2, 2, 3, 4, 5 and 6. 5 and 6 > k, so the answer is 2.

Challenge
Time complexity O(n)

Notice
1 <= k <= n <= 100000
1 <= len <= 100000
0 <= num[i] <= 100000 (1 <= i <= n)


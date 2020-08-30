1897. Meeting Room III

you have a list intervals of current meetings, and some meeting rooms with start and end timestamp.When a stream of new meeting ask coming in, check if it can be scheduled.A meeting room can only hold one meeting at a time. Each inquiry is independent.

Example
Example 1:

Input:
Intervals:[[1,2],[4,5],[8,10]], rooms = 1, ask: [[2,3],[3,4]]
Output: [true,true]
Explanation:
For the ask of [2,3], we can arrange a meeting room room0.
The following is the meeting list of room0:
[[1,2], [2,3], [4,5], [8,10]]
For the ask of [3,4], we can arrange a meeting room room0.
The following is the meeting list of room0:
[[1,2], [3,4], [4,5], [8,10]]
Example 2:

Input:
[[1,2],[4,5],[8,10]]
1
[[4,5],[5,6]]
Output:
[false,true]
Notice
Ensure that Intervals can be arranged in rooms meeting rooms
Ensure that the end time of any meeting is not greater than 50000
|Intervals|<=50000
|ask|<=50000
rooms<=20



解法1：扫描线法
这题我开始考虑的是扫描线法，因为Meeting Room II那题就是用的扫描线法。但是做下来感觉很难。
1)首先定义pair<eventTime, eventType> eventType: 0 end, 1 start
这里把0定义成end，1定义为start，是因为想排序的时候让end的事件先结束，再考虑start的事件。不然，在这个时间点上就有2个event，不符合实际情况。注意Meeting Room II那题是把1定义成end，0定义为start，那是因为题目要求在这个时间点上算2个事件。
2)把events数组初始化后排序。
3)定义vector<int> counters(50000, -1) 是表示从0..50000每个时间点上的event数，会议开始加1，会议结束减1。注意为什么counters数组初始化为-1而不是0呢？这里我们一开始只能把events里面的时间点的events数对应上，这些时间点之间我们没有处理，所以要初始化它们为-1，跟0(事件全部结束区分开)。比如说一个会议事件是[3..5]，那么counters[3]=1，counters[4]=-1， counters[5]=0。
4) 我们根据 
if (counters[i] == -1 && counters[i - 1] > 0) counters[i] = counters[i - 1];
可以把会议的中间点的情况跟会议起始点的情况统一起来。即上面的例子counters[4]也会变成1。
5) 如果某个时间点上counters>=rooms，那么说明这个时间点上不能插入会议了，将该counter=1，否则=0。
6) 这个地方参考的网上思路：
对counter这个数组求一个前缀和。 通过前缀和sums数组我们可以发现，我们查找的l,r区间要求suml,suml+1,suml+2一直到sumr-1都为0，所以在前缀和中的表达为suml-1==sumr-1。 这样我们通过预处理，就能O(1)的处理每一个询问了。

解法2：这个是我在网上学习的。
思路跟上面差不多。不过更简单。下面的代码就直接得到了counters数组，也不用排序。
        for (int i = 0; i < intervalSize; ++i) {
            counters[intervals[i][0]]++;
            counters[intervals[i][1]]--;
            maxTime = max(maxTime, intervals[i][1]);
        }
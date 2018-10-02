There are many solutions for this problem.

Solution 1: priority queue + tuple
tuple<int, int, Interval> is for i, j and intervals[i][j]

First, push the head of each vector into pq, then push_back the top of the pq into result vector, and move the pointer of the corresponding vector. By this way, the result vector will be a sorted vector which includes all the intervals.

Second, merge the intervals in the result vector.

Solution  2: First put all the intervals into the map.
map<int, int> mp; 
key: start or end of an interval
value: if no duplicate, =1 if start and -1 if end.
++ or -- if duplicate.

Secondly, go through the map, add the mp.second to count. 
If count == 0, it means the end of an interval. Then a new interval starts.
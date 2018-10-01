There are many solutions for this problem.

Solution 1: priority queue + tuple
tuple<int, int, Interval> is for i, j and intervals[i][j]

First, push the head of each vector into pq, then push_back the top of the pq into result vector, and move the pointer of the corresponding vector. By this way, the result vector will be a sorted vector which includes all the intervals.

Second, merge the intervals in the result vector.
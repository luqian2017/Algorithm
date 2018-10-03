Solution 1:
priority_queue + tuple

For priority queue, it needs to define struct cmp and its operator() to make sure it generates min-heap, otherwise it is max-heap by default.

tuple<i,j,k> indicates k=arrays[i][j]

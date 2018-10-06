Solution 1:
DP. 
Without optimization, time complexity O(n^2).
With optimization, time complexity (O(nlogn)).

Solution 2:
Binary Search.
Use a new array B with size n + 1.
For example, A = {2,3,1}
B = {-INF, INF, INF, INF}

Go through the array A, for each element a, find the first element in B that is larger than a, and set the element as the a. For example,
B = {-INF, 2, INF, INF}
B = {-INF, 2, 3, INF}
B = {-INF, 1, 3, INF}

Then, we reverse search array B, and find the first element that is not INF - its position indicates the LIS result. In the example above, B[2] = 3, then LIS = 2.  
 
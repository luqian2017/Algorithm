1566. Minimum Difference
Given a 2D array size of n * m and the elements of each row of the array are sorted. Select 1 number from each row and select n numbers in total. And the diff of n numbers is maximum-minimum, find the minimum diff.

Example
Input: [[1,2,3,4,5],[6,7,8,9,10]]
Output: 1

//////
My solution is to use a min-Heap. 
The following link is a good reference. It is based on two sorted arrays, but the idea is similar.
https://prismoskills.appspot.com/lessons/Arrays/Find_closest_elements_in_2_arrays.jsp

1) Choose each row's first element and build a minHeap (size rRow), then each row's pointer is 1 (the column 1, as the column 0 is chosen);
2) In the while loop, 
   check the minHeap.top(), find which row it is from, then move that row's pointer to the next col. Choose the pointed node as the candidate.
   Update the maxV and minDiff.
   pop the top, and push the candidate.
   Increment count.
   If one row's element reach the row's end, exit the loop
3) return minDiff.


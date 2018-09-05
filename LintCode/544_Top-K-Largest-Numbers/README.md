There are two solutions:
1) Use the min-heap. The total time complexity is O(nlogk).

2) Use QuickSelect algorithm to find the Kth largest element, then go through the vector to find the k elements that are larger or equal to the element (but in my opinion, we need to  resize the result vector to k as there may be duplicate elements in the result vector). 
The total time complexity is O(n). It is because the QuickSelect algorithm only takes O(n). In contract, the QuickSort takes O(nlogn).
Two solutions:

**1. Quick Select**
 
Borrwoed the idea from Quick Sort. Each time choose a pivot (it can be in the middle, or on either side). Then the array can be divided into 3 parts: **left side is less or equal to pivot, right side is larger or equal to pivot, the middle part is jut pivot.**

case 1: **compare start+k-1 and j**. If start+k-1<=j, it shows the kth largest element is in the left part. So why not comparing start+k and j? Consider the extreme case: if k=1, start=j, in such case we also need to search from the left side, so start+k<=j is incorrect.

case 2: compare start+k-1 and i.  If start+k-1>=i, it shows the kth largest element is in the right part. We need to reduce k to k-(i-start), as we don't need to care about the left part and middle part.

Case 3: If both case 1 and case 2 do not meet, we return pivot, which is nums[j+1].


**2. Max Heap**

Try next time.
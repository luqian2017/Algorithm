In the recursion, it needs to return both sum and node*.
One way is to put both in a structure or class.

Note: if a node's left child or right child is null, we cannot directly use 
 minChildSum = min(sumLeft, sumRight) as the null's sum is 0, which is the smaller one.

Useful test cases:
   input = {1,#,2}。

There is another beautiful version I found online. See v2.cpp.



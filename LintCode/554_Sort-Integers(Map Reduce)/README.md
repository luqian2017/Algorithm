554. Sort Integers (Map Reduce)

Sort integers by Map Reduce framework.
In the mapper, key is the document id which can be ignored, value is the integers.

In the reducer, your can specify what the key / value is (this depends on how you implement your mapper class). For the output of the reducer class, the key can be anything you want, the value should be ordered. (the order is depending on when you output it)

Example
Example 1:

Input:
1: [14,7,9]
2: [10,1]
3: [2,5,6,3]
4: []
Output:
[1,2,3,5,6,7,9,10,14]

Example 2:

Input:
1: [14,7]
Output:
[7,14]

v
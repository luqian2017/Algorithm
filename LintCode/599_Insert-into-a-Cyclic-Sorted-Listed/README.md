599. Insert into a Cyclic Sorted List
Given a node from a cyclic linked list which has been sorted, write a function to insert a value into the list such that it remains a cyclic sorted list. The given node can be any single node in the list. Return the inserted new node.

Example
Given a list, and insert a value 4:
3->5->1
Return 5->1->3->4

Notice
3->5->1 is a cyclic list, so 3 is next node of 1.
3->5->1 is same with 5->1->3

Solution:
Note the following cases:
1) 10->1->2->4   10
2) 10->1->2->4->4->10->10
3) null 1
4) 10 1
5) 2->2->2 3
6) 3->5->1->2 7
7) 3->5->2->3 1
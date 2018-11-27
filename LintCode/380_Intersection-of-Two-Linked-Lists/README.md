380. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

Example
The following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Solution 1:
First make List A a circular list.
Then let node1 = headB, node2 = headB->next. node1 moves 1 step each time, and node 2 moves 2 steps each time. Find the meet node. If they do not meet, then return NULL.
Let node1 = meetnode->next, node2 = headB. Let them start the move, each time one step each, until they meet. The meeting place is the converge point. 

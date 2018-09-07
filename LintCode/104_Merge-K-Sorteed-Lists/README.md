There are three solutions:
1) Each list has a pointer. Each time go through all the pointers, compare the value of the elements that the pointers points to, choose the minimum element and the corresponding pointer moves by one. The process continues until all the pointers move to the end of the list.

Disadvantage: too slow. Time complexity is O(k*N) where N is the number of all the elements in all the lists.
363. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Trapping Rain Water

Example
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Challenge
O(n) time and O(1) memory

O(n) time and O(n) memory is also acceptable.

Solution 1.
Find the maxHeight and maxIndex first.
Then calculate the left side and right side respectively.
For left side, calculate the gap of the current maxheight and the current height, adds it into sum.
For right side, calculate the gap of the current maxheight and the current height, adds it into sum.

1138. Can Place Flowers
Suppose you have a long flowerbed in which some of the pots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example
Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Notice
1.The input array won't violate no-adjacent-flowers rule.
2.The input array size is in the range of [1, 20000].
3.n is a non-negative integer which won't exceed the input array size.

Solution:
We can find the rules:
1_1   gap = 1 -> 0 tree
1__1  gap = 2 -> 0 tree
1___1 gap = 3 -> 1 tree
1____1 gap = 4 -> 1 tree
1_____1 gap = 5 -> 2 trees
1______1 gap = 6 -> 2 trees
1_______1 gap = 7 -> 3 trees
1________1 gap = 8 - 3 trees

so we can tell that, for the gap between 1s, the # of trees = (gap + 1) / 2 - 1.
Use two pointers p1 and p2 to travere through the vectors and record the new 1 and old 1's place. gap = p2 - p1 -1.
p1 is initialzed as -1, and p2 is initialized as 0.
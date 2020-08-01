1444. Dyeing Problem

There is a circle, divided into n sectors. All the sectors are colored with some of m colors. The colors of adjacent sectors cannot be the same. Find the total number of plans.

Example
Example 1:

Input:n = 2,m = 3
Output:6
Explanation:One circle is divided into two sectors. There are six kinds of schemes for coloring in three colors: black, red, black and white, white and red, white and black, red and white, and red and black.
Example 2:

Input:n = 3,m = 2
Output:0
Explanation:A circle is divided into 3 sectors and colored with 2 colors. No matter how it is colored, there is no guarantee that the adjacent colors are different.          
Notice
Do not consider symmetry.
Since this number may be large, you only need to return the solution number mod 1e9 + 7.
1 \leq n \leq 10^5
​1 \leq m \leq 10^5
​​

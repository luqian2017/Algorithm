280. Closest City

There are many cities on a two-dimensional plane, all cities have their own names c[i]c[i], and location coordinates (x[i],y[i])(x[i],y[i]) (both are integers). There are qq group queries, and each group query gives a city name. You need to answer the city name that is the closest to the city and has the same xx or yy.

Example
Example 1：

Input: x = [3, 2, 1] y = [3, 2, 3] c = ["c1", "c2", "c3"] q = ["c1", "c2", "c3"]
Output: ["c3", "NONE", "c1"]
Explanation: For c1, c3 is the same as its y, the closest distance is (3-1)+(3-3)=2
For c2, no city is the same as its x or y
For c3, c1 is the same as his y, the closest distance is (3-1)+(3-3)=2
Notice
If there are multiple answers that satisfy the conditions, the one with the smallest lexicographic name is output.

The distance here is the Euler distance: the absolute value of the coordinate difference of xx plus the absolute value of the coordinate difference of yy.

0 ≤ Number of cities ≤ 10^5, 
0 ≤ Ask for the number of groups ≤ 10, 
1 ≤ Coordinate range 10^9
​​ 


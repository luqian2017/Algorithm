516. Paint House II

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Example
Example 1

Input:
costs = [[14,2,11],[11,14,5],[14,3,10]]
Output: 10
Explanation:
The three house use color [1,2,1] for each house. The total cost is 10.
Example 2

Input:
costs = [[5]]
Output: 5
Explanation:
There is only one color and one house.
Challenge
Could you solve it in O(nk)?

Notice
All costs are positive integers.

解法1：DP。第3层循环遍历colors，在跟当前color不同的color中找最小值。时间复杂度O(n^3)和空间复杂度O(n^2)都太高。
解法2：改进版。只需保存前次节点的最小值和第二小的值和其对应的colors即可，如果当前color和前次节点的最小值对应的color一样，则取前次节点的第二小的值，否则取前次节点的最小值。
时间复杂度O(n^2)，空间复杂度还是O(n^2)。
解法3：类似解法2，但不用二维数组了，因为只需要保存前次节点的4个值即可(min1_id, min2_id, min1_v, min2_v)。
时间复杂度O(n^2)，空间复杂度O(1)。
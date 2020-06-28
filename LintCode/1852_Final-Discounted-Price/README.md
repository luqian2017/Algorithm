


1852. Final Discounted Price
中文English
A shopkeeper has a sale to complete and has arranged the items being sold in an array. Starting from the left, the shopkeeper rings up each item at its full price less the price of the first lower or equal priced item to its right. If there is no item to the right that costs less than or equal to the current item's price, the current item is sold at full price.You should return the actual selling price of each item.

Example
Example 1:
Input:
Prices = [2, 3, 1, 2, 4, 2]
Output: [1, 2, 1, 0, 2, 2]
Explanation: The item 0 and 1 are each discounted by 1 unit, The item 3 at 2 units, is discounted 2 units, as would the item 4 at 4 units. 
Example 2:
Input:
Prices = [1, 2, 3, 4, 5]
Output: [1, 2, 3, 4, 5]
Explanation: each item should keep full price beacause there are not equal or lower priced items to the right
Notice
The length of Prices is within range: [1, 100000]
Prices[i] is within range: [1, 1000000]

解法1：单调栈。
1）注意是单调递增栈(即从栈底到栈底单调不递减）
2）stack里面存储的是index，不是实际值。

以input={2,3,1,2,4,2}为例，result一开始初始化为input的值{2,3,1,2,4,2}。
i=0, stack={2}   //start from bottom
i=1, stack={2,3}
i=2, stack={1} //因为1<3, 1<2, 所以3和2都pop，result[0]和result[1]对应的值(2和3)都减去result[2](=1)。
i=3, stack={1,2}
i=4, stack={1,2,4}
i=5, stack={1,2} //因为2<4, 2<=2, 所以4 和 2 都pop, result[3]和result[4]对应的值(2和4)减去result[5](=2)。

所以最后result={1,2,1,0,2,2}。
总结：
求最右边第一个大于等于某元素的值用单调递减栈。
求最右边第一个小于等于某元素的值用单调递增栈。


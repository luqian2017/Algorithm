801. Backpack X
You have a total of n yuan. Merchant has three merchandises and their prices are 150 yuan, 250 yuan and 350 yuan. And the number of these merchandises can be considered as infinite. After the purchase of goods need to be the remaining money to the businessman as a tip, finding the minimum tip for the merchant.

Example
Example 1:

Input: n = 900
Output: 0
Example 2:

Input: n = 800
Output: 0

经典的完全背包例题。
解法1：最朴素的2维数组
注意：完全背包和01背包都只需要2重循环，优化也只是空间优化而已。
多重背包需要3重循环(不管优不优化)，优化也只是空间优化。

解法2：
空间优化后2层循环，一重数组。

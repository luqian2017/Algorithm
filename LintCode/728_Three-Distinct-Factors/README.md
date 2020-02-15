728. Three Distinct Factors

Given a positive integer n (1 <= n <= 10^18). Check whether a number has exactly three distinct factors, return true if it has exactly three distinct factors, otherwise false.

Example
Example1

Input: n = 9
Output: true
Explanation:
Number 9 has exactly three factors: 1, 3, 9, so return true.
Example2

Input: n = 10
Output: false
Explanation:
Number 10 has four factors: 1, 2, 5, 10, so return false.

解法1：
注意满足3个因子的数一定是1 X sqrt X sqrt=N。其中sqrt必须是质数。
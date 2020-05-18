739. 24 Game

You have 4 cards each containing a number from 1 to 9. You need to compute whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example
Example 1:

Input：[1, 4, 8, 7]
Output：true
Explanation：8 * （7 - 4） * 1 = 24
Example 2:

Input：[1, 1, 1, 2]
Output：false
Explanation：no way to get 24
Example 3:

Input：[3, 3, 8, 8]
Output：true
Explanation：8 / ( 3 - 8 / 3) = 24
Notice
The division operator / represents real division, not integer division. so 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.

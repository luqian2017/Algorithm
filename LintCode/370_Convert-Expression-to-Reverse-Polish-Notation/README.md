370. Convert Expression to Reverse Polish Notation
中文English
Given a string array representing an expression, and return the Reverse Polish notation of this expression. (remove the parentheses)

Example
Example 1:

Input: ["3", "-", "4", "+", "5"]
Output: ["3", "4", "-", "5", "+"]
Explanation: 3 - 4 + 5 = -1 + 5 = 4
    3 4 - 5 + = -1 5 + = 4
Example 2:

Input: ["(", "5", "-", "6", ")", "*", "7"]
Output: ["5","6","-","7","*"]
Explanation: (5 - 6) * 7 = -1 * 7 = -7
    5 6 - 7 * = -1 7 * = -7
Clarification
Definition of Reverse Polish Notation:

https://en.wikipedia.org/wiki/Reverse_Polish_notation
https://baike.baidu.com/item/逆波兰表达式/9841727?fr=aladdin

My Note:
Input:
["(","3","-","2",")","*","7"]
Output:
["3","2","-","7","*"]

Input:
["3","-","2","*","7"]
Output:
["3","2","7","*","-"]
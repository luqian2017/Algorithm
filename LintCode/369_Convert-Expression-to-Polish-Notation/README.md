369. Convert Expression to Polish Notation
中文English
Given a string array representing an expression, and return the Polish notation of this expression. (remove the parentheses)

Example
Example 1:

Input: ["(", "5", "-", "6", ")", "*", "7"]
Output: ["*", "-", "5", "6", "7"]
Explanation: (5 - 6) * 7 = -1 * 7 = -7
    * - 5 6 7 = * -1 7 = -7
Example 2:

Input: ["3", "+", "(", "1", "-", "2", ")"]
Output:["+", "3", "-", "1", "2"] 
Explanation: 3 + (1 - 2) = 3 + -1 = 2
    + 3 - 1 2 = + 3 -1 = 2
Clarification
Definition of Polish Notation:

http://en.wikipedia.org/wiki/Polish_notation
http://baike.baidu.com/view/7857952.htm

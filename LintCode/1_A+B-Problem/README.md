1. A + B Problem
中文English
Write a function that add two numbers A and B.

Example
Example 1:

Input:  a = 1, b = 2
Output: 3	
Explanation: return the result of a + b.
Example 2:

Input:  a = -1, b = 1
Output: 0	
Explanation: return the result of a + b.
Challenge
Of course you can just return a + b to get accepted. But Can you challenge not do it like that?(You should not use + or any arithmetic operators.)

Clarification
Are a and b both 32-bit integers?

Yes.
Can I use bit operation?

Sure you can.
Notice
There is no need to read data from standard input stream. Both parameters are given in function aplusb, you job is to calculate the sum and return it.

///////////

Typical bit operation problem.

a ^ b is no-carrier addition (that is, a ^ b is the result of a plus b without carrier operation)
a & b is the a and b's 1's operation.


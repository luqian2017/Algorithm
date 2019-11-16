419. Roman to Integer
中文English
Given a roman numeral, convert it to an integer.

The answer is guaranteed to be within the range from 1 to 3999.

Example
Example 1:

Input: "IV"
Output: 4
Example 2:

Input: "XCIX"
Output: 99
Clarification
What is Roman Numeral?

https://en.wikipedia.org/wiki/Roman_numerals
https://zh.wikipedia.org/wiki/罗马数字
http://baike.baidu.com/view/42061.htm

解法1：基于map。
注意Roman to Integer和Integer to Roman都maintain两个数组Roman[]和value[]。
Integer to Roman: go through the Roman table (0..13)即可
Roman to Integer: go through the string，每次看两个，不match就看一个。
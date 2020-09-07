1856. Sub-palindrome

Twitter users love word play. Imagine a Twitter feature that finds palindromes in tweets!

A palindrome is a string that reads the same forward and backward, e.g. 121 or tacocat. A substring is a contiguous subset of characters in a string. Given a string s, how many distinct substrings of s are palindromes?

For example, s = mokkori. Some of its substrings are [m,o,k,r,i,mo,ok,mok,okk,kk,okko].Each of the bold elements is a palindromic substring of s. In total, there are 7 distinct palindromes.

Example
Example 1:
Input: str = "abaaa"
Output:  5
Explanation:Below are 5 palindrome sub-strings
a
aa
aaa
aba
b
Example 2:
Input: str = "geek"
Output:  4
Explanation:Below are 4 palindrome sub-strings
e
ee
g
k
Notice
1 ≤ |s| ≤ 5000
Each character s[i] ∈ ascii[a-z]

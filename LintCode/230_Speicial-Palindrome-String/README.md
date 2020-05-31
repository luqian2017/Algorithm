250. Special Palindrome String

You have a list of paired ambigram letter, like a<->t, b<->y, y<->h, h<->n, m<->w, w<->w …
Given a string, return true if it is a palindrome string which letters in it can be replaced by another corresponding letters. Attentionally, nested replacement is not be allowed, which means a<-->b, b<-->c, but a<-/->c.

For example, the string "swims" is true because "w" can be replaced by "m" and the string changes to "smims" which is palindrome.
the string "hob" is also true because "h" can be replaced by "y" and "b" can be replaced to "y" too. Then the string is "yoy" which is palindrome.
However, the string "ban" is false because nested replacement is not be allowed. Even "b" can just change to "y" and "n" can just change to "h" , the new string "yah" isn't palindrome.

Example
Example 1:
Input: ambigram=["at", "by", "yh", "hn", "mw", "ww"], word="swims"
Output: true
Explanation: "w" can be replaced by "m" and the string changes to "smims" which is palindrome, so it is true.

Example 2:
Input: ambigram=["at", "by", "yh", "hn", "mw", "ww"], word="hob"
Output: true
Explanation: "h" can be replaced by "y" and "b" can be replaced to "y" too. Then the string is "yoy" which is palindrome, so it is true.

Example 3:
Input: ambigram=["at", "by", "yh", "hn", "mw", "ww"], word="ban"
Output: false
Explanation: Nested replacement is not be allowed. Even "b" can just change to "y" and "n" can just change to "h" , the new string "yah" isn't palindrome.

Notice
Each digit of list ambigram is 2 letters, indicating that it can be converted from one to the other.
The length of list ambigram does not exceed 10,000
The length of the string word does not exceed 1,000
All data are guaranteed to be lowercase.


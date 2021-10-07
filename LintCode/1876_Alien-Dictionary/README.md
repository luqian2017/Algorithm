1876 · Alien Dictionary(easy)

Algorithms

Easy

Accepted Rate53%



![img](https://js.lintcode.com/react/assets/ade1d8c6a840a106f80c427909c31dcc.svg)



Description

Solution

Notes

Discuss

Leaderboard

Description

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.Otherwise, it returns false.

1 <= words.length <= 1001 <= words[i].length <= 20order.length == 26All characters in words[i] and order are English lowercase letters.

Example

**Example 1:**

```
Input: 
words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: 
true
Explanation: 
As 'h' comes before 'l' in this language, then the sequence is sorted.
```

**Example 2:**

```
Input: 
words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: 
false
Explanation: 
As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
```

**Example 3:**

```
Input: 
words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: 
false
Explanation: 
The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
```

Tags

Company

Facebook
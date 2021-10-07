1592 · Find and Replace Pattern

Algorithms

Medium

Accepted Rate82%



![img](https://js.lintcode.com/react/assets/ade1d8c6a840a106f80c427909c31dcc.svg)



Description

Solution

Notes

Discuss

Leaderboard

Description

You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern.

You may return the answer in any order.

1 <= words.length <= 501<=*w**or**d**s*.*l**e**n**g**t**h*<=501 <= pattern.length = words[i].length <= 201<=*p**a**tt**er**n*.*l**e**n**g**t**h*=*w**or**d**s*[*i*].*l**e**n**g**t**h*<=20

Example

**Example 1:**

```
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["aqq","mee"]
Explanation: 
"mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
```

**Example 2:**

```
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
Explanation: 
All strings match.
```

Tags

Company

GoogleGoldman SachsAmazon
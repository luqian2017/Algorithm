683 · Word Break III

Algorithms

Medium

Accepted Rate44%



![img](https://js.lintcode.com/react/assets/ade1d8c6a840a106f80c427909c31dcc.svg)



Description

Solution

Notes

Discuss

Leaderboard

Description

Give a dictionary of words and a sentence with all whitespace removed, return the number of sentences you can form by inserting whitespaces to the sentence so that each word can be found in the dictionary.

Ignore case

Example

**Example1**

```
Input:
"CatMat"
["Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"]
Output: 3
Explanation:
we can form 3 sentences, as follows:
"CatMat" = "Cat" + "Mat"
"CatMat" = "Ca" + "tM" + "at"
"CatMat" = "C" + "at" + "Mat"
```

**Example1**

```
Input:
"a"
[]
Output: 
0
```
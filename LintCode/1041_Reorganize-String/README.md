
1041. Reorganize String
中文English
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result. If not possible, return the empty string.

Example
Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Notice
S will consist of lowercase letters and have length in range [1, 500].

解法1:
Find the most frequent character, if the frequency > n / 2, return empty string.
Otherwise, put the other characters into the string by mixing them without adjacent same characters.
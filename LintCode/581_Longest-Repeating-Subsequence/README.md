581. Longest Repeating Subsequence

Given a string, find length of the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any ith character in the two subsequences shouldn’t have the same index in the original string.

Example
Example 1:

Input:"aab"
Output:1
Explanation:
The two subsequence are a(first) and a(second). 
Note that b cannot be considered as part of subsequence as it would be at same index in both.
Example 2:

Input:"abc"
Output:0
Explanation:
There is no repeating subsequence

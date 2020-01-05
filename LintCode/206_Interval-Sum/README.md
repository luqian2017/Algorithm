206. Interval Sum

Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. Each query has two integers [start, end]. For each query, calculate the sum number between index start and end in the given array, return the result list.

Example
Example 1:

Input: array = [1,2,7,8,5],  queries = [(0,4),(1,2),(2,4)]
Output: [23,9,20]
Example 2:

Input: array : [4,3,1,2],  queries : [(1,2),(0,2)]
Output: [4,8]
Challenge
O(logN) time for each query

Notice
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.

解法1: Binary Index Tree

解法2: Segment Tree
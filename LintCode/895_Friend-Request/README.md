895. Friend Request

Given an array Ages of length n, where the first i elements represent the age of the individual i. Find total number of friend requests sent by this n person. There are some requirements:

if Age(B) <= (1/2)Age(A) + 7, A will not send a request to B.
if Age(B) > Age(A), A will not send a request to B.
if Age(B) < 100 and Age(A) > 100, A will not send a request to B.
If it does not satisfy 1,2,3, then A will send a request to B
Example
Example1

Input: Ages = [10,39,50]
Output: 1
Explanation:
Only people of age 50 will send friend requests to people of age 39.
Example2

Input: Ages = [101,79,102]
Output: 1
Explanation:
Only people of age 102 will send friend requests to people of age 101.
Notice
Ages.length <= 1000。
Everyone's age is greater than 0, no larger than 150。

1112. Set Mismatch
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example
Input: nums = [1,2,2,4]
Output: [2,3]
Notice
1.The given array size will in the range [2, 10000].
2.The given array's numbers won't have any order.

Solution:
First sorting numsp[], then find if nums[i - 1] == nums[i], then nums[i] is the error number in nums[]. 
Then using XOR to get all the XOR result for the nums[] and [1 .. n], then XOR the error number again. The final XOR result is the error number in [1 .. n].
Good input case: [3,2,3,4,6,5].
The error number in nums[] is 3.
The error number in [1..6] is 1.
It is easy to find the error number in nums[] is 3.
How to get 1? 3^2^3^4^6^5 ^ 1^2^3^4^5^6 ^ 3 = 1.
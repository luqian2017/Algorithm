379. Reorder array to construct the minimum number
Construct minimum number by reordering a given non-negative integer array. Arrange them such that they form the minimum number.

Example
Example 1:

Input:[2,1]
Output:[1,2]
 Explanation: there are 2 possible numbers can be constructed by reordering the array:
          1+2=12
          2+1=21
So after reordering, the minimum number is 12, and return it.
Example 2:

Input:[3, 32, 321]
Output:[321, 32, 3]
 Explanation: there are 6 possible numbers can be constructed by reordering the array:
	3+32+321=332321
	3+321+32=332132
	32+3+321=323321
	32+321+3=323213
	321+3+32=321332
	321+32+3=321323
So after reordering, the minimum number is 321323, and return it.
Challenge
Do it in O(nlogn) time complexity.

Notice
The result may be very large, so you need to return a string instead of an integer.

解法1：贪心法。记得按字典顺序排序的cmp技巧是比较a+b vs b+a。
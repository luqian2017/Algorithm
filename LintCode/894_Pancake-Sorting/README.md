894. Pancake Sorting
中文English
Given an unsorted array, sort the given array. You are allowed to do only following operation on array.

flip(arr, i): Reverse array from 0 to i 
Unlike a traditional sorting algorithm, which attempts to sort with the fewest comparisons possible, the goal is to sort the sequence in as few reversals as possible.

Example
Example 1:
	Input: array = [6,11,10,12,7,23,20]

Example 2:
	Input: array = [4, 2, 3]

	Explanation:
	flip(array, 2)
	flip(array, 1)
	
Notice
You only call flip function.
Don't allow to use any sort function or other sort methods.

Java：you can call FlipTool.flip(arr, i)
C++： you can call FlipTool::flip(arr, i)
Python2&3 you can call FlipTool.flip(arr, i)


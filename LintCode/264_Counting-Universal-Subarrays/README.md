264. Counting Universal Subarrays

You will be given an array comprised of '2's or '4's. A subarray (A subarray is a group of contiguous elements in an array and cannot be empty) of such an array is called " universal" if it matches the following conditions:

The 2's and 4's are grouped consecutively (e.g., [4, 2],[2, 4],[4, 4, 2, 2],[2, 2, 4, 4],[4, 4, 4, 2, 2, 2], etc.).
The number of 4's in the subarray is equal to the number of 2's in the subarray.
Subarrays with the same element but different positions are treated differently. For example, there are two [4, 2] subarrays in array[4, 2, 4, 2].
You need to return an integer value, the number of "universal" subarrays in a given array.

Example
Sample 1:
Input sample: array = [4, 4, 2, 2, 4, 2]
Output sample: 4
Sample explanation: The 4 subarrays that match these two criteria are: [4, 4, 2, 2]，[4,2]，[2,4]，[4,2]. Note that there are two subarrays [4,2], in indexes 1-2 and 4-5, respectively.

Sample 2:
Input sample: array = [4, 4]
Output sample: 0
Sample explanation: the given array does not have 2, certainly cannot satisfy the condition two, so the result is 0.

Notice
1 ≤ |array| ≤ 10^5
array[i] ∈ (2, 4)


1859. Minimum Amplitude
Given an array A consisting of N integers. In one move, we can choose any element in this array and replace it with any value.
The amplitude of an array is the difference between the largest and the smallest values it contains.
Return the smallest amplitude of array A that we can achieve by performing at most three moves

Example
Example 1
Input:
A = [-9, 8, -1]
Output: 0
Explanation: We can replace -9 and 8 with -1 so that all element are equal to -1, and then the amplitude is 0
Example 2:
Input:
A = [14, 10, 5, 1, 0]
Output: 1
Explanation: To achieve an amplitude of 1, we can replace 14, 10 and 5 with 1 or 0.
Example 3:
Input:
A = [11, 0, -6, -1, -3, 5]
Output: 3
Explanation: This can be achieved by replacing 11, -6 and 5 with three values of -2.
Notice
N is an integer within the range: [2, 10000]
each element of array A is an integer within the range: [-50, 50]
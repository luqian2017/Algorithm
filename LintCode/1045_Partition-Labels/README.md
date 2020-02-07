1045. Partition Labels

A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example
Example 1:
	Input:  S = "ababcbacadefegdehijhklij"
	Output:  [9,7,8]
	
	Explanation:
	The partitions are "ababcbaca", "defegde", "hijhklij".
	A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
	
Example 2:
	Input: S = "abcab"
	Output:  [5]
	
	Explanation:
	We can not split it. 
	
Notice
1.S will have length in range [1, 500].
2.S will consist of lowercase letters ('a' to 'z') only.


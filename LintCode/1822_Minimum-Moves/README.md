1822. Minimum Moves

Given a string S consisting of N letters 'a' and / or 'b'. In one move, you can swap one letter for the other ('a' for 'b' or 'b' for 'a'). You should return the minimum number of moves required to obtain a string containing no instances of three identical consecutive letters.

Example
Example1:
Input:
S = "baaaaa"
Output: 1
Explanation: The string S without three identical consecutive letters which can be obtained in one move is "baabaa".
Example2:
Input:
S = "baaabbaabbba"
Output: 2
Explanation: There are four valid strings obtainable in two moves: for example: "bbaabbaabbaa"
Example3:
Input:
S="baabab"
Output: 0
Notice
N is an integer within the range: [0, 2000000]
string S consists only of the characters 'a' and/or 'b'

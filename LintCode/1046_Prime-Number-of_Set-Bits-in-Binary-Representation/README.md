LintCode-Logo
Home
Algorithms
AI
CATnew
VIP
Language
avatarroufoo
Back
1046. Prime Number of Set Bits in Binary Representation
Description
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

1.L, R will be integers L <= R in the range [1, 10^6].
2.R - L will be at most 10000.

Have you met this question in a real interview?  
Example
Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Related Problems
Amazon

1 - Easy

90%
DifficultyEasy
Total Accepted748
Total Submitted1166
Accepted Rate64%
 Show Tags
 Company
Leaderboard - C++

Sunday
8ms

ziken.neo
9ms

Pingle
12ms

nihaohai
50ms

silenceofthecode
50ms
Note
08/23 这个题的关键是算二进制数有几个1 这种方法速度比较快，其运算次数与输入n的大小无关，只与n中1的个数有关。如果n的二进制表示中有k个1，那么这个方法只需要循环k次即可。其原理是不断清除n的二进制表示中最右边的1，同时累加计数器，直至n为0，
xxm555
Created at 4 months ago
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-762-prime-number-of-set-bits-in-binary-representation/ 很好的视频 要点： 1. Integer.bitCount() 2. 用binary做一个mask，用数组做一个mask，比用HashSet好。 https://leetcode.com/articles/prime-number-of-set-bits-in-binary-representation/ 挺巧的做法，注意分析题目给的条件。 最常规的做法。 loop through all number, see if it has prime set bits. public int countPrimeSetBits(int L, int R) { int cnt = 0; for (int n = L; n <= R; n++) { if (isPrime(getSetBitsCount(n))) { cnt++; } } return cnt; } private int getSetBitsCount(int n) { int cnt = 0; while (n > 0) { cnt += n % 2; n = n / 2; } return cnt; } private boolean isPrime(int n) { // 小于等于1 if (n <= 1) { return false; } // 2, 3, 4... for (int i = 2; i <= Math.sqrt(n); i++) { if (n % i == 0) { return false; } } return true; }
ZZ1
Created at 5 months ago
Discuss
No topic

  
1046. Prime Number of Set Bits in Binary Representation
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example
Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Notice
1.L, R will be integers L <= R in the range [1, 10^6].
2.R - L will be at most 10000.
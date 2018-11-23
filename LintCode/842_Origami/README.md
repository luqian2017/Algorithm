842. Origami
Origami, each time the paper is folded from right to left, the dent is 0, the bump is 1. After the n number of folds, find the 01 sequence of the creases formed with the paper unrolling.

Example
Given n = 1, return "0".

Explanation:
the 01 sequence of the creases is "0".
Given n = 2, return "001".

Explanation:
the 01 sequence of the creases is "001".
Notice
1 <= n <= 20

Solution:
We can see the rule:
#1: 0
#2: 001
#3: 0010011
#4: 001001100011011

so let the ith fold result be s, then the i+1th fold result is s + '0' + s.reverse().flip().

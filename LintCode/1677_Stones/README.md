1677. Stones
cat-only-icon
CAT Only
中文English
Given array p representing position of n stones, and array d representing distance that can be thrown.

Go from left (0 position) to right. When you encounter a stone for the kth time, throw it to right if k is odd, or skip it if k is even.

Return the position of the rightmost stone when you will not encounter a stone any more.

Example
Example 1:

Input: p = [1, 2], d = [5, 4]
Output: 11
Explanation: 
  First, the stone on the position 1 was thrown to 6.
  Then skip the stone on the position 2.
  Next the stone on the position 6 was thrown to 11.
  Last skip the stone on the position 11.
Example 2:

Input: p = [1, 6], d = [5, 6]
Output: 12
Explanation: 
  First, the stone on the position 1 was thrown to 6.
  Then skip the stone on the position 6 (the larger one).
  Next the stone on the position 6 was thrown to 12.
  Last skip the stone on the position 12.
Notice
n <= 10^4
p[i] <= 10^5
d[i] <= 10^3
If two or more stones stay at the same position, you will meet the largest one (the one with the smallest d[i]) first. Means throwing or skipping larger stones first.

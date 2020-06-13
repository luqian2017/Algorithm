253. Minimum Type Way

You are given a string only contains lower or upper English characters that you want to type.
At the beginning, the Capslock is off, it's at a state of lower characters, you are required that after typing it should still be at lower state.
There are three kinds operations:

Type a character, the screen will print a character at corresponding state (lower or upper). You hit the keyboard once.
Press Capslock, switch the state of the keyboard. You hit the keyboard once.
Press Shift with some character, the screen will print a character at a opposite state. You hit the keyboard twice. e.g. It will print 'P' when you press Shift + 'p'.
Example
Input:
"Hello"
Output:
6
Clarification
The type steps：Shift + 'h', 'e', 'l', 'l', 'o'.

Notice
The length of the string is N, 1≤N≤10^5

解法1：
这题想了好久。我开始的解法不对。参考的别人的思路。

这题难在有几种组合混在一起。对于每个字母，无论大写或小写，都可以通过按CAP键与否和按SHIFT键与否来实现。这种情况可以通过DP来解决，保证不会遗漏中间的情况。

双序列DP: upper[i]表示当前为第i个字符，CAP键按下时所需的最少按键，lower[i]表示当前为第i个字符，CAP键未按下时所需的最少按键。那么，

当第i个字符为大写字母时:
upper[i]如果由upper[i-1]来实现，其值直接加1即可。因为CAP键已经按下，不需再按SHIFT键，
upper[i]如果由lower[i-1]来实现，其值必须加2。因为CAP键未按下，必须要按下CAP键，再敲第i个字符。
lower[i]如果由upper[i-1]来实现，其值必须加2。因为CAP键已经按下，必须要再按CAP键消掉大写功能，再直接敲第i个字符。
lower[i]如果由lower[i-1]来实现，其值必须加2。因为CAP键未按下，必须要按SHIFT键来实现大写。

当第i个字符为小写字母时:
upper[i]如果由upper[i-1]来实现，其值必须加2。因为CAP键已经按下，必须再按SHIFT键来实现小写。
upper[i]如果由lower[i-1]来实现，其值必须加2。因为CAP键未按下，必须要按下CAP键，再敲第i个字符。
lower[i]如果由upper[i-1]来实现，其值必须加2。因为CAP键已经按下，必须要再按CAP键消掉大写功能，再直接敲第i个字符。
lower[i]如果由lower[i-1]来实现，其值直接加1即可。因为CAP键未按下，也不需要按SHIFT键就可以实现小写。
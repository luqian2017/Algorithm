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
The length of the string is NN, 1 \le N \le 10^51≤N≤10
​5
​​ .


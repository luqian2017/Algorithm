193. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example
Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

解法1：stack
这题比单纯判断字符串是否合法要复杂一些。一开始我的思路就是遇到'(’就压栈，遇到')'就出栈，同时count+2。但看看input=")(()(()"就知道了，这个方法会返回4(因为遇到2个())，但实际答案为2，因为这2个()没有连在一起。
参考了网上的答案。这题要注意记录一个合法序列开始时候的position!
1) 当遇到'('时，压栈;
2) 当遇到')'时，
2.1) 如果栈为空，那么说明此时input已经不合法了，startPos从下一个位子开始算。
2.2) 如果栈非空，那么st.pop()。
若此时栈空了，说明此时从上个startPos到现在都合法，记录maxCount=max(maxCount, i - startPos + 1)。
若此时栈仍然为非空，说明从st.top()的下一个位置开始到i都合法，记录maxCount=max(maxCount, i - st.top())。//i-st.top()即i-(st.top()+1)+1
注意这里一定要用i-st.top()而不是i-st.old_top + 1。//old_top即st.pop()出来的那个位置。
比如说input = ")(()()()"，那么最后i=7，st.pop()，stack仍然非空，st.top()=1，说明从i=2的位置就开始合法了，maxCount=i-1=6，即”()()()“的长度。
如果我们用i-st.old_top()+1=7-6+1=2就不对了，此时只记录了最后一个()的长度。

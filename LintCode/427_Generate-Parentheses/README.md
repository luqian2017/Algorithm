427. Generate Parentheses

Given n, and there are n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example
Example 1:

Input: 3
Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]
Example 2:

Input: 2
Output: ["()()", "(())"]

解法1：感觉这题其实不容易，关键是要做到不TLE思路要比较巧妙才行，所以重点在于剪枝。

1) 首先我们要知道什么样的表达式才是合法的。其实就是从头往后数，如果在某一位置的累积右括号数多于累积左括号数，那么就不合法。否则就合法。
2) 把当前累计左括号数和累计右括号数都放到入口参数，方便剪枝。不然要再写一个函数parse sol，会浪费时间！
3) dfs里面分几种情况处理：
   case 1: left == n && right == n，此时sol一定合法，存下来退出即可。
   case 2: left == n，此时right一定<n，此时sol的剩余字符只能都是')'了，补全就是。
               那么有人可能会问，会不会出现right>left的情况呢？照代码中4种case来的话就不会。
   case 3: left < n && left > right，此时分2种情况处理，一个是加一个'(’，一个是加一个')'，分别调用dfs即可。
   case 4: left < n && left == right，此时只可能加一个'('，调用dfs。


解法2：在网上看到的，感觉非常不错。
思路就是找左括号，每找到一个左括号，就在其后面加一个完整的括号，最后在开头加一个 ()。用set来去重。
为什么这个方法可行呢？
以n=3为例，我们来看debug的输出就可以理解了。

n=1 a=
         insert ()
 n=2 a=()
    insert (())
         insert ()()
 n=3 a=()()
    insert (())()
    insert ()(())
         insert ()()()
 n=3 a=(())
    insert (()())
    insert ((()))
         insert ()(())

Output

["((()))","(()())","(())()","()(())","()()()"]


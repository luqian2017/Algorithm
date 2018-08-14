这题不容易。可以用DFS做，也可以用BFS做。

解法1： 见.cpp
我参考了网上的solution，不过感觉这种方法好像不一定是最优。

注意： 
1）因为每次生成新str，所以就不需要再results.pop_back()。 
2）注意生成新str后, helper()里面还是i，不是i+1，因为这个新str要重新检查。 
3) 注意去重。 
4) 注意isValid()的写法，比较巧妙。 
5) 注意生成新string的写法 
string new_str = s.substr(0, i) + s.substr(i + 1); 
//if index==0, substr(0,index) = “”

解法2：还是DFS 
https://www.jiuzhang.com/solution/remove-invalid-parentheses/#tag-other-lang-java 
zxqiu的做法好像很巧妙。没时间细看。 
下次做。

解法3： BFS 
下次做

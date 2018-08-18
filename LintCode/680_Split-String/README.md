我用的经典DFS回溯方法，见下图：
![alt text](https://github.com/luqian2017/Algorithm/blob/master/LintCode/680_Split-String/pic1.jpg)

这里注意：
1) if (index >= s.size())  用==也可以。
2) 记得要加上
 if (index < s.size()) {
 和
 if (index < s.size() - 1) 
第一个if可省，第二个不可省。否则
Output
[["1","23"],["12","3"],["12","3"],["1","2","3"],["1","2","3"]]
Expected
[["1","23"],["12","3"],["1","2","3"]]
因为当sol={"12"}时，如果不加限制，以下代码仍会调用

```
            sol.push_back(s.substr(index, 2));
            helper(s, index + 2, sol, results);
            sol.pop_back();
```
这里虽然substr(index,2)已经越界，但不会报错，substr会返回到末尾的子字符串。然后调用helper(,index+2,..)，进去后会将sol存在result中，造成重复。
3) if (index < s.size() - 1) 里面记得要pop_back()，这样才能回溯。

另外，这个解法可以简化成下面的经典方法，这样，分成1..n的子字符串的问题都适用。
 void helper(string&s, int index, vector<string> &sol, vector<vector<string>> &results) {
        if (index == s.size()) {
            results.push_back(sol);
            return;
        }

        for (int i = 1; i < 3; ++i) {
            if (index + i <= s.size()) {
                sol.push_back(s.substr(index, i));
                helper(s, index + i, sol, results);
                sol.pop_back();
            }
        }
    }

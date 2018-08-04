
思路就是暴力深搜 - 每个格子来一次DFS深搜。 
注意： 
1) visited[]数组还是需要 
2) 注意剪枝：如果不是prefix，剪掉！ 如果出界或已经访问过，剪掉！ 
3) char -> string 不能直接用std里面的to_string()，因为char本来就是integer，to_string(char)会生成”100”,”103”这样的字符串。可以用string(1,c)来生成一个临时的内容为c，长度为1的字符串。 
4) 对于二维数组或vector，用if (board.size() < 1) 比if (board.empty()) 更好 
5) getPrefixSets()里面，下面一行 
if (prefixSets.find(prefix) == prefixSets.end()) 
很关键！因为有可能某个word刚好是之前某个prefix，这样可以避免该word被关联到false！

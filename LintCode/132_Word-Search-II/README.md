132. Word Search II
中文English
Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix. A word can start from any position in the matrix and go left/right/up/down to the adjacent position. One character only be used once in one word. No same word in dictionary

Example
Example 1:

Input：["doaf","agai","dcan"]，["dog","dad","dgdg","can","again"]
Output：["again","can","dad","dog"]
Explanation：
  d o a f
  a g a i
  d c a n
search in Matrix，so return ["again","can","dad","dog"].
Example 2:

Input：["a"]，["b"]
Output：[]
Explanation：
 a
search in Matrix，return [].
Challenge
Using trie to implement your algorithm.


解法1:
思路就是暴力深搜 - 每个格子来一次DFS深搜。 
注意： 
1) visited[]数组还是需要 
2) 注意剪枝：如果不是prefix，剪掉！ 如果出界或已经访问过，剪掉！ 
3) char -> string 不能直接用std里面的to_string()，因为char本来就是integer，to_string(char)会生成”100”,”103”这样的字符串。可以用string(1,c)来生成一个临时的内容为c，长度为1的字符串。 
4) 对于二维数组或vector，用if (board.size() < 1) 比if (board.empty()) 更好 
5) getPrefixSets()里面，下面一行 
if (prefixSets.find(prefix) == prefixSets.end()) 
很关键！因为有可能某个word刚好是之前某个prefix，这样可以避免该word被关联到false！

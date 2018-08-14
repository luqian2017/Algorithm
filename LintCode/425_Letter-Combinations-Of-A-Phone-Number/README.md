经典DFS题。注意不要搞糊涂了用两层for循环。

注意这题也可以用BFS，下次补充。

要注意的是follow up。如果问在输入”23”的时候能否实时输出可能的单词，则要用Trie(Prefix tree)或Hashmap来预处理。用Hashmap的话，把所有的字母的前缀对应的单词放到Hashmap里面。但Hashmap的方法费空间，prefix的方法更好。
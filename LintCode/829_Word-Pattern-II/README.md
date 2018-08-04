
DFS暴力遍历所有可能解。
注意 ：
1） 在helper()里面，如果调用的helper()返回false，不能直接返回false，而是要继续处理其他的solution。注意这个跟其他返回vector< vector<> >的情况不一样，因为这里只是返回true/false。
2) map和set没有pop_back()操作，只能用erase。

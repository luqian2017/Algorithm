又是一道DFS排列经典题。这题用visited[]还不够，要专门用一个isValid()函数来确保没有列冲突和两个对角线冲突。

注意： 
1） string的初始化： 
string dotStr(n, ‘.’); 
vector solString(n, dotStr); //good string initialization code!
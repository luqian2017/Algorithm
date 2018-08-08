这题就是经典DFS排列(Permutation)题。 
注意： 
1）既然是Permutation，就要先sort，并加visited[]。而input是个string，所以要把string变成vector< char >才能sort。 
2) 注意去重的关键一步。 
if ((i > 0) && (str[i] == str[i - 1]) && !visited[i-1]) continue; 
这个实际上是 
if ((i > 0) && (str[i] == str[i - 1]) &&visited[i] && !visited[i-1]) continue; 
表示相同元素的后面一个元素选在了前面元素之前。但我们前面已经排除了visited[i]，所以这里不用再加了。
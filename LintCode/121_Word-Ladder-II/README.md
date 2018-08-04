以下面的input为例： 
start = hit 
end = cog 
dict = [hot,dot,dog,lot,log,dof,mit,sit,set,mog,mig,seg,nax,max] 
Return 
[[“hit”,”hot”,”dot”,”dog”,”cog”], 
[“hit”,”hot”,”lot”,”log”,”cog”], 
[“hit”,”mit”,”mig”,”mog”,”cog”]]

我们先用BFS找到一条最短路径，可能是上面3个solution中的一种。 
可以发现BFS遍历到的word是有层级先后顺序的：

level 1: [hit] 
level 2: [mit, sit, hot] 
level 3: [mig, set, dot, lot] 
level 4: [mog, seg, dof, dog, log] 
level 5: [cog]

我们在调用BFS的时候，顺便用Str2NextStrs记下每个string的下一个string的集合，比如说hot->{dot, lot}，然后用StrSteps记下每个string到start的步数，比如说mit->2, seg->4。然后我们就可以用DFS来找最短路径了，因为最短路径就是在每个level中挑一个可行的搭起来的。 
注意上面图中的level1-5对应Str2NextStrs，包含了BFS分层遍历的所有可能节点。



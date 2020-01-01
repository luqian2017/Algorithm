1574. Music Playlist
中文English
Ming likes to listen to music on his mobile phone while traveling by train. He has a n song on his mobile phone. He can listen to the p song on the whole train, so he wants to generate a playlist to produce a p song. The rules for this playlist are:
(1) Each song must be played at least once
(2) In the middle of two songs, there are at least m other songs.
Xiao Ming wants to know how many different playlists can be produced. Since the result is large, the output result is the remainder of the 1000000007.

Example
Example 1:

Input：2,0,3
Output：6
Explanation：
There are 2 songs in total, which are recorded as A and B. 
No other songs are needed between the two songs.
There are 6 programs in AAB, ABA, BAA, BBA, BAB and ABB.
Example 2:

Input：1,1,3
Output：0
Explanation：There is only one AAA scheme, but there are at least one other song in the middle of the same song, so there is no scheme that meets the requirements.
Notice
1≤n≤100
1≤m≤n
1≤p≤100

解法1：DP
dp[i][j]为前i首歌里面有j个unique的歌。
可知dp[i][j]可由dp[i - 1][j - 1]和dp[i - 1][j]转换而来。
dp[i-1][j-1]表示前i-1首歌里面有j-1首unique的歌，那么还有1首unique的歌就从n-(j-1)首unique的歌库里面选就好了。
dp[i-1][j]表示前i-1首歌里面有j首unique的歌，那么第i首歌就从这第j首里面选。注意连续的m首歌里面不能有重复的，所以第j首歌只能从前面的j-m首歌里面选。

为什么dp[i][j]不能由dp[i][j - 1]转换而来呢？因为前i首歌已经用完了，只有j-1首unique的歌，那没有办法再加一首unique的歌了，因为i首歌已经用完了。
为什么dp[i][j]不能由dp[i ][j - 2 ]转换而来呢？原因跟dp[i][j]不能由dp[i][j-1]转换而来相同。
为什么dp[i][j]不能由dp[i - 2][j ]转换而来呢？因为这样很多歌曲就跟dp[i-1][j]搞重复了。
为什么dp[i][j]不能由dp[i - 1][j-2 ]转换而来呢？因为2首unique歌不能插到一首歌的位置。

注意：
1）dp[0][0]应该为1,dp[1][1]不一定为1，因为dp[1][1]表示前1首歌里面有1首unique的歌，那么实际上有n种选择。如果dp[0][0]设为0，那么dp[1][1]也是0了。
2）相乘和相加的结果都要mod 1000000007

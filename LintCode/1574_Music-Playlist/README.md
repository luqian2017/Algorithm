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

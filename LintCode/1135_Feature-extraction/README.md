1135. Feature extraction

Xiao Ming wants to dig up some cat movement information from the cat video. In order to extract motion information, he needs to extract "cat features" from each frame of the video.
The characteristic of a cat is a two-dimensional vector <x, y>. If x_1 = x_2 and y_1 = y_2, then these two are the same feature.
If the characteristics of the kitty are consistent, it can be considered that the kitty is in motion. That is, if features <a, b> appear in continuous frames, then it will constitute feature motion. For example, feature <a, b> appears in the 2/3/4/7/8 frame, then the feature will form two feature motions 2-3-4 and 7-8.
Now, given the features of each frame, the number of features may be different. Xiaoming expects to find the longest characteristic movement.

Example
Example 1:

Input: 
features:
[[2,1,1,2,2],
[2,1,1,1,4],
[2,1,1,2,2],
[2,2,2,1,4],
[0],
[0],
[1,1,1],
[1,1,1]]
Output: 3
Explanation:Feature <1,1> appears three times in a row in consecutive frames. Compared with other features, the number of consecutive occurrences is greater, so output 3
Notice
Each line represents a frame. Among them, the first number is the number of features of the frame, and the next two numbers are a pair of <x, y>
The total number of features does not exceed 10^5

解法1：参考的网上的答案。我觉得非常不错。用2个map, preFreq表示每个坐标到上个时间点的累计出现次数，curFreq表示每个坐标到当前时间点的累计出现次数。

注意：
1）用一个map保存到当前所有的coordinate的freq不行。因为有些坐标到新的时间就没有了，这种情况没法处理。
2)  每次用preFreq判断当前coordinate是否在里面。如果在，curFreq[coordinate] = preFreq[coordinate] + 1，如果不在，curFreq[coordinate]。每行判断完后，preFreq=curFreq, curFreq清零。这个思路非常好。对于preFreq里面的coordinate，如果当前时间点没出现，那么该coordinate的出现次数自动就是0了(因为curFreq清零了)。
3）用unordered_map不行，编译通不过，说unordered_map没有end()？不知道为什么，下次再看。

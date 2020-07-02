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


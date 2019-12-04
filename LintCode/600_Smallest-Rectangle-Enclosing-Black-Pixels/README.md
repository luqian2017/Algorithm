600. Smallest Rectangle Enclosing Black Pixels
中文English
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

Example
Example 1:

Input：["0010","0110","0100"]，x=0，y=2
Output：6
Explanation：
The upper left coordinate of the matrix is (0,1), and the lower right coordinate is (2,2).
Example 2:

Input：["1110","1100","0000","0000"], x = 0, y = 1
Output：6
Explanation：
The upper left coordinate of the matrix is (0, 0), and the lower right coordinate is (1,2).

解法1:
准备两个image的备份，image2和image3。
image2是将image逐行累加到最下面一行:只要某行的某单元上面的单元为1，该单元即为1，否则不变。
image3是将image逐行累加到最下面一行:只要某行的某单元上面的单元为1，该单元即为1，否则不变。
然后找image2最后一行和image3最后一列即可。

注意：
1) 不能只用一个备份(即只用一个image2)。否则image2行累加完成后会对接下来的image2列累加有干扰。
比如说
[0010]
[0110]
[0100]
行累加完后是
[0010]
[0110]
[0110]
此时若直接在上面基础上列累加，则会有
[0011]
[0111]
[0111]
出错。

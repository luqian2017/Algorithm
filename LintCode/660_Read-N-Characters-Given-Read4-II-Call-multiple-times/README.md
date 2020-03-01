660. Read N Characters Given Read4 II - Call multiple times

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Example
Example 1

Input:
"filetestbuffer"
read(6)
read(5)
read(4)
read(3)
read(2)
read(1)
read(10)
Output:
6, buf = "filete"
5, buf = "stbuf"
3, buf = "fer"
0, buf = ""
0, buf = ""
0, buf = ""
0, buf = ""
Example 2

Input:
"abcdef"
read(1)
read(5)
Output:
1, buf = "a"
5, buf = "bcdef"
Notice
The read function may be called multiple times.


解法1：
注意
1) 这题要求多次call，所以我们应该单独设一个char buff[4]，这样如果buff里面有4个char的话，这次读了一个char，下次还可以继续从buff里面读，就不用再调用read4这个系统函数了。buff应该是类里面的全局变量，这样下次调用还可以接着用buff里面的数据。
2) 我们还要设一个readPos和WritePos作为类里面的全局变量。readPos表示这次buff里面已经读到的位置。writePos表示调用read4()之后在buff里面写到什么位置了。同样因为read()会多次调用，它们应该放在函数外面作为全局变量。
3) 什么时候需要调用read4()呢? 可以把这道题当成一个producer-consumer模型。其中buff就是缓冲区。当readPos==writePos的时候，说明buff中的未读数据已经读完了，如果i<n的话，要再call一次read4()。
4) 这里因为read4()不支持循环buffer (ring buffer)，所以每次调用read4()，writePos都是0+read4()实际读的char数。而因为read4()不支持循环buffer，每次调用read4()，readPos也就必须设为0。
5) 如果writePos==0，说明这次read4根本就没有读到什么新数据，也就是说文件已经读到头了，实际上上次read4()就已经读完了，那么就可以直接退出，返回i即可，i就是实际读到的总数据。
6) 如果0<writePos<4，那么程序还会在for循环里多执行几次buf[i] = buff[readPos++]，直到readPos==writePos，然后退出。
7) 如果题目说的是只调用一次read()，那么就不需要再开一个buff了，程序可以写成如下：
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n / 4; ++i) {
            int cur = read4(buf + res);
            if (cur == 0) break;
            res += cur;
        }
        return min(res, n);
    }
};


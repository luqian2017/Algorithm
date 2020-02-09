743. Monotone Increasing Digits

Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example
Given N = 10, return 9
Given N = 12345, return 12345
Given N = 10000, return 9999

Notice
Note: N is an integer in the range [0, 10^9].


解法1：
思路从最低位往高扫，当遇到digits[i] > digits[i-1]时，pos=i，同时digits[i]--。这个过程要一直进行，直到找到最后一个值升高的位置。注意每次比大小的时候要按已经更新过的digits元素的值。
举例：
1) 123496。从最低位6往前扫，发现9比6大，则9变成8，pos=1。
最后，从0到pos-1，把所有的数字变成9即可。所以结果是123489。
2) 100001。从最低位往前扫，发现最高位1比0大，则1变成0，pos=5。
然后，从1到pos-1，把所有的数字变成9即可。所以结果是99999。

我的一个想法是能不能就从最高位往低扫，当遇到第一个digits[i] > digits[i-1]时，就设pos=i, digits[i]--，然后退出。这样就不用遍历整个digits[]了。但这样是不对的。
举例：
1) 111111110。遍历到最后才发现1>0。此时最后一个1变0，pos=1。结果是111111109。但正确结果是99999999。
原因在于前面一大堆1都是一样的，从后往前的话可以挨个处理，从前往后就不行了。
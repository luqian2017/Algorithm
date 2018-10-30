经典位运算题。
给出3*n + 1 个的数字，除其中一个数字之外其他每个数字均出现三次，找到这个数字。

在线评测地址: http://www.lintcode.com/problem/single-number-ii/

解法参考九章，基于模3运算。其中ONES 和 TWOS 表示：
如果TWOS里面ith是1，则ith当前为止出现1的次数模3的结果是2
如果ONES里面ith是1，则ith目前为止出现1的次数模3的结果是1

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        int ONES = 0, TWOS = 0;
        for (auto i : A) {
            ONES = (ONES ^ i) & (~TWOS);
   //         cout<<"ONES = "<<ONES<<endl;
            TWOS = (TWOS ^ i) & (~ONES);
   //         cout<<"TWOS = "<<TWOS<<endl;
        }
        return ONES;
    }
}; 

以输入[1,1,2,1]为例，打印信息为：
一开始ONES = 0, TWOS = 0
1来后：//00000000 00000000 00000000 00000001
ONES = 1 // ONES ^ 1 = 0x1, ~TWOS = 0xFFFF, ONES = 0x1
TWOS = 0 // TWOS ^ 1 = 0x1, ~ONES = 0xFFFE, TWOS = 0x0
2来后：//00000000 00000000 00000000 00000010
ONES = 3 // ONES ^ 2 = 0x3, ~TWOS = 0xFFFF, ONES = 0x3
TWOS = 0 //TWOS ^ 2 = 0x2, ~ONES = 0xFFFC, TWOS = 0x0
1来后：//00000000 00000000 00000000 00000001
ONES = 2 // ONES ^ 1 = 0x2, ~TWOS = 0xFFFF, ONES = 0x2
TWOS = 1 //TWOS ^ 1 = 0x1, ~ONES = 0xFFFD, TWOS = 0x1
1来后：//00000000 00000000 00000000 00000001
ONES = 2 // ONES ^ 1 = 0x3, ~TWOS = 0xFFFE, ONES = 0x2
TWOS = 0 // TWOS ^ 1 = 0x0, ~ONES = 0xFFFD, TWOS = 0x0

对ONES操作， ONES = ONES ^ A[i] & (~ TWOS) 把A[i] 计入到出现一次的情况里，但是有可能这个数已经出现过两次，所以要~TWOS。见最后一个1来后的ONES=2的处理。

对TWOS操作， TWOS = TWOS ^ A[i] & (~ONES) 把A[i] 计入到出现两次的情况里。

如果第三次出现了，自然会消掉(见最后一行的TWOS^1=0x0)。
如果是第二次出现就计入。
如果是第一次出现，不计入(见第一个1来时后的TWOS ^ 1 = 0x1, ~ONES = 0xFFFE, TWOS = 0x0)。
以上过程实际上是通过TWOS和ONES的非相交来控制。

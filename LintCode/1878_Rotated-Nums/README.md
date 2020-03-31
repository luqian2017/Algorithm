
1878. Rotated Nums

X is a good number when all the number rotates 180° and still be itself.Like "1" ,"2" ,"0”,"12021","69" and "96". It must be noted that we use numbers like the nums on the traffic lights.

Give you a len n,we need to count how many good numbers of length n.

Example
Input: n = 1
Output: 5
Explanation: 5 good nums is "0","1","2","5","8"
Input: n = 2
Output: 6
Explanation: 6 good nums is "11","22","55","88","69","96"
Notice
Rotate the whole good number, not every bit.
Except 0, good numbers cannot contain leading zeros.
1<=n<=40


解法1：
我们可以分奇数和偶数来考虑。设halfLen = (n - 1) / 2。当n=1,2时直接返回结果。

当n为奇数时，我们只需要考虑右边halfLen个数字和中间那个数字。中间那个数字只能是0,1,2,5,8这5种可能。而中间往右halfLen-1个数字每个可以取0,1,2,5,8,6,9这7种数字，最后一个只能取1,2,5,8,6,9这6种数字，因为首字母不能为0。

当n为偶数时，我们只需要考虑右边halfLen个数字，这时halfLen实际上比一半长度还少一个，所以最后乘6即可。

解法2：

这是我一开始的做法，实际上相当于逆向工程破解。即输入不同的n，看其结果，然后总结模式。
n = 1 -> 5
n = 2 -> 6
n = 3 -> 30
n = 4 -> 42
n = 5 -> 210
n = 6 -> 294
n = 7 -> 1470
n = 8 -> 2058
n = 9 -> 10290
n = 10 -> 14406

总结规律：
n为奇数时，dp[i] = dp[i - 1] * 5   
 注意：n为奇数时可以理解为就是基于n-1(偶数)的结果，中间插入一个数字，有5种可能。
    为什么我们不用考虑n-2的结果呢？因为n-1的结果里面已经包括了n-2的结果。
n为偶数时，dp[i] = dp[i - 1] + dp[i - 2] * 2; 
  注意：n为偶数时可以理解为基于n-1(奇数)的结果和n-2(偶数)的结果的和。
    对于n-1的结果，可以理解为中间那个数字又重复一次，所以还是dp[i - 1]
    为什么还要考虑n-2的结果呢？因为dp[i]不能光由上面的dp[i-1]来，因为这种结果里面中间两个数字是一样的。
    我们还必须考虑中间两个数字不一样的情况。那么这种情况只可能是取69和96这两种情况了。这就是为什么还要加dp[i-2]*2。

 不过这个算法非常耗时，勉强能过。
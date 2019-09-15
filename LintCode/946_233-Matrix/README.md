946. 233 Matrix
中文English
Given a matric A. The first row of matrix A is 0, 233, 2333, 23333...(i.e., A(0,0)=0,A(0,1)=233,A(0,2)=2333,A(0,3)=23333...). Besides, A(i,j)=A(i-1,j)+A(i,j-1).

Given an array X with n integers. X[i] is A(i+1,0), (i.e., X[0] is A(1,0), X[1] is A(2,0) ...), and a positive integer m.

Return the value of A(n,m) % 10000007.

Example
Example1

Input: X=[1], m=1
Output: 234
Explanation:
[[0,233],
 [1,234]]
Example2

Input: X=[0,0], m=2
Output: 2799
Explanation:
[[0,233,2333],
 [0,233,2566],
 [0,233,2799]]
Notice
n <=1 0, m <= 10^9
0 =< A(i,0) < 2^31

解法1：矩阵快速幂
这题的意思就是求
[0, 233, 2333, 23333,        ...]
[X_0, ?,   ?,     ?,         ...]
[X_1, ?,   ?,     ?,         ...]
...
[X_(n-1), ?,   ?,  ?,        ...]

矩阵A(n+1行，n+1列)里面的第A(n,m)项的值，其中A(i,j)=A(i-1,j)+A(i,j-1).
Example 1的output 就是：
[0 233]
[1 234]

Example 2的output 就是
[0 233 2333]
[0 233 2366]
[0 233 2799]

这道题感觉很难。下面这个链接讲解得非常好：
https://www.cnblogs.com/whatbeg/p/3971994.html

分析如下。
因为
```

A(n,m)=A(n-1,m)+A(n,m-1)
      =A(n-2,m)+A(n-1,m-1)+A(n,m-1)
      =A(n-3,m)+A(n-2,m-1)+A(n-1,m-1)+A(n,m-1)
      =...
      =A(0,m)+A(1,m-1)+A(2,m-1)+...+A(n,m-1)
```
即如下图所示（原出处为https://www.cnblogs.com/whatbeg/p/3971994.html）：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190915075433445.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3JvdWZvbw==,size_16,color_FFFFFF,t_70)
 红色方块即A[n][m]，其值为绿色方块之和。
我们知道
 ```
 A(n,m) =A(0,m)+A(1,m-1)+A(2,m-1)+...+A(n,m-1)
```
    
注意到233 = 23 * 10+3, 2333 = 233 * 10 + 3, 23333 = 2333 * 10 + 3
我们有

```
A(0, 0) = 0
A(0, 1) = 23
A(0,m) = A(0,m-1) * 10 + 3, m>=2
```


所以
 ```
 A(n,m) = A(0,m-1) * 10 + A(1,m-1) + A(2,m-1) + ... + A(n,m-1) + 3, m >= 2
```
所以，对于m>=2，我们等价于求下面的矩阵运算。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190915080457138.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3JvdWZvbw==,size_16,color_FFFFFF,t_70)
我们称上图的大矩阵为M的话，注意如果X维数为n, M的维数就是(n+2) * (n +2)。当m>=2时，

```
(a0,m a1,m, a2,m, ..., an,m 3) = M * (a0,m-1 a1,m-1 a2,m-1 ... an,m-1 3)
                                = M^2 * (a0,m-2 a1,m-2 a2,m-2 ... an,m-2 3)
                                ...
                                = M^m-1 * (a0,1 a1,1 a2,1 ... an,1 3)
```

但要注意，上面都是针对m>=2的情况，所以我们要先求出m=0和m=1的情况。
而m=0时，
(a0,0  a1,0  a2,0 ... an,0 3) = (0 X0 X1 ... Xn-1 3) //即最后结果第0列。
m=1时，
(a0,1 a1,1 a2,1 ...  an,1 3) = (233, 233+X0, 233+X0+X1, ..., 233+X0+X1+...+Xn-1, 3) // 即最后结果的第1列

进一步分析，

```
(a0,1 a1,1 a2,1 ...  an,1 3) =
(233, 233+X0, 233+X0+X1, ..., 233+X0+X1+...+Xn-1, 3) = 
(233, 233, 233, ..., 233, 3) + (0, X0, X0+X1, ..., X0+X1+...+Xn-1, 0) = 
(233, 233, 233, ..., 233, 3) + M * (0, X0, X1, ..., Xn-1, 0)  =
(23, 233, 233, ..., 233, 3) + M * (a0,0  a1,0  a2,0 ... an,0 0) 
```
而
```
(233, 233, 233, ..., 233, 3) = M * (23, 0, ..., 0, 3)
```
所以，
```
(a0,1 a1,1 a2,1 ...  an,1 3) = M * [(23, 0, ..., 0, 3) + (a0,0  a1,0  a2,0 ... an,0 0)]
(a0,m a1,m, a2,m, ..., an,m 3) = M^m-1 * (a0,1 a1,1 a2,1 ... an,1 3)
                               = M^m* (23, 0, ..., 0, 3) + M^m * (a0,0 a1,0 ... an,0 3)
```
我们把M ^ m   取名叫Mm，则我们因为只需要求a(n,m)，所以
**a(n,m) = Mm(n, 0) * 23 + Mm(n+1, m) * 3 + Mm * (a0,0 a1,0  ... an,0 3)**

代码如下：
```
class Matrix {
public:
    vector<vector<long long>> matrix;
    
    Matrix(int n, int mod) {
        dim = n;
        this->mod = mod;
        matrix.resize(dim, vector<long long>(dim, 0LL));
    }
    
    void unit() {
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                //matrix[i][j] = (long long)(i == j);
                if (i == j) matrix[i][j] = 1LL;
            }
        }
    }
    
    Matrix operator * (const Matrix & m) const {
        Matrix result(dim, mod);
        for (int i = 0; i < dim; ++i) {
            for (int k = 0; k < dim; ++k) {
                if (matrix[i][k] == 0) continue;
                for (int j = 0; j < dim; ++j) {
                    result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
                    result.matrix[i][j] %= mod;
                }
            }
        }
        return result;
    }

    Matrix power(int n) {
        Matrix result(dim, mod);
        result.unit();
        while(n) {
            if (n & 0x1) result =  result * (*this);
            //matrix = matrix * matrix;
            *this = (*this) * (*this);
            n /= 2;
        }
        return result;
    }
    
private:
    int dim, mod;
};


class Solution {
public:
    /**
     * @param X: a list of integers
     * @param m: an integer
     * @return: return an integer
     */
    int calcTheValueOfAnm(vector<int> &X, int m) {
        int n = X.size();
        if ((n == 0) && (m == 0)) return 0;
        if (m == 0) return X[n - 1];
        Matrix mx(n + 2, 10000007);
        
        for(int i = 0; i <= n; ++i) mx.matrix[i][0] = 10;
        for(int i = 0; i <= n + 1; ++i) mx.matrix[i][n + 1] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= i; ++j)
                mx.matrix[i][j] = 1;
        
        Matrix tmp = mx.power(m);
        long long answer = 23 * tmp.matrix[n][0] + 3 * tmp.matrix[n][n + 1];
 
        for (int i = 1; i <= n; ++i) {
            answer += tmp.matrix[n][i] * X[i - 1];
        }
        
        answer %= 10000007;
        return answer;
    }
};
```
解法2：
DP。感觉此题也可以用DP做，不过时间复杂度可能太大？

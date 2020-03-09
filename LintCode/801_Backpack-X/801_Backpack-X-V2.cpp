class Solution {
public:
    /**
     * @param n: the money you have
     * @return: the minimum money you have to give
     */
    int backPackX(int n) {
        vector<int> prices={150, 250, 350};
        vector<vector<int>> dp(4, vector<int>(n + 1));
        
        for (int i = 1; i <= 3; ++i) {
            for (int j = 0; j <= n; ++j) {   //j=1 也可以
                dp[i][j] = dp[i - 1][j];
                if (j >= prices[i - 1]) {   //note it is >=
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - prices[i - 1]] + prices[i - 1]);
                }
            }
        }
        
        return n - dp[3][n];
    }
};
————————————————
版权声明：本文为CSDN博主「纸上得来终觉浅 绝知此事要躬行」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/roufoo/article/details/83378395
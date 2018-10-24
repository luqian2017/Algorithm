我开始觉得这就是多重背包问题的变种，但是解法1会超时。因为有3重循环，所以当amount[i]的值都很大就超时了。

解法1：
dp[i]表示coins是否可以组合成i的值。

class Solution {
public:
    /**
     * @param n: the value from 1 - n
     * @param value: the value of coins
     * @param amount: the number of coins
     * @return: how many different value
     */
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
        int m = value.size();
        vector<bool> dp(n + 1, false); //dp[i] shows if the coins can be combined into i
        int sum = 0;
        
        dp[0] = true;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= amount[i]; ++j) {
                for (int k = n; k >= value[i]; --k) {
                    if (!dp[k] && dp[k - value[i]]) { //记得!dp[k]可以剪枝
                        dp[k] = true;
                    }
                }
            }
        }    
            
        for (int i = 1; i <= n; ++i) {
            if (dp[i]) sum++;
        }
        
        return sum;
    }
};

解法2(优化)：
优化非常巧妙，不容易想到。我参考了九章答案。
首先我们来看这道题跟传统的多重背包有什么区别? 传统的多重背包我们需要比大小。我们来看这backPackVII的代码(见我的博客LintCode 798)。

      int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts) {
        int itemCount = prices.size();   //count of items
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < itemCount; ++i) {
            for (int  j = 1; j < amounts[i]; ++j) {
                for (int k = n; k >= prices[i]; --k) {
                    dp[k] = max(dp[k], dp[k - prices[i]] + weight[i]);
                 }
             }
        }
        return dp[n];
    }

dp[k]是求价值不超过k情况下的最大重量。具体的说就是比较当前的dp[k]和第i-1次的还没有装item i时候的价格为k-prices[i]时的最大重量加上item i时候的重量，因为item i有amount[i]个，所以我们一定要比较amount[i]次才能找到最大值。

而对于这道题目Backpack VIII，我们的目标只是求dp[k]是true还是false。我们将dp[1…n]的初始值设为false。什么时候我们需要dp[k]为真呢? 当下面3个条件同时成立时：

当dp[k]为false。这是显然的剪枝条件。当dp[k]为true，我们不需要做重复功。
当dp[k - value[i]]为真。此时说明这些硬币可以凑成k - value[i]的值。如果dp[k - value[i]]为假，说明dp[k]也是false。因为在前
i-1次循环中（即前i-1种硬币不能凑出k-value[i]的钱，说明加上value[i]也凑不出k的钱)。
当前i次循环的时候，所用的硬币i的数量还没超过amount[i]。这也是显然的。注意这里我们必须要用另外一个数组
count[]。count[x]即当前(i)的时候，多少 个硬币i已经用了来和其他硬币凑出x的价值。
代码如下：

class Solution {
public:
    /**
     * @param n: the value from 1 - n
     * @param value: the value of coins
     * @param amount: the number of coins
     * @return: how many different value
     */
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
        int m = value.size();
        vector<bool> dp(n + 1, false); //dp[i] shows if the coins can be combined into i
        int sum = 0;
        
        dp[0] = true;
        for (int i = 0; i < m; ++i) {
            vector<int> count(n + 1, 0);  //count[x] is for current i, how many i s have been used to get x
            for (int k = value[i]; k <= n; ++k) {
                if (!dp[k] && dp[k - value[i]] && count[k - value[i]] < amount[i]) {
                    dp[k] = true;
                    count[k] = count[k - value[i]] + 1;
                    sum ++;
               }
           }
       }    
       return sum;
    }
};

注意：

为什么这里k循环又是从小到大呢？而相比之下为什么Backpack VII里面的优化方案的k循环是从大到小？
注意在Backpack VII里面，

dp[k] = max(dp[k], dp[k - prices[i]] + weight[i]);
1
也就是i时候的时候dp[k]实际上依赖于i-1时候的dp[k-prices[i]]。
所以对于大的k值的dp[k]依赖于上轮循环的小的k的dp[k]值，所以k循环从大到小。这里为什么还需要j循环呢？看代码

 for (int  j = 1; j < amounts[i]; ++j) {
    for (int k = n; k >= prices[i]; --k) {
          dp[k] = max(dp[k], dp[k - prices[i]] + weight[i]);
    }
}

假设对于i=2, amount[2]=4, k=8, prices[2]=3, weight[2]=1，则k循环一轮之后 dp[8]=max(dp[8], dp[5]+1)。因为k从大到小，所以后面的dp[5]变了dp[8]不知道，但是因为amount[2]=4，即item2有4个，我们再来一次k循环之后dp[8]就会被更新的dp[5]更新了。用完所有的amount[2]之后，dp[8]就是到i时候的最优值了。

而Backpack VIII里面，i时候的dp[k]为真依赖于i-1时候的dp[k - value[i ]]为真， 而i-1时候的dp[k-value[i]]为真，i时候的dp[k-value[i]]也必然为真, 因为dp值一旦为真就永远不会变了！。所以我们这里不需要用到上轮循环的值，所以k的值可以从小到大，也不需要j循环。

如果这里将k的值变成从大到小，就必须加j循环，否则不对。假设dp[8]的依赖于dp[5]的值，而dp[5]的值又依赖于dp[3]的值，等等，只有一层循环是不能取到最优的。

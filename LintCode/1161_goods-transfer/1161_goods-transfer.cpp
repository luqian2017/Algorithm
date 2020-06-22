class Solution {
public:
    /**
     * @param n: the number of backpacks
     * @param a: the number of goods each backpack carries
     * @param b:  the maximum capacity of each backpack
     * @return: given n, ai and bi,return the minimum number of backpacks and the minimum time
     */
    vector<int> goodsTransfer(int n, vector<int> &a, vector<int> &b) {
        int const INF = 0x3f3f3f3f;
        int k = INF, max_weight = 0;
        int sum_good = 0, sum_cap = 0;
        for (int i = 0; i < a.size(); i++) {
            sum_good += a[i];
            sum_cap += b[i];
        }
        
        //dp[i][j]表示前i个箱子，挑出最少的箱子个数后构成j的容量时，那个最少的箱子总数
        //可以简化为dp[j]，类似01背包一维数组优化。
        //weight[j]表示上面的最优方案里这些箱子里的食物之和最大是多少。
        vector<int> dp(sum_cap + 1, INF);
        vector<int> weight(sum_cap + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = sum_cap; j > 0; j--) {
                int res = max(j - b[i], 0);
                if (dp[j] < dp[res] + 1) {
                    continue;
                } else if (dp[j] > dp[res] + 1) {
                    dp[j] = dp[res] + 1;
                    weight[j] = weight[res] + a[i];
                } else {
                    weight[j] = max(weight[j], weight[res] + a[i]);
                }
            }
        }
    
    
       //dp[i]越小越优, 如果dp[i]结果一致，则weight[i]越大越好。
        for (int i = sum_good; i <= sum_cap; i++) {
            if (dp[i] < k) {
                k = dp[i];
                max_weight = weight[i];
            } else if (dp[i] == k) {
                max_weight = max(max_weight, weight[i]);
            }
        }
    
        return vector<int>{k, sum_good - max_weight};
    }
};
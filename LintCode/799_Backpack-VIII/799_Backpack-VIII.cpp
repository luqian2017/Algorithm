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
        //    for (int j = 1; j <= amount[i]; ++j) {
            vector<int> count(n + 1, 0);  //count[x] is for current i, how many i s have been used to get x
                for (int k = value[i]; k <= n; ++k) {
                    if (!dp[k] && dp[k - value[i]] && count[k - value[i]] < amount[i]) {
                        dp[k] = true;
                        count[k] = count[k - value[i]] + 1;
                        sum ++;
        //            }
                }
            }
        }    
            
//        for (int i = 1; i <= n; ++i) {
//            cout<<dp[i]<<" ";
//        }
        
        return sum;
    }
};
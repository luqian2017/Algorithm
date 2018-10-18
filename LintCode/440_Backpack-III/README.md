Full backpack problem (i.e., each item can be carried unlimited times until the backpack size).

Solution 1:
Typical DP solution (based on the optimization in multi-choice backpack problem)
Time complexity O(Sum_i(backpackSize /itemCount[i]) * backpackSize)
Space complexity O(backpackSize).

Note we can also write A[i - 1] as A[i] as follows: 
    
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        int n = A.size();
        vector<int> dp(m + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            
            for (int j = 0; j * A[i] <= m; ++j) {
                
                for (int k = m; k >= A[i]; --k) {
                    
                    dp[k] = max(dp[k], dp[k - A[i]] + V[i]);
                }
            }
        }
        
        return dp[m];
    }
Note here loop j can start from 0 or 1.
In contrast, in multi-choice backpack problem, the j loop can only start from 1. This is because in multi-choice backpack problem, each item limited count. If j starts from 0, then the j loop has amounts[i]+1 iterations; consequently, in dp[i][k - prices[i]], k totally minuses (amounts[i]+1)*prices[i], which does not make sense as there are only up to amounts[i] item i.

Solution 2:
3 loop -> 2 loop by reversing the k loop from small to big.

Time complexity O(mn). Space complexity O(m).

Note we cannot apply this optimization method in multi-choice backpack problem. Let's look at the loop:
         for (int k = prices[i]; k <= m; ++k) {
             dp[k] = max(dp[k], dp[k - prices[i]] + weight[i]);
         }
In multi-choice backpack prlblem, the dp[k - prices[i] may not be meaniningful during the k loop as item i has limited amount (amounts[i]).        
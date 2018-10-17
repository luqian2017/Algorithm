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

Solution 2:
3 loop -> 2 loop.

Time complexity O(mn). Space complexity O(m).
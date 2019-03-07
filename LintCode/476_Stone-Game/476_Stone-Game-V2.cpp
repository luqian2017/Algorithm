class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        int n = A.size();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> sums(n, 0);
        
        sums[0] = A[0];        
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + A[i];  
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                dp[i][i + len - 1] = INT_MAX;
                int sum = sums[i + len - 1] - sums[i - 1];
                for (int k = i; k < i + len - 1; ++k) {
                    dp[i][i + len - 1] = min(dp[i][i + len - 1], dp[i][k] + dp[k + 1][i + len - 1] + sum);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
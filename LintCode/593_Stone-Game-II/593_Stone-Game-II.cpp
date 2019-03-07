class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame2(vector<int> &A) {
        int n = A.size();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n * 2, vector<int>(n * 2, 0));
        vector<int> sums(n * 2, 0);
        
        sums[0] = A[0];        
        for (int i = 1; i < n * 2; ++i) {
            sums[i] = sums[i - 1] + A[i % n];  
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n * 2; ++i) {
                dp[i][i + len - 1] = INT_MAX;
                int sum = sums[i + len - 1] - sums[i - 1];
                for (int k = i ; k < i + len - 1; ++k) {
                    dp[i][i + len - 1] = min(dp[i][i + len - 1], dp[i][k] + dp[k + 1][i + len - 1] + sum);
                }
            }
        }
        
        int result = INT_MAX;
        for (int i = 0; i < n; ++i) {
            result = min(result, dp[i][i + n - 1]);
        }
        
        return result;
        
    }
};
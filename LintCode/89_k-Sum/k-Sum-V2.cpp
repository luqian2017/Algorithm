class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        int n = A.size();
        if (n < k) return 0;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));
        
        //dp[0][0][0] = 1;
        for (int i = 0; i <= n; ++i) dp[i][0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(k, i); ++j) {
                for (int k = 1; k <= target; ++k) {
                    if (k >= A[i - 1]) {
                        dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - A[i - 1]];
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                    
                }
            }
        } 
        
        return dp[n][k][target];
    }
};
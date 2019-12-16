class Solution {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
    int MinAdjustmentCost(vector<int> &A, int target) {
        int n = A.size();
        if (n == 0 ) return 0;
        int result = INT_MAX;
        
        vector<vector<int>> dp(n + 1, vector<int>(100 + 1, INT_MAX));
        for (int i = 0; i <= 100; ++i) {
            dp[0][i] = 0;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 100; ++j) {
                int lowRange = max(1, j - target);
                int upperRange = min(100, j + target);
                for (int k = lowRange; k <= upperRange; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - A[i - 1])); //abs(k - A[i - 1])); is also OK? 
                }
            }
        }
        
        for (int i = 1; i <= 100; ++i) {
            result = min(result, dp[n][i]);
        }
            
        return result;
    }
};
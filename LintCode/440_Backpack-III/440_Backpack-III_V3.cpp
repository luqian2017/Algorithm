class Solution {
public:
    /**
     * @param A: an integer array   // size array
     * @param V: an integer array   // value array
     * @param m: An integer         // backpack size
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        int n = A.size();
        //dp[i][j] : maximum value of first i items with bag size j
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = A[i - 1]; j <= m; ++j) {  //j can start from 0 or 1
                for (int k = 0; k * A[i - 1] <= m; ++k) {
                    if (j >= k * A[i - 1])
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * A[i - 1]] + k * V[i - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};
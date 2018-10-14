class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int itemCount = A.size();
        //dp[2][packSize]
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        int rotate = 0;
        
        for (int i = 0; i <= itemCount; ++i) {
            rotate ^= 1;
            for (int j = 0; j <= m; ++j) {
                dp[rotate][j] = dp[rotate ^ 1][j];
                if (j >= A[i - 1]) {
                    dp[rotate][j] = max(dp[rotate][j], dp[rotate ^ 1][j - A[i - 1]] + V[i - 1]);
                }
            }
        }
        
        return dp[rotate][m];
    }
};
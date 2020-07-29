class Solution {
public:
    /**
     * @param poured: an integer
     * @param query_row: an integer
     * @param query_glass: an integer
     * @return: return a double
     */
    double champagneTower(int poured, int query_row, int query_glass) {

        double result = 0.0;
        
        //dp[i][j] : amount of water filled into jth glass at row i
        vector<vector<double>> dp(2, vector<double>(query_row + 1, 0.0));
        
        dp[0][0] = poured;

        for (int i = 1; i <= query_row; ++i) {
            if (dp[(i - 1) % 2][0] > 1) dp[i % 2][0] = (dp[(i - 1) % 2][0] - 1) / 2;
            if (dp[(i - 1) % 2][query_row - 1] > 1) dp[i % 2][query_row - 1] = (dp[(i - 1) % 2][query_row - 1] - 1) / 2;
            for (int j = 1; j <= query_row; ++j) {
                if (dp[(i - 1) % 2][j - 1] > 1) dp[i % 2][j] += (dp[(i - 1) % 2][j - 1] - 1) / 2;
                if (dp[(i - 1) % 2][j] > 1) dp[i % 2][j] += (dp[(i - 1) % 2][j] - 1) / 2;  
            }
        }
        
        return dp[query_row % 2][query_glass] > 1.0 ? 1.0 : dp[query_row % 2][query_glass];
    }
};
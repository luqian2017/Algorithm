class Solution {
public:
    /**
     * @param matrix: a matrix of 0 an 1
     * @return: an integer
     */
    int maxSquare2(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int gMax = 0;
        
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 1) {
                dp[i][0] = 1;
                gMax = 1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 1) {
                dp[0][i] = 1;
                gMax = 1;
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
    
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    int prevSize = dp[i - 1][j - 1];
                    bool twoBorderZero = true;
                    for (int k = 1; k <= prevSize; ++k) {
                        if (matrix[i - k][j] == 1 || matrix[i][j - k] == 1) {
                            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                            twoBorderZero = false;
                            break;
                        }
                    }
                    
                    if (twoBorderZero && matrix[i][j] == 1) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        gMax = max(gMax, dp[i][j]);               
                    }
                }
         
            }
        }
        
        return gMax * gMax;
    }
};
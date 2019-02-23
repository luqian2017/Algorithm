class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        if (nRow == 0) return 0;
        
        vector<vector<int>> dp(nRow, vector<int>(nCol, 0));
        int maxLen = 0;
        for (int i = 0; i < nRow; ++i) {
            if (matrix[i][0] == 1) { 
                dp[i][0] = 1; 
                maxLen = 1;
            }
        }
        
        for (int j = 0; j < nCol; ++j) {
            if (matrix[0][j] == 1) {
                dp[0][j] = 1;
                maxLen = 1;
            }
        }
        
        for (int i = 1; i < nRow; ++i) {
            for (int j = 1; j < nCol; ++j) {
                if (matrix[i][j] == 0) continue;
                bool qualify = true;
                int len = dp[i - 1][j - 1];
                for (int k = j - 1; k >= j - len; --k) {
                    if (matrix[i][k] == 0) {
                        qualify = false;
                        break;
                    } else {
                        for (int k = i - 1; k >= i - len; --k) {
                            if (matrix[k][j] == 0) {
                                qualify = false;
                                break;
                            }
                        }
                    }
                }
                if (qualify) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        
        return maxLen * maxLen;
    }
};
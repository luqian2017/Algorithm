class Solution {
public:
    /**
     * @param Matrix: 
     * @param c: the zero submatrix rows
     * @param d: the zero submatrix columns
     * @return: return if there exists zero submatrix
     */
    bool isZeroMatrix(vector<vector<int>> &Matrix, int c, int d) {
        int row_len = Matrix.size();
        int col_len = Matrix[0].size();
        
        vector<vector<int>> presum2D(row_len + 1, vector<int>(col_len + 1));

        for (int i = 1; i <= row_len; ++i) {
            for (int j = 1; j <= col_len; ++j) {
                presum2D[i][j] = presum2D[i - 1][j] + presum2D[i][j - 1] + Matrix[i - 1][j - 1] - presum2D[i - 1][j - 1];
            }
        }

        for (int i = c; i <= row_len; ++i) {
            for (int j = d; j <= col_len; ++j) {
                int sum = presum2D[i][j] - presum2D[i - c][j] - presum2D[i][j - d] + presum2D[i - c][j - d];
                if (sum == 0) return true;
            }
        }
        
        return false;
    }
};
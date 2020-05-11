class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: True if and only if the matrix is Toeplitz
     */
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int nRow = matrix.size();
        if (nRow == 0) return true;
        int nCol = matrix[0].size();
        if (nCol == 0) return true;

        for (int i = 0; i < nRow; ++i) {
            int firstElem = matrix[i][0];
            int row = i;
            int col = 0;
            while (row < nRow - 1 && col < nCol - 1) {
                row++;
                col++;
                if (matrix[row][col] != firstElem) return false;
            }
        }
        
        for (int j = 1; j < nCol; ++j) {
            int firstElem = matrix[0][j];
            int row = 0;
            int col = j;
            while (row < nRow - 1 && col < nCol - 1) {
                row++;
                col++;
                if (matrix[row][col] != firstElem) return false;
            }
        }
        
        return true;
    }
};
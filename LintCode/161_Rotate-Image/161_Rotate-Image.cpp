class Solution {
public:
    /**
     * @param matrix: a lists of integers
     * @return: nothing
     */
    void rotate(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if (rowSize == 0) return;
        int colSize = matrix[0].size();
        
        for (int i = 1; i < rowSize; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
           
        for (int i = 0; i < colSize / 2; ++i) {
            for (int j = 0; j < rowSize; ++j) {
                swap(matrix[j][i], matrix[j][colSize - 1 - i]);
            }
        }
    }
};
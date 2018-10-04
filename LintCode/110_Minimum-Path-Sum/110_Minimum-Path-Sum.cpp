class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        
        vector<vector<int>> A(nRow, vector<int>(nCol, 0));
        
        A[0][0] = grid[0][0];
        for (int i = 1; i < nRow; ++i) {
            A[i][0] = A[i - 1][0] + grid[i][0];
        }
        
        for (int j = 1; j < nCol; ++j) {
            A[0][j] = A[0][j - 1] + grid[0][j];
        }
        
        for (int i = 1; i < nRow; ++i) {
            for (int j = 1; j < nCol; ++j) {
                if ((i ==0) || (j == 0)) continue; 
                A[i][j] = min(A[i - 1][j], A[i][j - 1]) + grid[i][j];
            }
        }
        
        return A[nRow - 1][nCol - 1];
    }
};
class Solution {
public:
    /**
     * @param grid: a 2D array
     * @return: the perimeter of the island
     */
    int islandPerimeter(vector<vector<int>> &grid) {
        int nRow = grid.size();
        if (nRow == 0) return 0;
        int nCol = grid[0].size();
        if (nCol == 0) return 0;
        
        int perimeter = 0;
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0) perimeter++;
                    if (i == nRow - 1) perimeter++;
                    if (j == 0) perimeter++;
                    if (j == nCol - 1) perimeter++;
                    if (i > 0 && grid[i - 1][j] == 0) perimeter++;
                    if (i < nRow - 1 && grid[i + 1][j] == 0) perimeter++;
                    if (j > 0 && grid[i][j - 1] == 0) perimeter++;
                    if (j < nCol - 1 && grid[i][j + 1] == 0) perimeter++;
                }
            }
        }
        
        return perimeter;
    }
};
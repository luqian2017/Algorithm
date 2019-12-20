class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        int nRow = grid.size();
        if (nRow == 0) return 0;
        int nCol = grid[0].size();
        int rowEnemies = 0;
        vector<int> colCounts(nCol, 0);
    //    int colEnemies = 0;
        
        int maxCount = 0;
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colCounts[j] = 0;
                    colEnemies = 0;
                    for (int k = i; k < nRow && grid[k][j] != 'W'; ++k) {
                        if (grid[k][j] == 'E') {
                            colCounts[j]++;
  //                          colEnemies++;
                        }
                    }
                }

                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowEnemies = 0; 
                    for (int k = j; k < nCol && grid[i][k] != 'W'; ++k) {
                        if (grid[i][k] == 'E') rowEnemies++;
                    }
                }

                if (grid[i][j] == '0') {
                    maxCount = max(maxCount, rowEnemies + colCounts[j]);
                 //   maxCount = max(maxCount, rowEnemies + colEnemies);
                }
            }
        }
        return maxCount;
    }
};
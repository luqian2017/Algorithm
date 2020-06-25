class Solution {
public:
    /**
     * @param grid: an integer matrix
     * @return: an integer 
     */
    int numIslandCities(vector<vector<int>> &grid) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        
        int result = 0;
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
   
                int count = 0;
                if (grid[i][j] != 0) {
                    dfs(grid, i, j, count);
                    if (count > 0) result++;
                }
            }
        }
        return result;
    }
    
private:
    void dfs(vector<vector<int>> &grid, int x, int y, int & count) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        bool result = false;
        
        if (x < 0 || x >= nRow || y < 0 || y >= nCol || grid[x][y] == 0)
            return;
        
        if (grid[x][y] == 2) {
            count++;
        }
        grid[x][y] = 0;
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            dfs(grid, newX, newY, count);
        }
    }
};
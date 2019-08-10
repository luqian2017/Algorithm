class Solution {
public:
    /**
     * @param grid: a 2d boolean array
     * @param k: an integer
     * @return: the number of Islands
     */
    int numsofIsland(vector<vector<bool>> &grid, int k) {
        int nRow = grid.size();
        if (nRow == 0) return 0;
        int nCol = grid[0].size();
        visited.resize(nRow, vector<int>(nCol, 0));
        int result = 0;
        
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                if (grid[i][j] && !visited[i][j]) {
                    amount = 0;
                    dfs(grid, i, j);
                    if (amount >= k) {
                        result++;
                    }
                }
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<bool>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        
        if (visited[i][j] || !grid[i][j]) return;
        visited[i][j] = 1;
        amount++;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for (int k = 0; k < 4; ++k) {
            int newX = i + dx[k];
            int newY = j + dy[k];
            dfs(grid, newX, newY);
        }
        
    }
    int amount;
    vector<vector<int>> visited;
};
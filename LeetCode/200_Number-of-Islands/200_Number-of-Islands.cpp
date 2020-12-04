class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        int count = 0;
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = 0;
        int n_row = grid.size();
        int n_col = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int k = 0; k < 4; ++k) {
            int newX = i + dx[k];
            int newY = j + dy[k];
            if (newX >= 0 && 
                newX < n_row &&
                newY >= 0 &&
                newY < n_col &&
                grid[newX][newY] == '1') {
                dfs(grid, newX, newY);
            }
        }
    }
};
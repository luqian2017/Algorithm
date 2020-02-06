class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        vector<vector<int>> visited(rowSize, vector<int>(colSize, false));

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    v.clear();

                    helper(grid, i, j, i, j, visited);
                    result.insert(v);
                }
            }
        }
        
        return result.size();
    }

private:
    int rowSize;
    int colSize;
    set<vector<pair<int, int>>> result;
    vector<pair<int, int>> v;
        
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    
    void helper(vector<vector<int>> &grid, int origX, int origY, int x, int y, vector<vector<int>> &visited) {
        visited[x][y] = true;
        v.push_back({x - origX, y - origY});
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < rowSize && newY >= 0  && newY < colSize && !visited[newX][newY] && grid[newX][newY] == 1) {
                helper(grid, origX, origY, newX, newY, visited);
            }
        }
    }
};
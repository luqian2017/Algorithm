class Solution {
public:
    /**
     * @param map: the map
     * @return: can you reach the endpoint
     */
    bool reachEndpoint(vector<vector<int>> &grid) {
        return helper(grid, 0, 0);
    }

    vector<int> dirX = {1, -1, 0, 0};
    vector<int> dirY = {0, 0, 1, -1};

private:
    bool helper(vector<vector<int>> &grid, int x, int y) {
    
        if (grid[x][y] == 9) return true;

        for (int i = 0; i < 4; ++i) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
           
            //if reach the boundary, or already visited, or reach the obstable, go back
            if (newX < 0 || newX >= grid.size() || 
                newY < 0 || newY >= grid[0].size() ||
                grid[newX][newY] == 0) {
            
                continue;
            }
            
            //we need to add if (grid[newX][newY] == 1), otherwise, it may change the destination (=9) to 0 also.
            if (grid[newX][newY] == 1) grid[newX][newY] = 0;
    
            if (helper(grid, newX, newY)) return true;   //if (dfs(,,,) is false, cannot return now, still dfs.
        }    
        
        return false;
     }
};
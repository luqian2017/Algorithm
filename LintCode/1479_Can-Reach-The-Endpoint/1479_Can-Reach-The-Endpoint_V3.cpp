class Solution {
public:
    /**
     * @param map: the map
     * @return: can you reach the endpoint
     */
    bool reachEndpoint(vector<vector<int>> &grid) {
        return helper(grid, 0, 0);
    }

private:
    bool helper(vector<vector<int>> &grid, int x, int y) {
        if ((x == grid.size()) || (y == grid[0].size())) return false;
        
        if (grid[x][y] == 9) return true;
        
        if (grid[x][y] == 0) return false;
        
        return helper(grid, x + 1, y) || helper(grid, x, y + 1);
    }
};
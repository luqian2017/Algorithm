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
                if (grid[i][j] == 0) continue;
                if (bfs(grid, i, j)) result++;
            }
        }
        
        return result;
    }
    
private:
    //return true if it has island and the island has city
    bool bfs(vector<vector<int>> &grid, int x, int y) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        bool result = false;
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        queue<pair<int, int>> q;
        q.push({x, y});
        
        while(!q.empty()) {
            auto curNode = q.front();
            q.pop();
            if (grid[curNode.first][curNode.second] == 2) result = true;
            grid[curNode.first][curNode.second] = 0;
            for (int i = 0; i < 4; ++i) {
                int newX = curNode.first + dx[i];
                int newY = curNode.second + dy[i];
                if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size() || grid[newX][newY] == 0) continue;
                q.push({newX, newY});
            }
        }
        
        return result;
    }
};
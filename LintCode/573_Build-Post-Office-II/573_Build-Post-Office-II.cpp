
class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        if (rowSize == 0 || colSize == 0) return 0;
        gMinTotalLen = INT_MAX;
        gTotalHouseCount = 0;
        
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == 1) gTotalHouseCount++;
            }
        }
        
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == 0) bfs(grid, i, j);
        }
        
        return gMinTotalLen == INT_MAX ? -1 : gMinTotalLen;
    }
    
private:
    int gMinTotalLen;
    int gTotalHouseCount;
    void bfs(vector<vector<int>> &grid, int x, int y) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
        q.push({x, y});
        visited[x][y] = 1;
        int totalLen = 0;
        int step = 0;
        int totalHouseCount = 0;
        while(!q.empty()) {
            step++;  
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                pair<int, int> topNode = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int newX = topNode.first + dx[j];
                    int newY = topNode.second + dy[j];
                    if (newX >= 0 && newX < rowSize && newY >= 0 && newY < colSize && !visited[newX][newY]) {
                        visited[newX][newY] = 1;
                        if (grid[newX][newY] == 2) {
                            continue;
                        }
                        else if (grid[newX][newY] == 1) {
                            totalLen += step;
                            totalHouseCount++;
                        }
                        else {   
                            q.push({newX, newY});
                        }
                    }
                }
            }

        }
        
        if (gTotalHouseCount == totalHouseCount) gMinTotalLen = min(gMinTotalLen, totalLen);

        return;
    }
};
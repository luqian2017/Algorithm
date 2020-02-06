class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        set<vector<pair<int, int>>> result;
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == 0) continue;
                vector<pair<int, int>> v;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = 0;
                while(!q.empty()) {
                    pair<int, int> top = q.front();
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int newX = top.first + dx[i];
                        int newY = top.second + dy[i];
                        if (newX >= 0 && newX < rowSize && newY >= 0 && newY < colSize && grid[newX][newY] == 1) {
                            q.push({newX, newY});
                            v.push_back({newX - i, newY - j});
                        }
                    }
                }
                result.insert(v);
            }
        }
        
        return result.size();
    }
};
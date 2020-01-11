class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: The list of grid coordinates
     */
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        vector<vector<int>> result;
        queue<pair<int, int>> pacificQ, atlanticQ;
        vector<vector<bool>> pacificGrid(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticGrid(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            pacificQ.push({i, 0}); 
            pacificGrid[i][0] = 1;
            atlanticQ.push({i, n -1}); 
            atlanticGrid[i][n - 1] = 1;
        }

        for (int j = 0; j < n; ++j) {
            pacificQ.push({0, j});
            pacificGrid[0][j] = true;
            atlanticQ.push({m - 1, j});
            atlanticGrid[m - 1][j] = true;
        }

        while(!pacificQ.empty()) {
            pair<int, int> node = pacificQ.front();
            pacificQ.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = node.first + dx[i];
                int newY = node.second + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !pacificGrid[newX][newY] && matrix[node.first][node.second] <= matrix[newX][newY]) {
                    pacificQ.push({newX, newY});
                    pacificGrid[newX][newY] = true;
                }
            }
        }

        while(!atlanticQ.empty()) {
            pair<int, int> node = atlanticQ.front();
            atlanticQ.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = node.first + dx[i];
                int newY = node.second + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !atlanticGrid[newX][newY] && matrix[node.first][node.second] <= matrix[newX][newY]) {
                    atlanticQ.push({newX, newY});
                    atlanticGrid[newX][newY] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacificGrid[i][j] && atlanticGrid[i][j]) result.push_back({i,j});
            }
        }    
        return result;
    }
};
            
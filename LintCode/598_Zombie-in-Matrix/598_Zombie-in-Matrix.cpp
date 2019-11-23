class Solution {
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int round = 0;
        while(!q.empty()) {
            round++;
            bool peopleFound = false; 
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                pair<int, int> frontNode = q.front();
                q.pop();
                
                for (int j = 0; j < 4; ++j) {
                    int newX = frontNode.first + dx[j];
                    int newY = frontNode.second + dy[j];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                        q.push({newX, newY});
                        grid[newX][newY] = 1;
                        peopleFound = true;
                    }
                }
            }
            
           // if (!peopleFound) return round;
          //  round++;
        }
        
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0) return -1;
        
        return round - 1;
    }
};
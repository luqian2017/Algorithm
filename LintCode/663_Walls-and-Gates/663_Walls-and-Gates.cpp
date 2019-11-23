class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size();
        if (m == 0) return;
        int n = rooms[0].size();
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        const int INF = 2147483647;
        
        queue<pair<int, int>> q;
        
        //push the doors (in the border) to the queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) q.push({i, j});
            }
        }
       // for (int i = 0; i < m; ++i) {
    //        if (rooms[i][0] == 0) q.push({i, 0});
    //        if (rooms[i][n - 1] == 0) q.push({i, n - 1});
    //    }
    //    for (int i = 1; i < n - 1; ++i) {
    //        if (rooms[0][i] == 0) q.push({0, i});
    //        if (rooms[m - 1][i] == 0) q.push({m - 1, i});
    //    }
        
        while(!q.empty()) {
            pair<int, int> headNode = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int newX = headNode.first + dx[i];
                int newY = headNode.second + dy[i];
                if (newX >= 0 && newX <= m - 1 && newY >= 0 && newY <= n - 1 && rooms[newX][newY] == INF) {
                    q.push({newX, newY});
                    rooms[newX][newY] = rooms[headNode.first][headNode.second] + 1;
                }
            }
        }
        
        return;
    }
};
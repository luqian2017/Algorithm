struct Node {
    int x;
    int y;
    Node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 and 1
     * @return: the shortest path
     */
    int shortestPath2(vector<vector<bool>> &grid) {
        int n = grid.size();
        if (n == 0) return -1;
        int m = grid[0].size();
        if (m == 0) return -1;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> dx = {1, -1, 2, -2};
        vector<int> dy = {2, 2, 1, 1};
        
        queue<Node> q;
        q.push(Node(0, 0));
        visited[0][0] = true;
        
        int step = 0;
        while(!q.empty()) {
            int qSize = q.size();

            for (int i = 0; i < qSize; ++i) {
                Node curNode = q.front();
                q.pop();
                
                if (curNode.x == n - 1 && curNode.y == m - 1) {
                    return step;
                }
                for (int j = 0; j < 4; ++j) {
                    int newX = curNode.x + dx[j];
                    int newY = curNode.y + dy[j];
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && grid[newX][newY] != 1) {
                        q.push(Node(newX, newY));
                        visited[newX][newY] = true;
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};

struct Node {
    int x;
    int y;
    Node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

class Solution {
public:
    /**
     * @param grid: the input matrix
     * @return: the new matrix
     */
    vector<vector<int>> shortestPath(vector<vector<int>> &grid) {
        int m = grid.size();
        if (m == 0) return {};
        int n = grid[0].size();
        vector<vector<int>> rounds(m, vector<int>(n));
        vector<int> dirMarks = {2, 3, 4, 5}; //DOWN, UP, RIGHT, LEFT
        
        queue<Node> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) q.push(Node(i, j));
            }
        }
        
        vector<int> dx = {1, -1, 0, 0};   //DOWN, UP, RIGHT, LEFT
        vector<int> dy = {0, 0, 1, -1};
        int round = 0;
        while(!q.empty()) {
            int qSize = q.size();
            round++;
            for (int i = 0; i < qSize; ++i) {
                Node frontNode = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int newX = frontNode.x + dx[j];
                    int newY = frontNode.y + dy[j];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                        if (grid[newX][newY] == 0) {
                            q.push(Node(newX, newY));
                            rounds[newX][newY] = round;
                            
                            grid[newX][newY] = dirMarks[j];
                            
                        } else if ((grid[newX][newY] >= 2) && (rounds[newX][newY] == round)) {
                            
                            if (dirMarks[j] < grid[newX][newY]) { grid[newX][newY] = dirMarks[j];
                            }
                        }
                    } 
                }
                
            }
        }
        return grid;
    }
};
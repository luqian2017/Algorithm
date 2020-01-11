struct Node {
    int x;
    int y;
    Node(int row = 0, int col = 0) : x(row), y(col) {}
};

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
        queue<Node> pacificQ, atlanticQ;
        vector<vector<bool>> pacificGrid(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticGrid(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            pacificQ.push(Node(i, 0)); 
            pacificGrid[i][0] = 1;
            atlanticQ.push(Node(i, n -1)); 
            atlanticGrid[i][n - 1] = 1;
        }

        for (int j = 0; j < n; ++j) {
            pacificQ.push(Node(0, j));
            pacificGrid[0][j] = true;
            atlanticQ.push(Node(m - 1, j));
            atlanticGrid[m - 1][j] = true;
        }

        while(!pacificQ.empty()) {
            Node node = pacificQ.front();
            pacificQ.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = node.x + dx[i];
                int newY = node.y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n   
                && !pacificGrid[newX][newY] && matrix[node.x][node.y] <= matrix[newX][newY]) {
                    Node tmpNode = Node(newX, newY);
                    pacificQ.push(tmpNode);
                    pacificGrid[newX][newY] = true;
                }
            }
        }

        while(!atlanticQ.empty()) {
            Node node = atlanticQ.front();
            atlanticQ.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = node.x + dx[i];
                int newY = node.y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !atlanticGrid[newX][newY] && matrix[node.x][node.y] <= matrix[newX][newY]) {
                    Node tmpNode = Node(newX, newY);
                    atlanticQ.push(tmpNode);
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
            
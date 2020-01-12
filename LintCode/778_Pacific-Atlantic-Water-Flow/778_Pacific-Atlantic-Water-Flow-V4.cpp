struct Node {
    int x;
    int y;
    int z;
    Node(int row = 0, int col = 0, int value = 0) : x(row), y(col), z(value) {}
    bool operator < (const Node & n) const {
        if (x < n.x) return true;
        if (x == n.x && y < n.y) return true;
        if (x == n.x && y == n.y) return z < n.z;
    }
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
        //unordered_set<Node, NodeHash> pacificS, atlanticS;
        set<Node> pacificS, atlanticS;
        
        for (int i = 0; i < m; ++i) {
            pacificQ.push(Node(i, 0, matrix[i][0])); 
            pacificS.insert(Node(i, 0, matrix[i][0]));
            atlanticQ.push(Node(i, n - 1, matrix[i][n - 1]));
            atlanticS.insert(Node(i, n - 1, matrix[i][n - 1]));
        }

        for (int j = 0; j < n; ++j) {
            pacificQ.push(Node(0, j, matrix[0][j]));
            pacificS.insert(Node(0, j, matrix[0][j]));
            atlanticQ.push(Node(m - 1, j, matrix[m - 1][j]));
            atlanticS.insert(Node(m - 1, j, matrix[m - 1][j]));
        }

        while(!pacificQ.empty()) {
            Node node = pacificQ.front();
            pacificQ.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = node.x + dx[i];
                int newY = node.y + dy[i];
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    Node tmpNode = Node(newX, newY, matrix[newX][newY]);
                    if (pacificS.find(tmpNode) == pacificS.end() && matrix[node.x][node.y] <= matrix[newX][newY]) {
                            pacificQ.push(tmpNode);
                            pacificS.insert(tmpNode);
                    }
                }
            }
        }

        while(!atlanticQ.empty()) {
            Node node = atlanticQ.front();
            atlanticQ.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = node.x + dx[i];
                int newY = node.y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    Node tmpNode = Node(newX, newY, matrix[newX][newY]);
                    if (atlanticS.find(tmpNode) == atlanticS.end() && matrix[node.x][node.y] <= matrix[newX][newY]) {
                            atlanticQ.push(tmpNode);
                            atlanticS.insert(tmpNode);
                    }
                }
            }
        }

        for (auto node : pacificS) {
            if (atlanticS.find(node) != atlanticS.end()) {
                result.push_back({node.x, node.y});
            }
        }
        
        return result;
    }
};
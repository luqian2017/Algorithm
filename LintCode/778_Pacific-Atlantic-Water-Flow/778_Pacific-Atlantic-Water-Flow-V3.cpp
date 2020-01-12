struct Node {
    int x;
    int y;
    Node(int row = 0, int col = 0) : x(row), y(col) {}
    bool operator == (const Node & n) const {
        return x == n.x && y == n.y;
    }
};

struct NodeHash {
    int operator() (const Node & n) const {
        return n.x * 33 + n.y;
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
        unordered_set<Node, NodeHash> pacificS, atlanticS;
        
        for (int i = 0; i < m; ++i) {
            pacificQ.push(Node(i, 0)); 
            pacificS.insert(Node(i, 0));
            atlanticQ.push(Node(i, n - 1));
            atlanticS.insert(Node(i, n - 1));
        }

        for (int j = 0; j < n; ++j) {
            pacificQ.push(Node(0, j));
            pacificS.insert(Node(0, j));
            atlanticQ.push(Node(m - 1, j));
            atlanticS.insert(Node(m - 1, j));
        }

        while(!pacificQ.empty()) {
            Node node = pacificQ.front();
            pacificQ.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = node.x + dx[i];
                int newY = node.y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && pacificS.find(Node(newX, newY)) == pacificS.end() && matrix[node.x][node.y] <= matrix[newX][newY]) {
                    pacificQ.push(Node(newX, newY));
                    pacificS.insert(Node(newX, newY));
                }
            }
        }

        while(!atlanticQ.empty()) {
            Node node = atlanticQ.front();
            atlanticQ.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = node.x + dx[i];
                int newY = node.y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && atlanticS.find(Node(newX, newY)) == atlanticS.end() && matrix[node.x][node.y] <= matrix[newX][newY]) {
                    atlanticQ.push(Node(newX, newY));
                    atlanticS.insert(Node(newX, newY));
                }
            }
        }
        
        for (auto node : pacificS) {
        //for (auto it = pacificS.begin(); it != pacificS.end(); ++it) {
            if (atlanticS.find(node) != atlanticS.end()) {
                result.push_back({node.x, node.y});
            }
        }
        
        return result;
    }
};
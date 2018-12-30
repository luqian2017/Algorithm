struct Node {
    int row;
    int col;
    int height;
    Node(int x, int y, int z) : row(x), col(y), height(z) {}
    bool operator < (const Node & node) const {
        return height < node.height;
    }
};

class Solution {
public:
    /**
     * @param forest: a list of integers
     * @return: return a integer
     */
    int cutOffTree(vector<vector<int>> &forest) {
        if (forest.size() == 0) return 0;
        int lenR = forest.size();
        int lenC = forest[0].size();
        vector<Node> trees;
        
        for (int i = 0; i < lenR; ++i) {
            for (int j = 0; j < lenC; ++j) {
                int val = forest[i][j];
                if ((val != 0) && (val != 1))
                    trees.push_back(Node(i, j, val));
            }
        }
        
        sort(trees.begin(), trees.end());
        int len = trees.size() - 1; // one less than the trees size
        int result = 0;
        
        Node node0 = Node(0, 0, forest[0][0]);
        
        result += bfs(forest, node0, trees[0]);
        for (int i = 0; i < len; ++i) {
            int steps = bfs(forest, trees[i], trees[i + 1]);
            if (steps == -1) 
                return -1;
            else 
                result += steps;      
        }
        
        return result;
    }

private:
    int bfs(vector<vector<int>> &forest, Node &src, Node &dest) {
        //down, left, up, right
        vector<int> dirR = {1, 0, -1, 0}; //col 
        vector<int> dirC = {0, -1, 0, 1}; //row 
        
        //each time of bfs, the visited map needs reset
        vector<vector<int>> visited(forest.size(), vector<int>(forest[0].size(), 0));
        
        queue<Node> q;
        q.push(src);
        
        int steps = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                Node n = q.front();
                q.pop();

                if ((n.row == dest.row) && (n.col == dest.col)) {
                    forest[dest.row][dest.col] = 1;
                    return steps;
                }
                
                for (int j = 0; j < 4; ++j) {
                    int r = n.row + dirR[j];
                    int c = n.col + dirC[j];
    
                    if ((r >= 0 && r < forest.size()) &&
                        (c >= 0 && c < forest[0].size()) &&
                        (forest[r][c] > 0) && (visited[r][c] == 0)) {
                        
                        Node neighbor = Node(r, c, forest[r][c]);
                        q.push(neighbor);
                        //should not set the neighbor.height = 1 here as it will be accessed in the following bfs calls
                        visited[r][c] = 1;
                    }
                }
            }
            
            steps++;
        }   
        
        return -1;
    }

};
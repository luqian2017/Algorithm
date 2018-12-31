struct Node {
    int x;
    int y;
    Node(int row, int col) : x(row), y(col) {}
    bool operator < (const Node & node) const {
        return (x < node.x) || ((x == node.x) && (y < node.y));
    }
};

class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the number of distinct islands
     */
    int numDistinctIslands2(vector<vector<int>> &grid) {
        nRow = grid.size();
        nCol = grid[0].size();
        set<vector<Node>> islands;
        
        for (int r = 0; r < nRow; ++r) {
            for (int c = 0; c < nCol; ++c) {
                if (grid[r][c] == 1) {
                    vector<Node> island;
                    Node src = Node(r, c);  //Node src(r, c) is also OK
                    Node dest(src);
                    dfs(grid, src, dest, island);
                    islands.insert(normalize(island));
                }
            }
        }
        return islands.size();
    }
    
private:
    int nRow;
    int nCol;


    void dfs(vector<vector<int>> &grid, Node &src, Node &dest, vector<Node> &island) {
        //left, down, right, up
        vector<int> dirX = {-1, 0, 1, 0}; //row
        vector<int> dirY = {0, -1, 0, 1}; //col
        int x = dest.x;
        int y = dest.y;
        if ((x >= 0) && (x < nRow) && (y >= 0) && (y < nCol) && (grid[x][y] > 0)) {
            grid[x][y] = 0;
            island.push_back(Node(x,y));
            for (int i = 0; i < 4; ++i) {
                Node neighbor = Node(dest.x + dirX[i], dest.y + dirY[i]);
                dfs(grid, src, neighbor, island);
            }
        }
    }
    
    vector<Node> normalize(vector<Node> &island) {
        vector<vector<Node>> result(8, vector<Node>());
        for (auto i : island) {
            int x = i.x, y = i.y;
            result[0].push_back(Node(x, y));
            result[1].push_back(Node(x, -y));
            result[2].push_back(Node(-x, y));
            result[3].push_back(Node(-x, -y));
            result[4].push_back(Node(y, x));
            result[5].push_back(Node(y, -x));
            result[6].push_back(Node(-y, x));
            result[7].push_back(Node(-y, -x));
        }
        
        for (int i = 0; i < 8; ++i) {
            sort(result[i].begin(), result[i].end());
            int len = result[i].size();
            int offsetCol = result[i][0].x;
            int offsetRow = result[i][0].y;
            for (int j = 0; j < len; ++j) {
                result[i][j].x -= offsetCol;
                result[i][j].y -= offsetRow;
            }
        }
        sort(result.begin(), result.end());
        return result[0];
    }

};
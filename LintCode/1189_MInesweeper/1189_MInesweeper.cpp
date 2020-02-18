class Solution {
public:
    /**
     * @param board: a board
     * @param click: the position
     * @return: the new board
     */
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        if (m == 0 || n == 0) return {};
        
        queue<pair<int, int>> q;
        q.push({click[0], click[1]});
        
        while(!q.empty()) {
            pair<int, int> curNode = q.front();
            q.pop();
            int mineCount = 0;
            int x = curNode.first, y = curNode.second;
            if (board[x][y] == 'M') {
                board[x][y] = 'X';
                return board;
            }
            
            vector<pair<int, int>> neighborNodes;
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int newX = x + i;
                    int newY = y + j;
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
                    if (board[newX][newY] == 'M') mineCount++;
                    else if (board[newX][newY] == 'E') neighborNodes.push_back({newX, newY});
                }
            }
            
            if (mineCount > 0) {
                board[x][y] = mineCount + '0';
            } else {
                for (auto n : neighborNodes) {
                    board[n.first][n.second] = 'B';
                    q.push(n);
                }
            }
        }
        return board;
    }
};
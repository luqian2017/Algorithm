struct Node {
    int x;
    int y;
    Node(int _x, int _y) : x(_x), y(_y) {}
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        n_row = board.size();
        if (n_row == 0) return;
        n_col = board[0].size();

        for (int i = 0; i < n_col; i++) {
            if (board[0][i] == 'O') bfs(board, Node(0, i));
            if (board[n_row - 1][i] == 'O') bfs(board, Node(n_row - 1, i));
        }

        for (int i = 0; i < n_row; i++) {
            if (board[i][0] == 'O') bfs(board, Node(i, 0));
            if (board[i][n_col - 1] == 'O') bfs(board, Node(i, n_col - 1));
        }

        for (int i = 1; i < n_row - 1; ++i) {
            for (int j = 1; j < n_col - 1; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        for (int i = 0; i < n_row; ++i) {
            for (int j = 0; j < n_col; ++j) {
                if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }

private:
    void bfs(vector<vector<char>>& board, Node n) {
        queue<Node> q;
        board[n.x][n.y] = 'Y';
        q.push(n);
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        while (!q.empty()) {
            Node currNode = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = currNode.x + dx[i];
                int newY = currNode.y + dy[i];
                if (newX < 0 || newX >= n_row || newY < 0 || newY >= n_col || board[newX][newY] != 'O') continue;
                board[newX][newY] = 'Y';
                q.push(Node(newX, newY));
            }
        }
    }
    int n_row;
    int n_col;
};
class Solution {
public:
    /**
     * @param board: the sudoku puzzle
     * @return: nothing
     */
    void solveSudoku(vector<vector<int>> &board) {
        dfs(board, 0, 0);
    }
    
private:
    bool dfs(vector<vector<int>> &board, int x, int y) {
        if (x >= 9) return true;
        if (y >= 9) {
            return dfs(board, x + 1, 0);
        }
    
        //skip the unit if it already has a number
        if (board[x][y] != 0) {
            return dfs(board, x, y + 1);
        }
            
        for (int i = 1; i <= 9; ++i) {
            board[x][y] = i;
        
            if (validSudoku(board, x, y, i)) {
                if (dfs(board, x, y + 1)) return true;
            }
            board[x][y] = 0;
        }
        
        return false;
    }

    bool validSudoku(vector<vector<int>> &board, int x, int y, int num) {
        for (int i = 0; i < 9; ++i) {
            if (i != x && board[i][y] == num) return false;
            if (i != y && board[x][i] == num) return false;
        }
        int startX = x / 3 * 3;
        int startY = y / 3 * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int newX = startX + i;
                int newY = startY + j;
                if (newX != x && newY != y && board[newX][newY] == num) return false;
            }
        }
        
        return true;
    }
};
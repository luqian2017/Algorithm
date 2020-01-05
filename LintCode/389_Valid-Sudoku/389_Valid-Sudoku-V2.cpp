class Solution {
public:
    /**
     * @param board: the board
     * @return: whether the Sudoku is valid
     */
    bool isValidSudoku(vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();
        if (m != 9 || n !=9) return false;
        vector<vector<bool>> rowsFlag(9, vector<bool>(9));
        vector<vector<bool>> colsFlag(9, vector<bool>(9));
        vector<vector<bool>> cellsFlag(9, vector<bool>(9));
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int cellIndex = (i / 3) * 3 + j / 3; // the x-th small grid
                int num = board[i][j] - '1';
                if (rowsFlag[i][num] || colsFlag[j][num] || cellsFlag[cellIndex][num]) return false;
                rowsFlag[i][num] = true;
                colsFlag[j][num] = true;
                cellsFlag[cellIndex][num] = true;
            }
        }
        
        return true;
    }
};
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
        
        unordered_map<char, int> um;   //number, count
        for (int i = 0; i < 9; ++i) {
            um.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] >= '0' && board[i][j] <= '9' && um[board[i][j]]++ > 0) {
                    return false;
                }
            }
        //    if (um.size() != 9) return false;        
        }

        for (int i = 0; i < 9; ++i) {
            um.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] >= '0' && board[j][i] <= '9' && um[board[j][i]]++ > 0) {
                    return false;
                }
            }
       //     if (um.size() != 9) return false;        
        }

        vector<unordered_set<int>> gridArray(9); //gridIndex, number
        
        for (int i = 0; i < 9; ++i) {
            //um.clear();
            for (int j = 0; j < 9; ++j) {
                int gridIndex = (i / 3) * 3 + j / 3; // the x-th small grid

                if (board[i][j] >= '0' && board[i][j] <= '9' && gridArray[gridIndex].find(board[i][j]) != gridArray[gridIndex].end())) {
                    return false;
                } else {
                    gridArray[gridIndex].insert(board[i][j]);
                }
            }
          //  if (um.size() != 9) return false;
        }
        
        return true;
    }
};
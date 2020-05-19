class Solution {
public:
    /**
     * @param board: the given board
     * @return: nothing
     */
    void gameOfLife(vector<vector<int>> &board) {
        int nRow = board.size();
        if (nRow == 0) return;
        
        int nCol= board[0].size();
        if (nCol == 0) return;
        
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                int liveNeighborCount = 0;
                for (int k = 0; k < 8; ++k) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    if (newX >= 0 && newX < nRow && newY >= 0 && newY < nCol) {
                        if (board[newX][newY] & 0x1) liveNeighborCount++;
                    }
                }

                if (board[i][j] == 1 && 
                    (liveNeighborCount < 2 || liveNeighborCount > 3)) board[i][j] = 0x3;
                
                if (board[i][j] == 0 && 
                    liveNeighborCount == 3) board[i][j] = 0x2;    
            }
        }
        
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                if (board[i][j] == 0x3) board[i][j] = 0;
                else if (board[i][j] == 0x2) board[i][j] = 1;
            }
        }
        
        return;
    }
};
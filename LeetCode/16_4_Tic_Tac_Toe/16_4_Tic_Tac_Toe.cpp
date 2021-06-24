class Solution {
public:
    string tictactoe(vector<string>& board) {
        int n = board.size();

        bool diagHasNonXChar = false, diagHasNonOChar = false;
        bool revDiagHasNonXChar = false, revDiagHasNonOChar =false;
        bool soFarFull = true;

        for (int i = 0; i < n; ++i) {
            bool rowHasNonXChar = false, rowHasNonOChar = false;
            bool colHasNonXChar = false, colHasNonOChar = false;
            for (int j = 0; j < n; ++j) {
                if (soFarFull && board[i][j] == ' ') {
                    soFarFull = false;
                 //   continue; 
                } 
                if (!rowHasNonXChar) rowHasNonXChar |= board[i][j] ^ 'X';
                if (!rowHasNonOChar) rowHasNonOChar |= board[i][j] ^ 'O';
                if (!colHasNonXChar) colHasNonXChar |= board[j][i] ^ 'X';
                if (!colHasNonOChar) colHasNonOChar |= board[j][i] ^ 'O'; 
            }

            if (!rowHasNonXChar || !colHasNonXChar) return "X";
            if (!rowHasNonOChar || !colHasNonOChar) return "O";
            
            if (!diagHasNonXChar) diagHasNonXChar |= board[i][i] ^ 'X';
            if (!diagHasNonOChar) diagHasNonOChar |= board[i][i] ^ 'O';
            if (!revDiagHasNonXChar) revDiagHasNonXChar |= board[i][n - i - 1] ^ 'X';
            if (!revDiagHasNonOChar) revDiagHasNonOChar |= board[i][n - i - 1] ^ 'O';
        }
        if (!diagHasNonXChar || !revDiagHasNonXChar) return "X";
        if (!diagHasNonOChar || !revDiagHasNonOChar) return "O";
        if (soFarFull) return "Draw";
        return "Pending";
    }
};

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        
        vector<int> sum_row_X(3), sum_row_O(3), sum_col_X(3), sum_col_O(3);
        int sum_diag_X = 0, sum_diag_O = 0, sum_revdiag_X = 0, sum_revdiag_O = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 0x1) { //O
                sum_row_O[moves[i][0]]++; 
                sum_col_O[moves[i][1]]++;
                if (moves[i][0] == moves[i][1]) sum_diag_O += 1;
                if (moves[i][0] + moves[i][1] == 2) sum_revdiag_O += 1;
                if (sum_row_O[moves[i][0]] == 3 || sum_col_O[moves[i][1]] == 3 || sum_diag_O == 3 || sum_revdiag_O == 3) return "B";
                
            } else { //X
                sum_row_X[moves[i][0]]++; 
                sum_col_X[moves[i][1]]++;
                if (moves[i][0] == moves[i][1]) sum_diag_X += 1;
                if (moves[i][0] + moves[i][1] == 2) sum_revdiag_X += 1;
                if (sum_row_X[moves[i][0]] == 3 || sum_col_X[moves[i][1]] == 3 || (sum_diag_X == 3) || sum_revdiag_X == 3) return "A";
            }
        }
        if (n == 9) return "Draw";
        else return "Pending";
    }
};
class Solution {
public:
    /**
     * @param queen: queen‘coordinate
     * @param knight: knight‘coordinate
     * @return: if knight is attacked please return true，else return false
     */
    vector<bool> isAttacked(vector<vector<int>> &queen, vector<vector<int>> &knight) {
        int len_q = queen.size();
        int len_k = knight.size();
        vector<bool> result(len_k, true);
        unordered_set<int> row_set;
        unordered_set<int> col_set;
        unordered_set<int> diag_set;
        unordered_set<int> rev_diag_set;
        
        for (int i = 0; i < len_q; ++i) {
            row_set.insert(queen[i][0]);
            col_set.insert(queen[i][1]);
            diag_set.insert(queen[i][0] - queen[i][1]);
            rev_diag_set.insert(queen[i][0] + queen[i][1]);
        }
        
        for (int i = 0; i < len_k; ++i) {
            if (row_set.find(knight[i][0]) == row_set.end() &&
                col_set.find(knight[i][1]) == col_set.end() &&
                diag_set.find(knight[i][0] - knight[i][1]) == diag_set.end() &&
                rev_diag_set.find(knight[i][0] + knight[i][1]) == rev_diag_set.end())
            
            result[i] = false;    
        }
        
        return result;
    }
};
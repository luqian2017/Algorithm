class Solution {
public:
    /**
     * @param matrix: A lsit of lists of integers
     * @return: nothing
     */
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        
        unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }        
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (zeroRows.find(i) != zeroRows.end() || zeroCols.find(j) != zeroCols.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        return;
    }
};
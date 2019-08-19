class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int nRow = matrix.size();
        if (nRow == 0) return;
        int nCol = matrix[0].size();
        prefixes.resize(nRow, vector<int>(nCol, 0));
        
        prefixes[0][0] = matrix[0][0];
        for (int i = 1; i < nRow; ++i) {
            prefixes[i][0] = prefixes[i - 1][0] + matrix[i][0];
        }
        for (int i = 1; i < nCol; ++i) {
            prefixes[0][i] = prefixes[0][i - 1] + matrix[0][i];
        }
        
        for (int i = 1; i < nRow; ++i) {
            for (int j = 1; j < nCol; ++j) {
                prefixes[i][j] = prefixes[i][j - 1] + prefixes[i - 1][j] - prefixes[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1 = prefixes[row2][col2];
        int sum2 = col1 == 0 ? 0 : prefixes[row2][col1 - 1];
        int sum3 = row1 == 0 ? 0 : prefixes[row1 - 1][col2];
        int sum4 = (row1 == 0 || col1 == 0) ? 0 : prefixes[row1 - 1][col1 - 1];

        return sum1 - sum2 - sum3 + sum4;
    }
    
private:
    vector<vector<int>> prefixes;
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
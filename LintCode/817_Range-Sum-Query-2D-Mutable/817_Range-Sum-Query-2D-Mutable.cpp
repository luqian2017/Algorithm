class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        nRow = matrix.size();
        nCol = matrix[0].size();
        A = matrix;
        C.resize(nRow + 1, vector<int>(nCol + 1, 0));
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                add(i, j, A[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        add(row, col, val - A[row][col]);
        A[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2, col2) - sum(row1 - 1, col2) - sum(row2, col1 - 1) + sum(row1 - 1, col1 - 1);
    }
    
private:
    vector<vector<int>> C, A;
    int nRow, nCol;
    
    int lowbit(int x) {
        return x & -x;
    }
    
    int sum(int x, int y) {
        int result = 0;
        x++; y++;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                result += C[i][j];
            }
        }
        return result;
    }
    
    void add(int x, int y, int val) {
        x++; y++;
        //int delta = val - A[x][y];
        for (int i = x; i <= nRow; i += lowbit(i)) {
            for (int j = y; j <= nCol; j += lowbit(j)) {
                C[i][j] += val;
            }
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
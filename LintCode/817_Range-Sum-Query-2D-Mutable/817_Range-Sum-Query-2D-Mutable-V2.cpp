class BinaryIndexTree {
public:
    vector<vector<int>> C;
    vector<vector<int>> A;
    int nRow;
    int nCol;

    BinaryIndexTree(vector<vector<int>> & matrix) {
        nRow = matrix.size();
        nCol = matrix[0].size();
        A = matrix;
        C.resize(nRow + 1, vector<int>(nCol + 1));
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                add(i, j, matrix[i][j]);
            }
        }
    }

    int presum(int x, int y) {
        x++;
        y++;
        int result = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                result += C[i][j];
            }
        }
        return result;
    }

    void add(int x, int y, int val) {
        x++;
        y++;
        for (int i = x; i <= nRow; i += lowbit(i)) {
            for (int j = y; j <= nCol; j += lowbit(j)) {
                C[i][j] += val;
            }
        }
    }

private:
    int lowbit(int x) {
        return x & (-x);
    }

};

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        //Bit = BinaryIndexTree::BinaryIndexTree(matrix);   //???
        pBit = new BinaryIndexTree(matrix);
    }
    
    void update(int row, int col, int val) {
        pBit->add(row, col, val - pBit->A[row][col]);
        pBit->A[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (pBit->presum(row2, col2) - pBit->presum(row1 - 1, col2) - pBit->presum(row2, col1 - 1) + pBit->presum(row1 - 1, col1 - 1));
    }
private:
    BinaryIndexTree * pBit;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
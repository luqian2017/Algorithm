class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        int nRow = matrix.size();
        if (nRow == 0) return 0;
        int nCol = matrix[0].size();
        if (nCol == 0) return 0;
        int totalNum = nRow * nCol;   
        int res = 0;
        int row = 0, col = nCol - 1, cnt = 0;
        while (cnt < totalNum) {
            if (matrix[row][col] == target) {
                res++;
                if (row < nRow - 1) row++;
                else break;
            } else if (matrix[row][col] < target) {
                if (row < nRow - 1) row++;
            } else {
                if (col > 0) col--;
            }
            cnt++;
        }
        return res;
    } 
};
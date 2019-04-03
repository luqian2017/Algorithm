class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        int start = 0, end = m * n - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] < target) {
                start = mid;
            } else if (matrix[row][col] > target) {
                end = mid;
            } else {
                return true;
            }
        }
        if (matrix[start / n][start % n] == target) return true;
        if (matrix[end / n][end % n] == target) return true;
        return false;
    }
};
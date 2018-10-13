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
        int count = 0;
        int rowIndex = 0;
        int colIndex = nCol - 1;  //start from the right top point
        
        while (rowIndex < nRow && colIndex >= 0) {
            if (matrix[rowIndex][colIndex] > target) {
                colIndex--;
            } else if (matrix[rowIndex][colIndex] < target) {
                rowIndex++;
            } else {
                count++;
                colIndex--;
                rowIndex++;
            }
        }
    
        return count;    
    }
};
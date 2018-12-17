class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int nRow = matrix.size();
        if (nRow == 0) return false;
        int nCol = matrix[0].size();
        
        if ((target < matrix[0][0]) || (target > matrix[nRow - 1][nCol - 1])) return false;
        
        vector<int> col0(nRow, 0);
        
        for (int i = 0; i < nRow; ++i) {
            col0[i] = matrix[i][0];
        }
        

        int indexRow = binarySearch(col0, 0, nRow - 1, target);

        int indexCol = binarySearch(matrix[indexRow], 0, nCol - 1, target);

        if (target == matrix[indexRow][indexCol]) return true;
        else return false;
    }
    
    // find the index of the first element that is smaller or equal to target
    int binarySearch(vector<int> nums, int start, int end, int target) {
        if (nums.size() == 0 || start > end) return -1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else { 
                end = mid;
            }
        }
        
        if (nums[start] == target) return start;
        if (nums[end] == target) return end;

        if (nums[end] < target) return end;        
        if (nums[start] < target) return start;
        return -1;
    } 
};

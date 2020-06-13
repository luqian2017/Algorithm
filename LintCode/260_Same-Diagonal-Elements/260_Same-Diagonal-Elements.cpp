class Solution {
public:
    /**
     * @param matrix: a matrix
     * @return: return true if same.
     */
bool judgeSame(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> newMatrix(n, vector<int>(n)), newSymmMatrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            newMatrix[i] = matrix[n - 1 - i];
        } 
        //transpose
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                newSymmMatrix[i][j] = newMatrix[j][i];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (newMatrix[i][j] != newSymmMatrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    /**
     * @param matrix: a matrix
     * @return: return true if same.
     */
bool judgeSame(vector<vector<int>> &matrix) {

        int n = matrix.size();

        vector<vector<int>> symmMatrix(n, vector<int>(n));
        reverse(matrix.begin(), matrix.end());

        //transpose
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                symmMatrix[i][j] = matrix[j][i];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != symmMatrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

};
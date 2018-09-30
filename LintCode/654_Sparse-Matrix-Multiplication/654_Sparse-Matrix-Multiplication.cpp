class Solution {
public:
    /**
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        int ARowSize = A.size();
        int AColSize = A[0].size();
        int BRowSize = B.size();
        int BColSize = B[0].size();
        
        vector<vector<int>> result;
        result.resize(ARowSize, vector<int>(BColSize, 0));
        
        for (int i = 0; i < ARowSize; ++i) {
            for (int j = 0; j < BColSize; ++j) {
                for (int k = 0; k < AColSize; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return result;
    }
};
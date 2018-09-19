class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: the largest possible sum
     */
    int maxSubmatrix(vector<vector<int>> &matrix) {
        int result = INT_MIN;
        int currSum = INT_MIN;
        int nRow = matrix.size();
        if (nRow == 0) return 0;
    
        int nCol = matrix[0].size(); 
        
        preProcess(matrix);

        vector<int> diff(nCol, 0);

        for (int i = 0; i < nRow; ++i) {
            for (int j = i; j < nRow; ++j) {
                for (int k = 0; k < nCol; ++k) {
                    diff[k] = preSumMatrix[j + 1][k] - preSumMatrix[i][k];
                }
                result = max(result, maxSubarray(diff));
            }    
        }
        
        return result;
    }
    
        
private:
   int maxSubarray(vector<int> &vec) {
       int result = INT_MIN;
       int sum = 0;
       
       for (int i = 0; i < vec.size(); ++i) {
           if ((sum + vec[i]) < vec[i]) 
               sum = vec[i];
           else
               sum += vec[i];
           if (result < sum) result = sum;
       }
       
       return result;
   }
    
   void preProcess(vector<vector<int>> &matrix) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        preSumMatrix.resize(nRow + 1, vector<int>(nCol, 0));
    
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                preSumMatrix[i + 1][j] = preSumMatrix[i][j] + matrix[i][j];
            }
        } 
   }
   
   vector<vector<int>> preSumMatrix;
};
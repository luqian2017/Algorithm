class Solution {
public:
    /**
     * @param M: a 2D integer matrix
     * @return: a 2D integer matrix
     */
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        int rowSize = M.size();
        if (rowSize == 0) return {};
        int colSize = M[0].size();
        if (colSize == 0) return {};
        
        vector<vector<int>> M2(rowSize, vector<int>(colSize));
        
        vector<int> dx = {-1, -1, 1, 1, 0, 0, 1, -1};
        vector<int> dy = {-1, 1, -1, 1, -1, 1, 0, 0};
        
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                int sum = M[i][j];
                int count = 1; //remember to count itself
                for (int k = 0; k < 8; ++k) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    
                    if (newX >= 0 && newX < rowSize && newY >= 0 && newY < colSize) {
                        count++;
                        sum += M[newX][newY];
                    }
                }
                M2[i][j] = sum / count;
            }
        }
    
        return M2;
    }
};
class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        vector<vector<int>> A;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        A.resize(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            } 
            A[i][0] = 1;
        }
        
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            A[0][j] = 1;
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                
                if (obstacleGrid[i][j] == 1) {
                    A[i][j] == 0;     
                } else {
                    A[i][j] = A[i - 1][j] + A[i][j - 1];
                }
            }
        }
        
        return A[m - 1][n - 1];
    }
};
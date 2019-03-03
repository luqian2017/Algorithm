class Solution {
public:
    /**
     * @param matrix: A 2D-array of integers
     * @return: an integer
     */
    int longestContinuousIncreasingSubsequence2(vector<vector<int>> &matrix) {
        const int n = matrix.size();
        if (n == 0) return 0;
        
        const int m = matrix[0].size();
        f.resize(n, vector<int>(m, 1));
        visited.resize(n, vector<bool>(m, false));
        gMaxLen = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                helper(matrix, i, j);        
                gMaxLen = max(gMaxLen, f[i][j]);
            }
        }
        
        return gMaxLen;
    }

private:
    void helper(vector<vector<int>> &matrix, int x, int y) {
        vector<int> dirX = {1, -1, 0, 0};
        vector<int> dirY = {0, 0, 1, -1};
        const int n = matrix.size();
        const int m = matrix[0].size();
        
        if (!visited[x][y]) {
            visited[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                if ((newX >= 0) && (newX < n) && (newY >= 0) && (newY < m)) {
                    if (matrix[newX][newY] > matrix[x][y]) {
                        helper(matrix, newX, newY);
                        f[x][y] = max(f[x][y], f[newX][newY] + 1);
                    }
                }
            }
        }
    }
    
    int gMaxLen;
    vector<vector<int>> f;
    vector<vector<bool>> visited;
};
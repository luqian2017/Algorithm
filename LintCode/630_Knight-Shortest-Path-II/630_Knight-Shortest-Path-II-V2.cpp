class Solution {
public:
    /**
     * @param grid: a chessboard included 0 and 1
     * @return: the shortest path
     */
    int shortestPath2(vector<vector<bool>> &grid) {
        int n = grid.size();
        if (n == 0) return -1;
        int m = grid[0].size();
        if (m == 0) return -1;
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = 0;
        
        vector<int> dx = {1, -1, 2, -2};
        vector<int> dy = {2, 2, 1, 1};
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (!grid[i][j]) { 
                    for (int k = 0; k < 4; ++k) {
                        int newX = i - dx[k];
                        int newY = j - dy[k];
                        if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] != 1 && dp[newX][newY] != INT_MAX) {
                                dp[i][j] = min(dp[i][j], dp[newX][newY] + 1);
                            }
                    }
                }
            }
        }
        
        return dp[n - 1][m - 1] == INT_MAX ? -1 : dp[n - 1][m - 1];
    }
};
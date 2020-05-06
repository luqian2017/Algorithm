class Solution {
public:
    /**
     * @param dungeon: a 2D array
     * @return: return a integer
     */
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int nRow = dungeon.size();
        int nCol = dungeon[0].size();
        
        vector<vector<int>> dp(nRow + 1, vector<int>(nCol + 1, INT_MAX));
        dp[nRow][nCol - 1] = 1;
        dp[nRow - 1][nCol] = 1;
        
        for (int i = nRow - 1; i >= 0; --i) {
            for (int j = nCol - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};
class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        if (nRow == 0 || nCol == 0) return 0;
        left2RightDist.resize(nRow, vector<int>(nCol, 0));
        right2LeftDist = left2RightDist;
        left2RightCount = left2RightDist;
        right2LeftCount = left2RightDist;

        //preprocessing  
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                int tmpCount = (j == 0) ? 0 : left2RightCount[i][j - 1];
                left2RightCount[i][j] = (grid[i][j] == 1) ? tmpCount + 1 : tmpCount;
                int tmpDist = (j == 0) ? 0 : left2RightDist[i][j - 1];
                left2RightDist[i][j] = tmpDist + left2RightCount[i][j] - 
                                       ((grid[i][j] == 1) ? 1 : 0);
            }
            for (int j = nCol - 1; j >= 0; --j) {
                int tmpCount = (j == nCol - 1) ? 0 : right2LeftCount[i][j + 1];
                right2LeftCount[i][j] = (grid[i][j] == 1) ? tmpCount + 1 : tmpCount;
                int tmpDist = (j == nCol - 1) ? 0 : right2LeftDist[i][j + 1];
                right2LeftDist[i][j] = tmpDist + right2LeftCount[i][j] -
                                       ((grid[i][j] == 1) ? 1 : 0);
            }
        }
    
        int minTotalDis = INT_MAX;
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                if (grid[i][j] == 0) {
                    int distSum = 0, countSum = 0;
                    for (int k = 0; k < nRow; ++k) {
                        countSum = left2RightCount[k][j] + 
                                     right2LeftCount[k][j] - 
                                     ((grid[k][j] == 1) ? 1 : 0);

                        int tempSum = left2RightDist[k][j] + 
                                   right2LeftDist[k][j]; 

                        distSum += tempSum + countSum * abs(i - k);
                    }
                    minTotalDis = min(minTotalDis, distSum);
                }
            }
        }
        
        return minTotalDis;
    }

private:
    int nRow, nCol;
    vector<vector<int>> left2RightDist, right2LeftDist;
    vector<vector<int>> left2RightCount, right2LeftCount;
};
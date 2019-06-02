class Solution {
public:
    /**
     * @param grid: the grid
     * @return: the number of corner rectangles
     */
    int countCornerRectangles(vector<vector<int>> &grid) {
        int M = grid.size(); // # of rows
        if (M <= 1) return 0;
        
        int N = grid[0].size(); // # of cols
        int result = 0;
        for (int i = 0; i < M - 1; ++i) {

            for (int j = i + 1; j < M; ++j) {
                vector<int> mergeRow(N, 0);
                int count = 0;
                for (int k = 0; k < N; ++k) {
                    if (grid[i][k] == 1 && grid[j][k] == 1) {
                        mergeRow[k] = 1;
                        count++;
                    }
                }
                result += count * (count - 1) / 2;
            } 
        }
        
        return result;
    }
};
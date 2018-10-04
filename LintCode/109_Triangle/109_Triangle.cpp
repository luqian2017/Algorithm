class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        int len = triangle.size();

        vector<vector<int>> DP;
        DP.resize(len);

        if (triangle.size() == 1) return triangle[0][0];
        
        DP[0] = vector<int>(1, triangle[0][0]);
        
        for (int i = 1; i < len; ++i) {
            DP[i].resize(triangle[i].size());
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    DP[i][j] = DP[i - 1][j] + triangle[i][j];
                } else if (j < triangle[i].size() - 1) {
                    DP[i][j] = min(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j];
                } else {
                    DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
                }
            }
            
        }
        
        int minSum = INT_MAX;
        for (int j = 0; j < triangle[len -1].size(); ++j) {
            if (DP[len - 1][j] < minSum) 
                minSum = DP[len - 1][j];
        }
        
        return minSum;
    }
};
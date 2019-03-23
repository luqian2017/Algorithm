class Solution {
public:
    /**
     * @param matrix: an integer array of n * m matrix
     * @param k: An integer
     * @return: the maximum number
     */
    int maxSlidingMatrix(vector<vector<int>> &matrix, int k) {
        int m = matrix.size();
        if (m < k) return 0;
        int n = matrix[0].size();
        if (n < k) return 0;
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        int result = INT_MIN;
        for (int i = k; i <= m; ++i) {
            for (int j = k; j <= n; ++j) {
                result = max(result, sums[i][j] - sums[i - k][j] - sums[i][j - k] + sums[i - k][j - k]);
            }
        }
        
        return result;
    }
};
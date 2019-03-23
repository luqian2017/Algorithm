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
        vector<vector<int>> accums(m - k + 1, vector<int>(n, 0));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                accums[0][j] += matrix[i][j];
            }
        }

        for (int i = 1; i <= m - k; ++i) {
            for (int j = 0; j < n; ++j) {
                accums[i][j] = accums[i - 1][j] - matrix[i - 1][j] + matrix[i + k - 1][j];
            }
        }
        
        int maxSum = INT_MIN;
        for (int i = 0; i < m - k + 1; ++i) {
            maxSum = max(maxSum, maxFixSizeSubArray(accums[i], k));
        }
        return maxSum;
    }

private:
    int maxFixSizeSubArray(vector<int> & nums, int k) {
        int n = nums.size();
        if (n < k) return 0;
        int sum = 0, maxSum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        maxSum = sum;
        for (int i = 1; i < n - k + 1; ++i) {
            sum += nums[k + i - 1] - nums[i - 1];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
    
};
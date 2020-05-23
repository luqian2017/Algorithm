class Solution {
public:
    /**
     * @param n: the number of buckets
     * @param k: the maximum times of operations
     * @param A: the number of balls in each bucket
     * @param W: the maximum capacity of each bucket
     * @return: return the minimum square value of the maximum difference
     */
    int getAns(int n, int k, vector<int> &A, vector<int> &W) {
        int result = INT_MAX;
        int start = 0, end = 100;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (calMinCost(n, A, W, mid) <= k) {
                result = min(result, mid);
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (calMinCost(n, A, W, start) <= k) {
            result = min(result, start);
        } else if (calMinCost(n, A, W, end) <= k) {
            result = min(result, end);
        }
        
        return result * result;
    }

private:
    int calMinCost(int n, vector<int> &A, vector<int> &W, int target) {
        vector<vector<int>> dp(n, vector<int>(101, 0x3f3f3f3f));

        for (int j = 0; j <= W[0]; ++j) {
            dp[0][j] = abs(j - A[0]);            
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= W[i]; ++j) {
                if (i == 0) continue;
                for (int k = max(0, j - target); k <= min(W[i - 1], j + target); ++k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - A[i]));
                }
            }
        }
        
        int result = INT_MAX;
        for (int i = 0; i <= 100; ++i) {
            result = min(result, dp[n - 1][i]);
        }
        return result;
    }
};
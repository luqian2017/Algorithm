#include <math.h>

class Solution {
public:
    /**
     * @param A: an integer array
     * @param k: An integer
     * @return: an integer
     */
    int postOffice(vector<int> &A, int k) {
        int n = A.size();
        if (n == 0 || k == 0 || k >= n) return 0;
        
        sort(A.begin(), A.end());
        
        vector<vector<int>> sumDis(n, vector<int>(n));

        //sumDis[i][j] is the minSum of distance when [i, j] has 1 office
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int pos = A[(i + j) / 2];
                for (int l = i; l <= j; ++l) {
                    sumDis[i][j] += abs(A[l] - pos);
                }
            }
        }

        //dp[i][j] is the minimum cost that first i places have j offices
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0x3f3f3f3f)); //should not use INT_MAX here.
        
        //for beninning houses up to the first office, dp = 0 
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[j][i] = 0;
            }
        }

        for (int i = 1; i <= k; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                for (int z = 1; z <= j - i + 1; ++z) {
                    dp[j][i] = min(dp[j][i], dp[j - z][i - 1] + sumDis[j - z][j - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
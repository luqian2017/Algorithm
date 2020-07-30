class Solution {
public:
    /**
     * @param p: The time you choose to do part of the problem.
     * @param part: The points you choose to do part of the problem.
     * @param f: The time you choose to do the whole problem.
     * @param full: The points you choose to do the whole problem.
     * @return: Return the maximum number of points you can get.
     */
    int exam(vector<int> &p, vector<int> &part, vector<int> &f, vector<int> &full) {
        int n = p.size();
        vector<vector<int>> dp(2, vector<int>(121, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 120; ++j) {
                dp[i % 2][j] = dp[(i - 1) % 2][j]; // case 1: skip question i
                
                if (j >= p[i - 1]) { //case 2: partial question i
                    dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - p[i - 1]] + part[i - 1]);
                }
                
                if (j >= f[i - 1]) { //case 3: full question i
                    dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - f[i - 1]] + full[i - 1]);
                }
            }
        }
        
        return dp[n % 2][120];
    }
};
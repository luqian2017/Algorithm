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
        vector<int> dp(121, 0);
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 120; j >= min(p[i - 1], f[i - 1]); --j) {
                //case 1: dp[j] = dp[j] skip question i
                if (j >= p[i - 1]) { //case 2: partial question i
                    dp[j] = max(dp[j], dp[j - p[i - 1]] + part[i - 1]);
                }
                
                if (j >= f[i - 1]) { //case 3: full question i
                    dp[j] = max(dp[j], dp[j - f[i - 1]] + full[i - 1]);
                }
            }
        }
        
        return dp[120];
    }
};
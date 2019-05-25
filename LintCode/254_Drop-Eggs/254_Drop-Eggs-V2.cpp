class Solution {
public:
    /**
     * @param n: An integer
     * @return: The sum of a and b
     */
    int dropEggs(int n) {
        if (n <= 1) return n;
        
        vector<vector<int>> DP(3, vector<int>(n + 1, INT_MAX));
        
        DP[1][0] = 0; DP[2][0] = 0;
        DP[1][1] = 1; DP[2][1] = 1;
        
        for (int i = 1; i <= n; ++i) {
            DP[1][i] = i;
        }
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= i; ++j) {
                DP[2][i] = min(DP[2][i], 1 + max(DP[1][j - 1], DP[2][i - j]));   
            }
             
        }
        
        return DP[2][n];
    }
};
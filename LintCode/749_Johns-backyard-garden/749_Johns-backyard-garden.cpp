class Solution {
public:
    /**
     * @param x: the wall's height
     * @return: YES or NO
     */
    string isBuild(int x) {
        string result;
        vector<int> A = {3, 7};
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= 1; ++i) {
            for (int j = A[i]; j <= x; ++j) {
                dp[j] = dp[j] || dp[j - A[i]];
            }    
        }
        
        if (dp[x]) return "YES";
        else return "NO";
    }
};
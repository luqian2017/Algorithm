class Solution {
public:
    /**
     * @param s: a string
     * @return: return a integer
     */
    int longestValidParentheses(string &s) {
        int n = s.size();
        if (n <= 1) return 0;
        
        int res = 0;
        vector<int> dp(n, 0);
        
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '(') {
                int j = i + dp[i + 1] + 1;
                if (s[j] == ')') {
                    dp[i] = dp[i + 1] + 2;
                    if (j + 1 < n)  dp[i] += dp[j + 1];
                }
                
                res = max(res, dp[i]);
            }
        }
        
        return res;
    }
};
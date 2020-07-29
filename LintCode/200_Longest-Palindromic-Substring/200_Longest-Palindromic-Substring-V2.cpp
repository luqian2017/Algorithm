class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int n = s.size();
        int maxLen = 0;
        string result;
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        result = s.substr(0, 1);
        
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                result = s.substr(i, 2);
            }
        }

        //for (int i = 0; i < n - 1; ++i) {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                if (s[j] == s[i]) {
                    dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i][j] && maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        result = s.substr(i, maxLen);
                    }
                }
            }
        }
        
        return result;
    }
};
class Solution {
public:
    /**
     * @param str: s string
     * @return: return an integer, denote the number of the palindromic substrings
     */
    int countPalindromicSubstrings(string &str) {
        int n = str.size();
        if (n <= 1) return n;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int count = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (str[i] == str[j]) {
                    if (j - i <= 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        count++;
                    } 
                }
            }
        }
        
        return count;
        
    }
};
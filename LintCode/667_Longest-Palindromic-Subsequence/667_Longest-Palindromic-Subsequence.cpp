class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        int len = s.size();
        
        if (len <= 1) return len;
        
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
        }
        
//        for (int i = 0; i < len - 1; ++i) {
//            for (int j = i + 1; j < len; ++j) {
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
     //   for (int i = 0; i < 5; ++i) {
     //       for (int j = 0; j < 5; ++j) {
     //           cout<<dp[i][j]<<" ";
     //       }
     //       cout<<endl;
     //   }
        
        
        return dp[0][len - 1];
    }
};
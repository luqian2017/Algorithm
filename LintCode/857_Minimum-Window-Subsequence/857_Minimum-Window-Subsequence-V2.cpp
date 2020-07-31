class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        int len_s = S.size();
        int len_t = T.size();
        
    //dp[i][j]: the beginning match place if T[1..j] is a subsequence of S[1..i].
        vector<vector<int>> dp(2, vector<int>(len_t + 1, 0));
        int min_len = len_s + 1;
        int min_start = 0;
        
        for (int i = 1; i <= len_s; ++i) {
            for (int j = 1; j <= len_t; ++j) {
                if (S[i - 1] == T[j - 1]) {
                    if (j == 1) {
                        dp[i % 2][1] = i;
                    } else {
                        dp[i % 2][j] = dp[(i - 1) % 2][j - 1]; 
                    }
                } else {
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
                }
            }
            
            if (dp[i % 2][len_t] > 0) {
                if (min_len > i - dp[i % 2 ][len_t] + 1) {
                    min_len = i - dp[i % 2][len_t] + 1;
                    min_start = dp[i % 2][len_t] - 1;
                }
            }
        }
        
        if (min_len == len_s + 1) return "";
        return S.substr(min_start, min_len);
    }
};
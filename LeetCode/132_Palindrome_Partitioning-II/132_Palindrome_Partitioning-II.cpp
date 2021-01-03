class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> dp(n);  //min # of cuts at position i
        vector<vector<bool>> par(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; ++i) {
            dp[i] = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || par[j + 1][i - 1])) { //s[j..i] is palindrome
                    par[j][i] = true;
                    if (j == 0) {
                        dp[i] = 0; //no cuts needed
                    } else {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};
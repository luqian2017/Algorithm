class Solution {
public
    
      @param A A string
      @param B A string
      @return The length of longest common subsequence of A and B
     
    int longestCommonSubsequence(string &A, string &B) {
        int m = A.size();
        int n = B.size();
        
        if (m == 0  n == 0) return 0;
        
        vectorvectorint dp(m, vectorint(n, 0));

        for (int i = 0; i  m; ++i) {
            if (A[i] == B[0]) {
                dp[i][0] = 1;
            }
        }
        
        for (int i = 0; i  n; ++i) {
            if (A[0] == B[i]) {
                dp[0][i] = 1;
            }
        }
   
        for (int i = 1; i  m; ++i) {
            for (int j = 1; j  n; ++j) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
class Solution {
public:
    /**
     * @param A: an integer array   // size array
     * @param V: an integer array   // value array
     * @param m: An integer         // backpack size
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        int n = A.size();
        vector<int> dp(m + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            
            for (int j = 1; j * A[i - 1] <= m; ++j) {  //j can start from 0 or 1
                
                for (int k = m; k >= A[i - 1]; --k) {
                    
                    dp[k] = max(dp[k], dp[k - A[i - 1]] + V[i - 1]);
                }
            }
        }
        
        return dp[m];
    }
};

// The following code is also OK. A[i - 1] to A[i]
#if 0
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        int n = A.size();
        vector<int> dp(m + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            
            for (int j = 1; j * A[i] <= m; ++j) {  //j can start from 0 or 1
                
                for (int k = m; k >= A[i]; --k) {
                    
                    dp[k] = max(dp[k], dp[k - A[i]] + V[i]);
                }
            }
        }
        
        return dp[m];
    }
#endif
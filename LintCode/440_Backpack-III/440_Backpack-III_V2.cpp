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
        
        for (int i = 0; i < n; ++i) {
            
        //    for (int j = 1; j * A[i] <= m; ++j) {
                //for (int k = m; k >= A[i]; --k) {
                for (int k = A[i]; k <= m; ++k) {    
                    dp[k] = max(dp[k], dp[k - A[i]] + V[i]);
                }
        //    }
        }
        
        return dp[m];
    }
};
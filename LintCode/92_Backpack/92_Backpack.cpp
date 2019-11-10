class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        int n = A.size();
        vector<int> dp(m + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int k = m; k >= A[i]; --k) {
            //for (int k = A[i]; k <= m; ++k) {    //wrong!!!
                dp[k] = max(dp[k], dp[k - A[i]] + A[i]);
            }
        }

        for (int k = 0; k <= m; ++k)
            cout<<dp[k]<<" ";
            
        cout<<endl;
        
        return dp[m];
    }
};
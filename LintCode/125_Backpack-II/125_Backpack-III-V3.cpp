class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int itemCount = A.size();
        //dp[packSize]
        vector<int> dp(m + 1, 0);
        
        for (int i = 1; i <= itemCount; ++i) {
            for (int j = m; j >= A[i - 1]; --j) {
                dp[j] = max(dp[j], dp[j - A[i - 1]] + V[i - 1]);
            }
        }
        
        return dp[m];
    }
};
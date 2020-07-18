class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        int len = A.size();
        if (len == 0) return 0;
        if (len == 1) return A[0];
        
        vector<vector<long long>> dp(len + 1, vector<long long>(2));
        //dp[i][0] - maximum value at house i if does not rob the house i 
        //dp[i][1] - maximum value at house i if rob the house i
        
        dp[1][1] = A[0];
        for (int i = 2; i <= len; ++i) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 2][1], dp[i - 2][0]) + A[i - 1];
        }
        
        return max(dp[len][0], dp[len][1]);
    }
};
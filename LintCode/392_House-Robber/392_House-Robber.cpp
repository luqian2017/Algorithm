
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
        
        vector<long long> dp(len, 0);
        dp[0] = A[0];
        dp[1] = A[0] > A[1] ? A[0] : A[1];
        
        for (int i = 2; i < len; ++i) {
            dp[i] = dp[i - 2] + A[i] > dp[i - 1] ? dp[i - 2] + A[i] : dp[i - 1];
        }
        
        return dp[len - 1];
    }
};

//2nd shua
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
        
        vector<long long> dp(len + 1, 0);
        dp[1] = A[0];
        for (int i = 2; i <= len; ++i) {
            dp[i] = max(dp[i - 2] + A[i - 1], dp[i - 1]);
        }
        
        return dp[len];
    }
};
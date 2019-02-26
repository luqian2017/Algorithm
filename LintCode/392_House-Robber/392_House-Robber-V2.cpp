
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
        
        long long dp1 = A[0];
        long long dp2 = A[0] > A[1] ? A[0] : A[1];

        for (int i = 2; i < len; ++i) {
            long long dp = dp1 + A[i] > dp2 ? dp1 + A[i] : dp2;
            dp1 = dp2;
            dp2 = dp;
        }
        
        return dp2;
    }
};
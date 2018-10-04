class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        int len = A.size();
        vector<bool> DP(len, false);
        
        DP[0] = true;
        for (int i = 0; i < A[0]; ++i) {
            DP[i + 1] = true;
        }
        
        for (int i = 1; i < len; ++i) {
            if (DP[i]) {
                for (int j = 1; j < A[i]; ++j) {
                    DP[i + j ] = true;
                }
            }
        }
        
        if (DP[len - 1]) return true;
        else return false;
    }
};
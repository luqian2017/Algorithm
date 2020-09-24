class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &A) {
        int n = A.size();
        
        //dp_0[i]: the maximum number of consecutive, end with A[i], never flipped so far
        //dp_1[i]: the maximum number of consecutive, end with A[i], flipped at most once
        vector<int> dp_0(n, 0), dp_1(n, 0);
        if (A[0] == 0) {
            dp_0[0] = 0;
            dp_1[0] = 1;
        } else {
            dp_0[0] = 1;
            dp_1[0] = 1;
        }
        int max_len = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] == 0) {
                dp_0[i] = 0;
                dp_1[i] = dp_0[i - 1] + 1;
            } else {
                dp_0[i] = dp_0[i - 1] + 1;
                dp_1[i] = dp_1[i - 1] + 1;
            }
            max_len = max(max_len, dp_1[i]);
        }
        
       return max_len;
    }
};
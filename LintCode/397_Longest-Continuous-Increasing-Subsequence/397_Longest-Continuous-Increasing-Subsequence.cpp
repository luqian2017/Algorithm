class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        int len = A.size();
        if (len == 0) return 0;
        int incrCount = 1, maxIncrCount = 1;
        int decrCount = 1, maxDecrCount = 1;
        
        for (int i = 1; i < len; ++i) {
            if (A[i] > A[i - 1]) {
                decrCount = 1;
                incrCount++;
                maxIncrCount = max(maxIncrCount, incrCount);
            } else if (A[i] < A[i - 1]){
                incrCount = 1;
                decrCount++;
                maxDecrCount = max(maxDecrCount, decrCount);
            } else {
                incrCount = 1;
                decrCount = 1;
            }
        }
        
        return max(maxIncrCount, maxDecrCount);
    }
};
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: return maxium contiguous non-negative subarray sum
     */
    int maxNonNegativeSubArray(vector<int> &A) {
        int n = A.size();
        if (n == 0) return 0;
        int sum = 0, maxSum = 0;
        int posCount = 0;
        for (int i = 0; i < n; ++i) {
            
            if (A[i] < 0) {
                sum = 0;
             } else {
                sum += A[i];
                posCount++;
            } 

            if (maxSum < sum) {
                maxSum = sum;
            }

        }
        
        if (posCount == 0) return -1;
        return maxSum;
    }
};
class Solution {
public:
    /**
     * @param A: a integer sorted array
     * @param B: a integer sorted array
     * @param K: a integer
     * @return: return a pair of index
     */
    vector<int> optimalUtilization(vector<int> &A, vector<int> &B, int K) {
        int sizeA = A.size();
        int sizeB = B.size();
        if (sizeA == 0 || sizeB == 0) return vector<int>();
        
        int maxCount = INT_MIN;
        vector<int> result;
        
        for (int i = 0; i < sizeA; ++i) {
            for (int j = 0; j < sizeB; ++j) {
                int sum = A[i] + B[j];
                if (sum <= K) {
                    if (sum > maxCount) {
                        result = {i, j};
                        maxCount = sum;
                    }
                }
            }
        }
        
        return result;
        
    }
};
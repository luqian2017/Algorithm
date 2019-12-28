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
            int start = 0, end = sizeB - 1;
            while(start + 1 < end) {
                int mid = start + (end - start) / 2;
                if (A[i] + B[mid] <= K) {
                    if (maxCount < A[i] + B[mid]) {
                        maxCount = A[i] + B[mid];
                        result = {i, mid};
                    }
                    start = mid;
                } else if (A[i] + B[mid] > K) {
                    end = mid;
                } else {
                    maxCount = K;
                    result = {i, mid};
                    end = mid; 
                }
            }
            
            int sum1 = A[i] + B[start];
            int sum2 = A[i] + B[end];
            if (sum1 <= K) {
                if (sum1 > maxCount) {
                    maxCount = sum1;
                    result = {i, start};
                } else if (sum1 == maxCount) {
                    if (i < result[0] || 
                       (i == result[0] && start < result[1])) {
                       result = {i, start}; 
                    }
                }
            }
            if (sum2 <= K && sum2 > maxCount) {
                maxCount = sum2;
                result = {i, end};
            }
            

            for (int j = result[0] - 1; j >= 0; --j) {
                if (A[j] == A[result[0]]) result[0] = j;
                else break;
            }
            
            for (int j = result[1] - 1; j >= 0; --j) {
                if (B[j] == B[result[1]]) result[1] = j;
                else break;
            }
        }
        return result;
    }
};
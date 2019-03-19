class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int> &A) {
        int n = A.size();
        if (n == 0) return vector<int>();
        
        int sum = A[0], maxSum = A[0], minSum = A[0], totalSum = A[0];
        int maxStartIndex = 0, maxEndIndex = 0;
        int gMaxStartIndex = 0, gMaxEndIndex = 0;
        int minStartIndex = 0, minEndIndex = 0;
        int gMinStartIndex = 0, gMinEndIndex = 0;
        
        for (int i = 1; i < n; ++i) {
            totalSum += A[i];
            if (sum < 0) {
                sum = A[i];
                maxStartIndex = i;
                maxEndIndex = i;
            } else {
                sum += A[i];
                maxEndIndex = i;
            } 
                
            if (sum > maxSum) {
                maxSum = sum;
                gMaxStartIndex = maxStartIndex;
                gMaxEndIndex = maxEndIndex;
            }
        }
        
        sum = A[0];
        for (int i = 1; i < n; ++i) {
            if (sum > 0) {
                sum = A[i];
                minStartIndex = i;
                minEndIndex = i;
            } else {
                sum += A[i];
                minEndIndex = i;
            }
            
            if (sum < minSum) {
                minSum = sum;
                gMinStartIndex = minStartIndex;
                gMinEndIndex = minEndIndex;
            }
        }
        
        if (maxSum > totalSum - minSum) {
            return vector<int>{gMaxStartIndex, gMaxEndIndex};
        } else {
            if (gMinStartIndex == 0 && gMinEndIndex == n - 1) {
                return vector<int>{gMaxStartIndex, gMaxEndIndex};
            } else {
                return vector<int>{(gMinEndIndex + 1) % n, (gMinStartIndex - 1 + n) % n};
            }
        }       
    }
};


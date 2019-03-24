class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        int n = A.size();
        if (n == 0) return 0;
        
        int begin = 0, last = 0;
        int count = 0;
        vector<int> sums(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            sums[1] = sums[1] + A[i - 1];
            if (sums[1] >= start && sums[1] <= end) count++;
        }

        for (int i = 2; i <= n; ++i) {        
            sums[i] = A[i - 1];
            if (sums[i] >= start && sums[i] <= end) count++;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                sums[i] += A[j - 1];
                if (sums[i] >= start && sums[i] <= end) {
                    count++;
                }
            }    
        }
        
        return count;
    }
};
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
        vector<vector<int>> sums(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            sums[1][i] = sums[1][i - 1] + A[i - 1];
            if (sums[1][i] >= start && sums[1][i] <= end) count++;
        }

        for (int i = 2; i <= n; ++i) {        
            sums[i][i] = A[i - 1];
            if (sums[i][i] >= start && sums[i][i] <= end) count++;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
               if (sums[i][j] == 0) {
                    sums[i][j] = sums[i][j - 1] + A[j - 1];
                    if (sums[i][j] >= start && sums[i][j] <= end) {
                        count++;
                    }
                }
            }    
        }
        
        return count;
    }
};
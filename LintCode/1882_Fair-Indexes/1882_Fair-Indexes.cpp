class Solution {
public:
    /**
     * @param A: an array of integers
     * @param B: an array of integers
     * @return: return a integer indicating the number of fair indexes.
     */
    int CountIndexes(vector<int> &A, vector<int> &B) {
        int n = A.size();
        if (n == 0) return 0;
        
        long long presumsA = 0, presumsB = 0;

        for (int i = 0; i < n; ++i) {
            presumsA += A[i];
            presumsB += B[i];
        }
        
        if (presumsA != presumsB) return 0;
        long long halfSum = presumsA / 2;
        presumsA = 0, presumsB = 0;
        int result = 0;
        for (int i = 0; i < n - 1; ++i) {
            presumsA += A[i];
            presumsB += B[i];
            if (presumsA == presumsB && presumsA == halfSum) result++;
        }
        
        return result;
    }
};
class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: An integer
     */
    int firstMissingPositive(vector<int> &A) {
        int N = A.size();
        if (N == 0) return 1;

        for (int i = 0; i < N; ++i) {
            while(A[i] > 0 && A[i] <= N && A[i] != i + 1) {
                if (A[A[i] - 1] == A[i]) break;  //important!
                swap(A[i], A[A[i] - 1]);
            }
        }
        
        for (int i = 0; i < N; ++i) {
            if (A[i] != i + 1) return i + 1;
        }
        
        return N + 1;
    }
};
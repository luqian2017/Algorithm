class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers(vector<int> &A) {
        int n = A.size();
        if (n == 0) return;
        
        for (int i = 0; i < n - 1; ++i) {
            
            int minV = A[i];
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (minV > A[j]) {
                     minV = A[j];
                     minIndex = j;
                };
            }
            swap(A[i], A[minIndex]);
        }
        return;
    }
};
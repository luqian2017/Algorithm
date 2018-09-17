class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        if (!A || !B) return;
        int insertIndex = m + n - 1;
        while(m && n) {
            if (A[m - 1] >= B[n - 1]) {
                A[insertIndex] = A[m - 1];
                m--;
            } else {
                A[insertIndex] = B[n - 1];
                n--;
            }
            insertIndex--;
        }
        
        while(n) {
            A[insertIndex--] = B[n-1];
            n--;
        }
    }
};
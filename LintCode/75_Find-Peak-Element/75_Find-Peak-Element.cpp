class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        int n = A.size();
        if (n <= 1) return n - 1;
        
        int start = 0, end = n - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (mid == 0) return -1;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) return mid;

            if (A[mid - 1] < A[mid]) start = mid;
            if (A[mid - 1] > A[mid]) end = mid;
        }
        
        return -1;
    }
};
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        int n = A.size();
        int start = 1, end = n - 2;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) return mid; //A[mid] is peak, return
            if (A[mid] > A[mid - 1]) start = mid;    //A[mid - 1] < A[mid] < A[mid + 1], choose right side
            else if (A[mid] > A[mid + 1] ) end = mid; //A[mid - 1] > A[mid] > A[mid + 1], choose left side
            else start = mid;  //A[mid] is bottom, choose either side is OK
        }
        
        if (A[start] < A[end]) return end;
        return start;
    }
};


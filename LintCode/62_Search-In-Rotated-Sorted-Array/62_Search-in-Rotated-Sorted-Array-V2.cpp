class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        int n = A.size();
        if (n == 0) return -1;
        
        int start = 0, end = n - 1;
        
        if (A[start] == target) return start;
        if (A[end] == target) return end;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;

            if (A[mid] == target) return mid;

            if (A[mid] > A[start]) {
                if (target < A[mid] && target > A[start]) end = mid;
                else start = mid;
            }
            
            if (A[mid] < A[start]) {
                if (target > A[mid] && target < A[end]) start = mid;
                else end = mid;
            }
            
        }

        if (A[start] == target) return start;
        if (A[end] == target) return end;
        
        return -1;
    }
};
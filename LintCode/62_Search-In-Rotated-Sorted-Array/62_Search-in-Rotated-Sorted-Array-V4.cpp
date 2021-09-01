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
        while (start + 1 < end) {
            int mid =  start + (end - start) / 2;
            if (A[mid] < A[start] && target > A[start]) {
                end = mid;
            } else if (A[mid] > A[start] && target < A[start]) {
                start = mid;
            } else {
                if (A[mid] > target) {
                    end = mid;
                } else if (A[mid] < target) {
                    start = mid;
                } else {
                    return mid;
                }
            } 
        }
        if (A[end] == target) return end;
        if (A[start] == target) return start;
        return -1;
    }
};
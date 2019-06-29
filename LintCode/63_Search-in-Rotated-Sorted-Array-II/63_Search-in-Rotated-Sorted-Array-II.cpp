class Solution {
public:
    /**
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean 
     */
    bool search(vector<int> &A, int target) {
        int n = A.size();
        if (n == 0) return false;
        int start = 0, end = n - 1;
        
        if (A[start] == target) return true;
        if (A[end] == target) return true;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) return true;
            if (A[mid] > A[start] && target < A[start]) start = mid;
            else if (A[mid] < A[start] && target > A[start]) end = mid;
            else {
                if (A[mid] > target) end = mid;
                else start = mid;
            }
        }
        
        if (A[start] == target || A[end] == target) return true;
        return false;
    }
};
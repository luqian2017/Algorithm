class Solution {
public:
    /**
     * @param A: an integer array sorted in ascending order
     * @param target: An integer
     * @return: an integer
     */
    int closestNumber(vector<int> &A, int target) {
        int n = A.size();
        if (n == 0) return 0;
        if (n == 1) return A[0];
        
        int start = 0, end = n - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] < target) {
                start = mid;
            } else if (A[mid] > target) {
                end = mid;
            } else {
                return mid;
            }
        }
        
        if (abs(target - A[start]) < abs(target - A[end])) {
            return start;
        } else {
            return end;
        }
    }
};
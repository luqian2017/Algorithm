class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        int n = A.size();
        if (n == 0) return vector<int>(2, -1);
        
        int start = 0, end = n - 1;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] < target) {
                start = mid;
            } else if (A[mid] >= target) {
                end = mid;
            }
        }

        vector<int> result(2, -1);
        if (A[start] != target && A[end] != target) return vector<int>(2, -1);
        
        for (int i = start; i <= end; ++i) {
            if (A[i] == target) {
                result[0] = i;
                result[1] = i;
                break;
            }
        }
        if (result[0] == -1) return result;
        
        for (int i = result[0] + 1; i < n - 1; ++i) {
            if (A[i] == target && A[i + 1] != target) {
                result[1] = i;
            } 
        }
        if (A[n - 1] == target) result[1] = n - 1;
        
        return result;
    }
};
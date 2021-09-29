class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        vector<int> res;
        int n = A.size();
        if (n == 0 || k == 0) return {};
        int count = 0;
        int start = 0, end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] < target) {
                start = mid;
            } else if (A[mid] > target) {
                end = mid;
            } else {
                //return mid;
                res.push_back(A[mid]);
                count = 1;
                start = mid - 1;
                end = mid + 1;
                break;
            }
        }
       
        if (start > 0 && A[start] > target) {
            for (int i = 0; i < k; i++) {
                res.push_back(A[start + i]);
            }
        } else if (end < n && A[end] < target) {
            for (int i = 0; i < k; i++) {
                res.push_back(A[end - i]);
            }
        } else {
            int left = start, right = end;

            while (count < k) {
                if (left >= 0 && right < n) {
                    if (abs(A[left] - target) <= abs(A[right] - target)) {
                        res.push_back(A[left--]);
                    } else {
                        res.push_back(A[right++]);
                    }
                } else if (left >= 0) {
                    res.push_back(A[left--]);
                } else {
                    res.push_back(A[right++]);
                }
                count++;
            }
        }
        
        return res;
    }
};
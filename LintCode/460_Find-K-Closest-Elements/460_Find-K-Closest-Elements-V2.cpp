class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        int n = A.size();
        if (n < k || k == 0) return {};
        vector<int> res;
        int start = 0, end = n - 1;
        int find_pos = -1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] < target) {
                start = mid;
            } else if (A[mid] > target) {
                end = mid;
            } else {
                find_pos = mid;
                break;
            }
        }
        if (find_pos == -1) {
            if (abs(A[start] - target) <= abs(A[end] - target)) find_pos = start;
            else find_pos = end;
        }
        res.push_back(A[find_pos]);
        int cnt = 1;
       // int left = max(0, find_pos - 1), right = min(find_pos + 1, n - 1);
        int left = find_pos - 1, right = find_pos + 1;
        while (cnt < k) {
            if (left >= 0 && right <= n - 1) {
                if (abs(A[left] - target) <= abs(A[right] - target)) {
                    res.push_back(A[left]);
                    left--;
                } else {
                    res.push_back(A[right]);
                    right++;
                }
            } else if (left >= 0) {
                res.push_back(A[left]);
                left--; 
            } else if (right <= n - 1) {
                res.push_back(A[right]);
                right++;
            } else {
                break;
            }
            cnt++;
        }

        return res;
    }
};
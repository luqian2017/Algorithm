class Solution {
public:
    /**
     * @param A: a array
     * @return: is it monotonous
     */
    bool isMonotonic(vector<int> &A) {
        int n = A.size();
        if (n <= 1) return true;
        bool increasing, decreasing;
        
        if (A[1] > A[0]) {
            increasing = true;
            decreasing = false;
        } else if (A[1] < A[0]) {
            increasing = false;
            decreasing = true;
        } else {
            increasing = true;
            decreasing = true;
        }
 
        for (int i = 2; i < n; ++i) {
            if (increasing && A[i] >= A[i - 1]) continue;
            if (decreasing && A[i] <= A[i - 1]) continue;
            return false;
        }
        return true;
    }
};

class Solution {
public:
    /**
     * @param A: the array.
     * @param k: the integer.
     * @return: the divisor satisfy the requirement.
     */
    int FindDivisor(vector<int> &A, int k) {
        int n = A.size();
        int start = 1, end = INT_MAX;
        
        while(start + 1 < end) {
            double mid = start + (end - start) / 2;
            if (test(A, k, mid)) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (test(A, k, end)) return end;
        return start;
      }
private:
    bool test(vector<int> &A, int k, double target) {
        int n = A.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += ceil(A[i] / target);
        }
        return (count >= k);
    }
};
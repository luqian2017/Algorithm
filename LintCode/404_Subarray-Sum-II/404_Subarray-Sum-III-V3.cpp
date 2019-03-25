
class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        int n = A.size();
        if (n == 0) return 0;
        if (end == 0) return 0;
        
        int p1 = 0, p2 = 1;
        int count = 0;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sums[i] += sums[i - 1] + A[i - 1];
        }
        return largerSubarraySum(sums, start - 1) - largerSubarraySum(sums, end);

        return count;
    }

private:
    int largerSubarraySum(vector<int> &A, int target) {
        int n = A.size() - 1;
        int p1 = 0, p2 = 1;
        int count = 0;
        while (p2 <= n && p1 <= p2) {
            if (A[p2] - A[p1] <= target) {
                p2++;
            } else {
                count += n - p2 + 1;
                p1++;
            }
        }
        
        return count;
    }
};
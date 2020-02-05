class Solution {
public:
    /**
     * @param A: an array
     * @return: is the number of global inversions is equal to the number of local inversions
     */
    bool isIdealPermutation(vector<int> &A) {
        int n = A.size();
        if (n < 2) return true;
        int maxV = 0;
        for (int i = 2; i < n; ++i) {
            maxV = max(maxV, A[i - 2]);
            if (maxV > A[i]) return false;
        }
        return true;
    }
};
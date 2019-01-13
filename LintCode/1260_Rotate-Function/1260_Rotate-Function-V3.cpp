class Solution {
public:
    /**
     * @param A: an array
     * @return: the maximum value of F(0), F(1), ..., F(n-1)
     */
    int maxRotateFunction(vector<int> &A) {
        
        int len = A.size();
        if (len <= 1) return 0;

        int sum = 0;
        vector<int> f(len, 0);
        
        for (int i = 0; i < len; ++i) {
            sum += A[i];
            f[0] += i * A[i];
        }
        
        int maxResult = f[0];
        
        for (int i = 1; i < len; ++i) {
            f[i] = f[i - 1] + sum - len * A[len - i];
            maxResult = max(maxResult, f[i]);
        }
        
        return maxResult;
    }
};
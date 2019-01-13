class Solution {
public:
    /**
     * @param A: an array
     * @return: the maximum value of F(0), F(1), ..., F(n-1)
     */
    int maxRotateFunction(vector<int> &A) {
        
        int len = A.size();
        if (len <= 1) return 0;

        int maxSum = INT_MIN;
        
        vector<int> newA = A;
        newA.insert(newA.end(), A.begin(), A.end());

        for (int i = 0; i <= len; ++i) {
            
            int sum = 0;
            for (int j = 0; j < len; ++j) {
                sum += newA[i + j] * j;
            }
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
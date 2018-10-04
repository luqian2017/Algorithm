class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        vector<int> A(n + 1, 0);
        
        A[1] = 1;
        A[2] = 2;
        
        for (int i = 3; i <= n; ++i) {
            A[i] = A[i - 1] + A[i -2];    
        }
        
        return A[n];
    }
};
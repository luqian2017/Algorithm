class Solution {
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        
        int a1 = 0;
        int a2 = 1;
        
        for (int i = 3; i <= n; ++i) {
            int temp = a2;
            a2 += a1;
            a1 = temp;
        }
        
        return a2;
        
    }
};
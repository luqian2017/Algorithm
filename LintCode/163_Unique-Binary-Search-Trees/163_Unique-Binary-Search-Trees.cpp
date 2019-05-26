class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        
        double numerator = 1;
        double denominator = 1;
        int n2 = n * 2;
        
        for (int i = n + 2; i < n2; ++i) {
            numerator *= i;    
        }

        for (int i = 3; i < n; ++i) {
            denominator *= i;
        }

        return (int)ceil(numerator / denominator);
    }
};
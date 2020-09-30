class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // Let x = t * t, t is varibale
        // Then return the root of t * t - x = 0
        double t = x / 2.0;
        while(fabs(t * t - x) > 1e-6) {
            t -= (t * t - x) / (2 * t);
        }
        return t;
    }
};
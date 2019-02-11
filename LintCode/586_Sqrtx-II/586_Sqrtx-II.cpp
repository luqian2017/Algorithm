class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        double result;
        double start = 0, end, mid;
        double origX = x;
        
        if (x < 1) x = 1.0 / x;
        
        end = x;
        
        while(start + 1e-9 < end) {
            mid = start + (end - start) / 2;
            if (mid * mid < x) {
                start = mid;
            } else {
                end = mid;   
            }
        }
        
        result = start + (end - start) / 2;
        
        if (origX < 1) {
            result = 1.0 / result;   
        }
        
        return result;
    }
};
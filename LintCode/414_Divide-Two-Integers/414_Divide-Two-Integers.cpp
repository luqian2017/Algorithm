
class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;  //important! 
        if (dividend == 0) return 0;
        
       // bool isNegative = (((long long)dividend * divisor) > 0) ? false : true; //remember to use long long! Otherwise overflow (case: 2147483647 2)
        bool isNegative = ((dividend < 0) && (divisor > 0)) || ((divisor < 0) && (dividend > 0));
        
        long long dividendll = (long long)dividend, divisorll = (long long)divisor;
        if (isNegative) {
            if (dividendll < 0) dividendll = -dividendll; //note! it is incorrect for case dividend ==  -2147483648
            else divisorll = -divisorll;
        } else if (dividendll < 0) {
            dividendll = -dividendll;
            divisorll = -divisorll;
        }
        int quotient = 0;
        
        while(dividendll >= divisorll) {
            int shift = 1;
            while ((divisorll << shift) <= dividendll) {
                shift++;
            }
            quotient += 1 << (shift - 1);
            dividendll -= (divisorll << (shift - 1));
        }
        
        return quotient * (isNegative ? -1 : 1);    
    }
};
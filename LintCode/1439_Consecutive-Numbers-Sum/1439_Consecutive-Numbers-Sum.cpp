class Solution {
public:
    /**
     * @param N: an integer
     * @return: how many ways can we write it as a sum of consecutive positive integers
     */
    int consecutiveNumbersSum(int N) {
        int res = 0;
        int thresh = sqrt(2 * N);
        
        //a + a+1 + a+2 + ... + a+k-1 = N
        //k * (2 * a + k - 1) = 2 * N => k * k < 2 * N => k < sqrt(2 * N)
        //a = (2 * N - k * k + k) / 2k
        
        for (int k = 1; k <= thresh; ++k) {
            int temp = 2 * N - k * k + k;
            if (temp > 0 && (temp % (2 * k) == 0)) res++;
        }
        
        return res;
    }
};
class Solution {
public:
    /**
     * @param L: an integer
     * @param R: an integer
     * @return: the count of numbers in the range [L, R] having a prime number of set bits in their binary representation
     */
    int countPrimeSetBits(int L, int R) {
        int result = 0;
        for (int i = L; i <= R; ++i) {
            if (isPrime(numOfSetBits(i))) {
                result++;
            }
        }
        return result;
    }

private:
    inline int numOfSetBits(int n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }

    inline int isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if ((n & 0x1) == 0) return false;
        int sqrtN = sqrt(n);
        for (int i = 2; i <= sqrtN; ++i) {
            if ((n % i) == 0) return false;
        }
        return true;
    }    
};
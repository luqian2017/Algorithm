class Solution {
public:
    /**
     * @param n: an integer
     * @return: if n is a power of three
     */
    bool isPowerOfThree(int n) {
        if (n == 0 || n == 1) return n;
        if (n % 3 != 0) return false;
        return isPowerOfThree(n / 3);
    }
};
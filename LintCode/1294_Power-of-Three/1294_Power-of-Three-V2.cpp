class Solution {
public:
    /**
     * @param n: an integer
     * @return: if n is a power of three
     */
    bool isPowerOfThree(int n) {
        int num = 1;
        while(num <= n) {
            if (num == n) return true;
            num *= 3;
        }
        return false;
    }
};
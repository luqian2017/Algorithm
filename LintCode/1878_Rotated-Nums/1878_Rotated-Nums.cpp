class Solution {
public:
    /**
     * @param n: length of good nums
     * @return: The num of good nums of length n
     */
    long long RotatedNums(int n) {
        if (n == 1) return 5;
        if (n == 2) return 6;
        int halfLen = (n - 1) / 2;
        long long prod = 1;

        if (n & 0x1) {
            for (int i = 1; i <= halfLen - 1; ++i) {
                prod *= 7;
            }
            return 5 * prod * 6;
        } else {
             for (int i = 1; i <= halfLen; ++i) {
                prod *= 7;
            }
            return prod * 6;            
        }
    }
};
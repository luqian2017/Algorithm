class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param i: A bit position
     * @param j: A bit position
     * @return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        
        for (int k = i; k <= j; ++k) {
           if (m & (1 << k - i))
               n |= (1 << k);
           else
               n &= ~(1 << k);
        }
        
        return n;
    }
};
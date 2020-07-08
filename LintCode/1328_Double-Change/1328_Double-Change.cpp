class Solution {
public:
    /**
     * @param A: an Integer
     * @param B: an Integer
     * @param p: an Integer
     * @param q: an Integer
     * @return: Return the minimum time
     */
    int DoubleChange(int A, int B, int p, int q) {
        int step = 0;
        long long prod = p;
        while(A + prod < B) {
            prod *= q;
            step++;
        }
        return step + 1;
    }
};
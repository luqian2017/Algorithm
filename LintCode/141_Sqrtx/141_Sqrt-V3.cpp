class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if (x < 0) return -1;
        long long res = 1;
        while (res * res <= x) {
            res++;
        }
        return (res * res == x) ? (int)res : (int)res - 1;
    }
};
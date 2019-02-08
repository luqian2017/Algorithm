class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        int start = 0, end = x;

        while(start + 1 < end) {
            long long mid = start + (end - start) / 2;
            long long midSquare = mid * mid;
            if (midSquare < x) {
                start = mid;
            } else if (midSquare > x) {
                end = mid;
            } else {
                return mid;
            }
        }
       
        if (end * end == x) return end;
        return start;
    }
};
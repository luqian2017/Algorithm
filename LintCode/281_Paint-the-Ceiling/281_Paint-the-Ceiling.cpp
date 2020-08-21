class Solution {
public:
    /**
     * @param s0: the number s[0]
     * @param n: the number n
     * @param k: the number k
     * @param b: the number b
     * @param m: the number m
     * @param a: area
     * @return: the way can paint the ceiling
     */
    long long painttheCeiling(int s0, int n, int k, int b, int m, long long a) {
        long long result = 0;
        vector<long long> s(n, 0);
        s[0] = s0;
        
        for (int i = 1; i < n; ++i) {
            s[i] = ((k * s[i - 1] + b) % m) + 1 + s[i - 1];
        }
        
        int start = 0, end = n - 1;
        while(start <= end) {
            if (s[start] * s[end] > a) {
                end--;
            } else {
                result += 2 * (end - start) + 1;
                start++;
            }
        }
        
        return result;
    }
};
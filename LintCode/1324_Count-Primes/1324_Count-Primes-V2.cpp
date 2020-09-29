class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a integer
     */

    int countPrimes(int n) {
        vector<int> flags(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            if (flags[i]) continue;
            //fails after i >=46350 as i*i exceeds MAX_INT
            for (int j = i * i; j <= n; j += i) {
                flags[j] = 1;
            }
        }
        int count = 0;

        
        for (int i = 2; i < n; ++i) {
            if (!flags[i]) count++;
        }
        return count;   //1 is not prime
    }
};

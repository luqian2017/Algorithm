class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a integer
     */
    int countPrimes(int n) {
        if (n == 1) return 0;
        int sqrtn = sqrt(n);
        vector<int> filter(n, 1);
        
        for (int i = 2; i <= sqrtn; ++i) {
            int j = i << 1;
            while (j < n) {
                filter[j] = 0;
                j += i;
            }
        }
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (filter[i] == 1) {
                count++;
            }
        }
        
        return count - 1;   //1 is not prime
    }
};
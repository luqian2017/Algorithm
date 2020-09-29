//https://zhuanlan.zhihu.com/p/42609585

class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a integer
     */

    int countPrimes(int n) {
        vector<int> primes(n + 1, 0); //primes[i]: 0 => unprocessed, -1 => non-prime, >0 => a prime-number
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (!primes[i]) {
                primes[count++] = i;
            }
            for (int j = 0; j < count; ++j) {
                int product = primes[j] * i;
                if (product > n) break;
                primes[product] = -1; //just show it is not prime-number. It can be any number except 0.
                if (i % primes[j] == 0) break;
            }
        }
        return count;
    }
};

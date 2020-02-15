class Solution {
public:
    /**
     * @param n: the given number
     * @return:  return true if it has exactly three distinct factors, otherwise false
     */
    bool isThreeDisctFactors(long long n) {
        long long sqrtN = sqrt(n);
        if (sqrtN * sqrtN != n) return false;
        return isPrime(sqrtN);   
    }

private:
    bool isPrime(long long num) {
        long long sqrtNum = sqrt(num);
        for (int i = 2; i <= sqrtNum; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
};
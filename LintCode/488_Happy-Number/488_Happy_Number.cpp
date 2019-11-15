class Solution {
public:
    /**
     * @param n: An integer
     * @return: true if this is a happy number or false
     */
    bool isHappy(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        
        unordered_set<long long> sumSet;
        while (n > 1) {
            long long sum = getSum(n);
            if (sum == 1) return true;
            if (sumSet.find(sum) != sumSet.end()) return false;
            sumSet.insert(sum);

            n = sum;
        }
        
        return false;
    }

private:
    long long getSum(long long n) {
        long long sum = 0;
        while(n > 0) {
            int m = n % 10;
            sum += m * m; //m ^ 2 is wrong!
            n /= 10;
        }
        return sum;
    }
};
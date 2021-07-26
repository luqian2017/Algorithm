class Solution {
public:
    /**
     * @param n: An integer
     * @return: true if this is a happy number or false
     */
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        int sum = 0;
        while (n != 1) {
            sum = 0;
            while(n) {
                int res = n % 10;
                sum += res * res;
                n /= 10;
            }
            if (s.find(sum) != s.end()) return false;
            s.insert(sum);
            n = sum;
        }
        return true;
    }
};
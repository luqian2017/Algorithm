class Solution {
public:
    /**
     * @param n: The number of digits
     * @return: All narcissistic numbers with n digits
     */
    vector<int> getNarcissisticNumbers(int n) {
        if (n == 0) return vector<int>();
        vector<int> results;
        vector<int> powers(10, 0);
        for (int i = 1; i < 10; ++i) {
            powers[i] = pow(i, n);
        }
        
        int upperLimit = pow(10, n) - 1;
        int lowerLimit = (n == 1) ? 0 : pow(10, n - 1);

        for (int num = lowerLimit; num <= upperLimit; ++num) {
            vector<int> digits(n, 0);
            long long powSum = 0;
            int saveNum = num;
            for (int i = 0; i < n; ++i) {
                digits[i] = saveNum % 10;

                saveNum /= 10;
                powSum += powers[digits[i]];
            }

            if (num == powSum) results.push_back(num);
        }
        
        return results;
    }
};
class Solution {
public:
    /**
     * @param digits: a number represented as an array of digits
     * @return: the result
     */
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();

        int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = (digits[i] >= 10) ? 1 : 0;
            digits[i] %= 10;
        }

        if (carry == 0) return digits;
        
        vector<int> result(n + 1);
        result[0] = 1;
        for (int i = 1; i <= n; ++i) {
            result[i] = digits[i - 1];
        }
        return result;

    }
};
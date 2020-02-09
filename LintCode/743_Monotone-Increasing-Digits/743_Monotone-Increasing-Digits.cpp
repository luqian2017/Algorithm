class Solution {
public:
    /**
     * @param num: a non-negative integer N
     * @return: the largest number that is less than or equal to N with monotone increasing digits.
     */
    int monotoneDigits(int num) {
        vector<int> digits;
        while(num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        int pos = 0;
        for (int i = 1; i < digits.size(); ++i) {
            if (digits[i] > digits[i - 1]) {
                digits[i]--;
                pos = i;
            }
        }
        
        for (int i = 0; i < pos; ++i) digits[i] = 9;
        
        int result = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            result = result * 10 + digits[i];
        }
        
        return result;
    }
};
class Solution {
public:
    /**
     * @param num: a non-negative integer
     * @return: one digit
     */
    int addDigits(int num) {
        int result = num;

        do {
            num = result;
            result = 0;
            while(num) {
                result += (num % 10);
                num = num / 10;
            }
        } while(result >= 10);
    
        return result;
    }
};
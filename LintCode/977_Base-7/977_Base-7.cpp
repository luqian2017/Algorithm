class Solution {
public:
    /**
     * @param num: the given number
     * @return: The base 7 string representation
     */
    string convertToBase7(int num) {
        string res = "";
        bool isNeg = false;
        if (num < 0) {
            isNeg = true;
            num = -num;
        }
        while (num) {
            //res = ('0' + (num % 7)) + res;
            res = to_string(num % 7) + res;
            num /= 7;
        }
        
        if (isNeg) res = '-' + res;
        return res;
    }
};
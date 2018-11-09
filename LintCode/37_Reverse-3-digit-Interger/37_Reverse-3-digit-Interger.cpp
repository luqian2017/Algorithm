class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        int n100 = number / 100;
        int n10 = (number - n100 * 100) / 10;
        int n1 = number - n100 * 100 - n10 * 10;
        return n1 * 100 + n10 * 10 + n100;
        
    }
};
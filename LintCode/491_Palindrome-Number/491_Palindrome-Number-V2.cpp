class Solution {
public:
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        int temp = num; //num = 321
        long long rev = 0;
        while(temp) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        
        return rev == num;
    }
};
class Solution {
public:
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        
        int start = 0, end = n - 1;
        while(start < end) {
            if (numStr[start] != numStr[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
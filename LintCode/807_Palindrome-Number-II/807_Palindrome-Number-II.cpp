class Solution {
public:
    /**
     * @param n: non-negative integer n.
     * @return: return whether a binary representation of a non-negative integer n is a palindrome.
     */
    bool isPalindrome(int n) {
        string s;
        while (n) {
            s = s + static_cast<char>('0' + n & 0x1);
            n >>= 1;
        }
        
        int len = s.size();
        int p1 = 0, p2 = len - 1;
        while (p1 < p2) {
            if (s[p1] != s[p2]) return false;
            p1++;
            p2--;
        }
        
        return true;
    }
};
class Solution {
public:
    /**
     * @param s: a string
     * @return bool: whether you can make s a palindrome by deleting at most one character
     */
    bool validPalindrome(string &s) {
        int n = s.size();
        if (n <= 1) return true;
        
        return helper(s, 0, n - 1, 1);
    }
    
private:
    bool helper(string &s, int a, int b, int d) {
        if (a >= b) return true;
        if (s[a] == s[b]) {
            return helper(s, a + 1, b - 1, d);
        } else if (d > 0) {
            return helper(s, a + 1, b, d - 1) || helper(s, a, b - 1, d - 1);
        }
    }
};
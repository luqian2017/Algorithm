class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
       int n = s.size();
       if (n == 0) return true;
       int start = 0, end = n - 1;
       while (start < end) {
           while (!isalnum(s[start])) start++;
           while (!isalnum(s[end])) end--;
           if (start < end) {
               if (tolower(s[start]) != tolower(s[end])) {
                   return false;
               } else {
                   start++;
                   end--;
               }
           }
       }
       return true;
    }
};
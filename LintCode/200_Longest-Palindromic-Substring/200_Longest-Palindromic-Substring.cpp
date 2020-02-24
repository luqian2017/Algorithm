class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int n = s.size();
        int maxLen = 0;
        int maxLenStart = 0;
        for (int i = 0; i < n; ++i) {
            int len1 = findPalindromLen(s, i, i); 
            if (len1 > maxLen) {
                maxLen = len1;
                maxLenStart = i - len1 / 2;  //aba
            }
            
            int len2 = findPalindromLen(s, i, i + 1);
            if (len2 > maxLen) {
                maxLen = len2;
                maxLenStart = i - len2 / 2 + 1;    //abba
            }
        }
        
        return s.substr(maxLenStart, maxLen);
    }

private:
    int findPalindromLen(string & s, int start, int end) {
        int len = 0;
        while(start >= 0 && end < s.size()) {
            if (s[start] == s[end]) {
                len += (start == end) ? 1 : 2;
                start--;
                end++;
            } else {
                break;
            }
        }
        return len;
    }
};
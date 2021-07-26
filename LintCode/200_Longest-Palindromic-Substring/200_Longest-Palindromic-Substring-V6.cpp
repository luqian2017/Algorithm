class Solution {
public:
    /**
     * @param s: input string
     * @return: a string as the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int n = s.size();
        if (n == 0) return "";
        int g_start = 0, g_len = 0;
        int i = 0, j = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i < j || i + j >= n) break;
                if (s[i - j] == s[i + j]) { 
                    if (2 * j + 1 > g_len) {
                        g_start = i - j;
                        g_len = 2 * j + 1;
                    }
                } else {    
                    break;
                }
            }

            for (j = 0; j < n; ++j) {
                if (i < j || i + j >= n) break;
                if (s[i - j] == s[i + 1 + j]) {
                    if (2 * j + 2 > g_len) {
                        g_start = i - j;
                        g_len = 2 * j + 2;
                    } 
                } else {
                    break;
                }
            }
        }

        return s.substr(g_start, g_len);
    }
};
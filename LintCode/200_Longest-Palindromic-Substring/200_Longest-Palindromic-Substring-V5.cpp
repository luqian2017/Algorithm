class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int len = s.size();
        int new_len = len * 2 - 1;
        string longest_palindrome;
        int longest_len = 0;
        //assume abc=>a#b#c
        for (int i = 0; i < new_len; ++i) {
            int start = i / 2;
            int end = start + i % 2;
            while(start >= 0 && end < new_len && s[start] == s[end]) {
                if (longest_len < (end - start + 1)) {
                    longest_len = end - start + 1;
                    longest_palindrome = s.substr(start, longest_len);
                }
                start--;
                end++;
            }
        }
        return longest_palindrome;
    }
};
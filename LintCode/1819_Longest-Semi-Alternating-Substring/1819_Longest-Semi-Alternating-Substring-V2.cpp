class Solution {
public:
    /**
     * @param s: the string
     * @return: length of longest semi alternating substring
     */
    int longestSemiAlternatingSubstring(string &s) {
        int len = s.size();
        if (len < 3) return 0;
        int substr_len = 1, longest_substr_len = 0;
        int pos = 1, count = 1;
        while(pos < len) {
            if (s[pos] == s[pos - 1]) {
                count++;
            } else {
                count = 1;
            }
            
            if (count < 3) {
                substr_len++;
                longest_substr_len = max(longest_substr_len, substr_len);
            } else {
                substr_len = 2;
            }
            
            pos++;
        }

        return longest_substr_len;
    }
};
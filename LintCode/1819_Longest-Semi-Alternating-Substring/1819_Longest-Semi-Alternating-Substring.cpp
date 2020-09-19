class Solution {
public:
    /**
     * @param s: the string
     * @return: length of longest semi alternating substring
     */
    int longestSemiAlternatingSubstring(string &s) {
        int len = s.size();
        if (len == 0) return 0;
        int substr_len = 0, longest_substr_len = 0;
        vector<int> counts;
        int pos = 0, count = 0;
        while(pos < len) {
            if (s[pos] == 'a') {
                while (pos < len && s[pos] == 'a') {
                    count++;
                    pos++;
                }
                counts.push_back(count);
                count = 0;
            } else {
                while (pos < len && s[pos] == 'b') {
                    count++;
                    pos++;
                }
                counts.push_back(count);
                count = 0;
            }
        }

        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] < 3) {
                substr_len += counts[i];
                longest_substr_len = max(longest_substr_len, substr_len);
            }else {
                substr_len += 2;
                longest_substr_len = max(longest_substr_len, substr_len);
                substr_len = 2;
            }
        }
        return longest_substr_len;
    }
};
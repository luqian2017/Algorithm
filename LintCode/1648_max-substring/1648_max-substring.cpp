class Solution {
public:
    /**
     * @param s: the matrix
     * @return: the last substring of s in lexicographical order
     */
    string maxSubstring(string &s) {
        int len = s.size();
        if (len == 0) return "";
        string result = "";
        char largestChar = 'a';

        for (int i = 0; i < len; ++i) {
            if (largestChar < s[i]) largestChar = s[i];
        }
        
        for (int i = 0; i < len; ++i) {
            if (s[i] == largestChar) {
                result = max(result, s.substr(i));
            }
        }
        
        return result;
    }

};
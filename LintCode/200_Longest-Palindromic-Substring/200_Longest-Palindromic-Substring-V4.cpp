class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int len_s = s.size();
        if (len_s == 0) return "";
        
        //abc -> #a#b#c#
        string new_s;
        for (int i = 0; i < len_s; ++i) {
            new_s += '#';
            new_s += s[i];
        }
        new_s += '#';
        
        int new_len = new_s.size();
        vector<int> palindromes(new_len, 0);
        int mid = 0, longest = 1;
        palindromes[0] = 1;
        
        for (int i = 1; i < new_len; ++i) {
            int len = 1;
            if (mid + longest > i) {
                int mirror_i = mid - (i - mid);
                len = min(palindromes[mirror_i], mid + longest - i);
            }
            
            while(i + len < new_len && i - len >= 0) {
                if (new_s[i - len] != new_s[i + len]) {
                    break;
                }
                len++;
            }
            
            if (len > longest) {
                longest = len;
                mid = i;
            }
            
            palindromes[i] = len;
        }
        
        longest = longest - 1; // remote the extra #
        int start = (mid - 1) / 2 - (longest - 1) / 2;
        return s.substr(start, longest);
    }
};
class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
       for (int i = 0; i < min(s.size(), t.size()); ++i) {
           if (s[i] != t[i]) {
               if (s.size() == t.size()) return s.substr(i + 1) == t.substr(i + 1);
               if (s.size() == t.size() + 1) return s.substr(i + 1) == t.substr(i);
               if (t.size() == s.size() + 1) return t.substr(i + 1) == s.substr(i);
           }
       }
       return abs((int)s.size() - (int)t.size()) == 1;
    }
};